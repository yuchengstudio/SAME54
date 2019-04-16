
这里所说的ARM系统基本文件格式，都是在基于ARM的嵌入式系统开发中常会碰到的文件格式。
    ARM系统基本文件格式有三种：
1) BIN，平板式二进制格式，一般用于直接烧写到Flash中，也可以用于加载到monitor程序中。
2) ELF，EXECUTABLE AND LINKABLE FORMAT，一种通用的OBJECT文件格式，一般由GNU COMPILER COLLECTION (GCC)产生。
3) AXF，BIN格式的扩展版,主体部分同BIN，在文件头和尾加入了调试用的信息，用于AXD。
