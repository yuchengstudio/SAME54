# 1.错误说明：
当使用studio中的tools中device programming做程序烧写的时候，如果出现如下图所示的错误，那么用本文提到的方法就能有效解决
(备注：这是SAMD51_DFP pack包1.1.96版本的一个小bug)
![images](https://github.com/yuchengstudio/SAME54/blob/master/tools_issues/reference/program_001.jpg)


# 2.bug修改方法
按照图示方框中找到“ATSAMD51J18A.atdf”文件
备注：如果是其他器件的型号，比如是ATSAMD51J20A，那只要打开相应的pack文件，并做相同的修改就行。
![images](https://github.com/yuchengstudio/SAME54/blob/master/tools_issues/reference/program_002.jpg)


# 3.
请在如图位置添加红色方框中的代码字段
![images](https://github.com/yuchengstudio/SAME54/blob/master/tools_issues/reference/program_003.jpg)
备注：我用的是topyra这款软件打开pack包文件的，用记事本打开不方便阅读。
```
<memory-segment name="AUX0" start="0x00804000" size="0x200" type="user_page" pagesize="16" rw="RW"/>
```
# 4.重启studio
重复1的程序烧录过程，问题解决，☺。

