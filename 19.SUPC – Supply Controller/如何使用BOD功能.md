# 1.如何使用BOD12
![image](https://github.com/yuchengstudio/SAME54/blob/master/19.SUPC%20%E2%80%93%20Supply%20Controller/reference/BOD_001.jpg)

## 1.1BOD12的关闭与启用
### 1.1.1 找到BOD12寄存器相应的使能位：
<br/>![image](https://github.com/yuchengstudio/SAME54/blob/master/19.SUPC%20%E2%80%93%20Supply%20Controller/reference/BOD_002.jpg)
### 1.1.2 找到BOD12寄存器在工程中的定义位置
<br/>![image](https://github.com/yuchengstudio/SAME54/blob/master/19.SUPC%20%E2%80%93%20Supply%20Controller/reference/BOD_003.jpg)
<br/>备注：same54p20a.h文件在工程的“Dependencies”文件夹下面，而且该文件夹里面的内容只有在工程编译完成后才会出现。

### 1.1.3 使用代码操作BOD12寄存器
<br/>SUPC寄存器枚举类型的定义
<br/>![image](https://github.com/yuchengstudio/SAME54/blob/master/19.SUPC%20%E2%80%93%20Supply%20Controller/reference/BOD_004.jpg)

<br/>SUPC BOD12_ENABLE API函数的
<br/>![image](https://github.com/yuchengstudio/SAME54/blob/master/19.SUPC%20%E2%80%93%20Supply%20Controller/reference/BOD_005.jpg)
<br/>提示：如何快速找到你想要的API函数
<br/>1.找到对应hri的函数库，对应的找到要访问的数据结构，比如这里的“Supc”。
<br/>![image](https://github.com/yuchengstudio/SAME54/blob/master/19.SUPC%20%E2%80%93%20Supply%20Controller/reference/BOD_008.jpg)

<br/>2.通过数据结构的定义查看数据结构里到底有哪些寄存器可以访问，找到我们的目标寄存器，比如这里的“BOD12”
<br/>![image](https://github.com/yuchengstudio/SAME54/blob/master/19.SUPC%20%E2%80%93%20Supply%20Controller/reference/BOD_009.jpg)

<br/>3.继续查看“BOD12”枚举变量里的数据枚举，找到我们需要访问的寄存器位，比如这里的ENABLE位，对应找到相应的宏定义：SUPC_BOD12_ENABLE
<br/>![image](https://github.com/yuchengstudio/SAME54/blob/master/19.SUPC%20%E2%80%93%20Supply%20Controller/reference/BOD_010.jpg)

<br/>4.使用SUPC_BOD12_ENABLE这个宏定义在相应的软件库里找对应的操作函数，就能比较快找到你想要的操作函数了,☺
<br/>![image](https://github.com/yuchengstudio/SAME54/blob/master/19.SUPC%20%E2%80%93%20Supply%20Controller/reference/BOD_011.jpg)



<br/>BOD12_ENABLE寄存器的操作，与操作结果演示
<br/>![image](https://github.com/yuchengstudio/SAME54/blob/master/19.SUPC%20%E2%80%93%20Supply%20Controller/reference/BOD_006.jpg)
<br/>![image](https://github.com/yuchengstudio/SAME54/blob/master/19.SUPC%20%E2%80%93%20Supply%20Controller/reference/BOD_007.jpg)
