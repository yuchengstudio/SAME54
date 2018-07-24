# 目录
## 概述
## 参考文献
 | 参考文献名字 | 链接 | 说明 |
 | --- | ----- | ----- | 
 | 1 | https://github.com/yuchengstudio/SAME54/blob/master/TCM/TCM_Linker.zip | 00306579 | 
 | tips | 
 ```
 1.Currently there is no option to enable Cache in Atmel START GUI. 
 You need to do through direct register access.CMCC (Cortex M Cache Controller) can be enabled by setting CEN bit in CMCC.CTRL register.
 Code snippet:

 void cmcc_enable(void)
 {
   CMCC->CTRL.reg = CMCC_CTRL_CEN;
   while (CMCC->SR.reg != CMCC_SR_CSTS);
 }

 void cmcc_disable(void)
 {
   CMCC->CTRL.reg = 0;
   while (CMCC->SR.bit.CSTS != 0);
}
```
