

asm volatile("" ::: "memory");

creates a compiler level memory barrier forcing optimizer to not re-order memory accesses across the barrier.

For example, if you need to access some address in a specific order (probably because that memory area is actually backed by a different device rather than a memory) you need to be able tell this to the compiler otherwise it may just optimize your steps for the sake of efficiency.

Assume in this scenario you must increment a value in address, read something and increment another value in an adjacent address.

int c(int *d, int *e) {
        int r;
        d[0] += 1;
        r = e[0];
        d[1] += 1;
        return r;
}

Problem is compiler (gcc in this case) can rearrange your memory access to get better performance if you ask for it (-O). Probably leading to a sequence of instructions like below:

00000000 <c>:
   0:   4603        mov r3, r0
   2:   c805        ldmia   r0, {r0, r2}
   4:   3001        adds    r0, #1
   6:   3201        adds    r2, #1
   8:   6018        str r0, [r3, #0]
   a:   6808        ldr r0, [r1, #0]
   c:   605a        str r2, [r3, #4]
   e:   4770        bx  lr

Above values for d[0] and d[1] are loaded at the same time. Lets assume this is something you want to avoid then you need to tell compiler not to reorder memory accesses and that is to use asm volatile("" ::: "memory").

int c(int *d, int *e) {
        int r;
        d[0] += 1;
        r = e[0];
        asm volatile("" ::: "memory");
        d[1] += 1;
        return r;
}

So you'll get your instruction sequence as you want it to be:

00000000 <c>:
   0:   6802        ldr r2, [r0, #0]
   2:   4603        mov r3, r0
   4:   3201        adds    r2, #1
   6:   6002        str r2, [r0, #0]
   8:   6808        ldr r0, [r1, #0]
   a:   685a        ldr r2, [r3, #4]
   c:   3201        adds    r2, #1
   e:   605a        str r2, [r3, #4]
  10:   4770        bx  lr
  12:   bf00        nop

It should be noted that this is only compile time memory barrier to avoid compiler to reorder memory accesses, as it puts no extra hardware level instructions to flush memories or wait for load or stores to be completed. CPUs can still reorder memory accesses if they have the architectural capabilities and memory addresses are on normal type instead of strongly ordered or device (ref).
