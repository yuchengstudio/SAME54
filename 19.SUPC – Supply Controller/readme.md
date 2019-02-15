# 1.如何使用BOD12
![image](https://github.com/yuchengstudio/SAME54/blob/master/19.SUPC%20%E2%80%93%20Supply%20Controller/reference/BOD_001.jpg)

## 1.1BOD12的关闭与启用
找到BOD12寄存器相应的使能位：
<br/>![image](https://github.com/yuchengstudio/SAME54/blob/master/19.SUPC%20%E2%80%93%20Supply%20Controller/reference/BOD_002.jpg)
<br/>在代码中如何访问BOD12寄存器
<br/>![image](https://github.com/yuchengstudio/SAME54/blob/master/19.SUPC%20%E2%80%93%20Supply%20Controller/reference/BOD_003.jpg)
<br/>备注：same54p20a.h文件在工程的“Dependencies”文件夹下面，而且该文件夹里面的内容只有在工程编译完成后才会出现。
