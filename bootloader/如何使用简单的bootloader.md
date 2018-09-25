* [1. 简介](#1-简介)
* [2. bootloader工程](#2-bootloader工程)  
  * [2.1 二级目录语法](#21-二级目录语法)
* [3. 在windows命令行中调用python下载应用程序](#3-在windows命令行中调用python下载应用程序)  


# 1. 简介
<br/>本文主要介绍如何编写最简单的bootloader应用。
<br/>开发板：SAME54 Xplained.
    
# 2. bootloader工程
<br/>请使用Atmel studio7打开如下链接的工程：
<br/>https://github.com/yuchengstudio/SAME54/blob/master/bootloader/reference_file/asf4_e54_uart_bootloader-simple-proto.7z
<br/>编译，下载bootloader代码到MCU里（SAME54 Xplained开发板使用EDBG口下载程序。）

## 2.1. bootloader工程分析（可以先跳过这一节内容直接查看第3节应用）
    请参照一级目录语法
    

# 3. 在windows命令行中调用python下载应用程序
<br/>准备工作：将“asf4_e54_rtos_led_blink_fast.bin”，“asf4_e54_rtos_led_blink_slowly.bin”，“dlimage.py”，“dlimage_a.py”这4个文件copy在系统默认用户名的文件夹下,如图3.1， 图3.2所示
<br/>https://github.com/yuchengstudio/SAME54/blob/master/bootloader/reference_file/asf4_e54_rtos_led_blink_fast.bin
<br/>https://github.com/yuchengstudio/SAME54/blob/master/bootloader/reference_file/asf4_e54_rtos_led_blink_slowly.bin
<br/>https://github.com/yuchengstudio/SAME54/blob/master/bootloader/reference_file/dlimage.py
<br/>https://github.com/yuchengstudio/SAME54/blob/master/bootloader/reference_file/dlimage_a.py

![image](https://github.com/yuchengstudio/SAME54/blob/master/bootloader/reference_file/bootloader_application%20%20002.png)
图3.1
![image](https://github.com/yuchengstudio/SAME54/blob/master/bootloader/reference_file/bootloader_application%20%20003.png)
图3.2

<br/>python 在2.xx 版本与 3.xx版本中会有一些差异，在本应用中主要涉及print函数。
<br/>请在windos 命令行下敲入“python --version”查当前windows系统使用的python的版本，如图3.3所示
![image](https://github.com/yuchengstudio/SAME54/blob/master/bootloader/reference_file/bootloader_application%20%20001.png)
图3.3

<br/>在本系统中，windos系统默认调用的是python 3.6.4, 这个时候我们就需要使用“dlimage_a.py”这个函数。
“https://github.com/yuchengstudio/SAME54/blob/master/bootloader/reference_file/dlimage_a.py”

<br/>在window的系统命令行窗口输入“python dlimage_a.py -p 'YOUR COM PORT' -f asf4_e54_rtos_led_blink_fast.bin”命令
<br/>note:
<br/>1.确保bootloader工程已经下载到MCU里面。
<br/>2.在启用python通过串口写程序之前，请复位当前的工程。
<br/>3.请根据实际与开发板连接的串口替代'YOUR COM PORT', 比如我们开发板通过EDBG与电脑链接，虚拟的串口是COM4,那么命令就改成实际的命令如下：
``` python dlimage_a.py -p COM4 -f asf4_e54_rtos_led_blink_fast.bin” ```







