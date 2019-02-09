# 1.参考文献
视频：https://www.youtube.com/watch?v=M3AGfdhPOIg
<br/>本实验源代码：https://github.com/yuchengstudio/SAME54/blob/master/ADC/reference/ADC_example.7z

# 2.用用笔记
https://github.com/yuchengstudio/SAME54/blob/master/AD/reference/Atmel-42645-ADC-Configurations-with-Examples_ApplicationNote_AT11481.pdf

# 3.Salesforce参考号：00348307
https://microchip.my.salesforce.com/5001N00000fFH2w?srPos=0&srKp=500

# 4.开发板链接
https://github.com/yuchengstudio/SAME54/blob/master/SAM%20E54%20Xplained%20Pro%20User's%20Guide.pdf

# 5.使用START产生第一个ADC应用
## 5.1 在这个实验中，我们将使用外部扩展板IO1Xplained pro, 利用SAME54 xplained的ADC测量IO1Xplained pro的light sensor模拟量
![image](https://github.com/yuchengstudio/SAME54/blob/master/ADC/reference/ADC_example.jpg)

## 5.2 在SAM E54 Xplained Pro User's Guide文档中找到对应PB00对应的ADC通道
![image](https://github.com/yuchengstudio/SAME54/blob/master/ADC/reference/ADC_example_002.png)

## 5.3 在START中添加ADC driver,根据实际硬件的链接（PB00作为ADC输入）配置ADC
![image](https://github.com/yuchengstudio/SAME54/blob/master/ADC/reference/ADC_expend_006.png)

## 5.4 将start生成的代码（ADC例子）移植到main函数中
![image](https://github.com/yuchengstudio/SAME54/blob/master/ADC/reference/ADC_expend_005.png)

## 5.5 查看ADC数据结果
![image](https://github.com/yuchengstudio/SAME54/blob/master/ADC/reference/ADC_example_006.png)


# 6.多路ADC数据采样
【说明】1.START ADC driver不支持ADC多通道采样的配置，如果实际应用中需要配置ADC多通道采样，需要在START生成的代码框架之上进行必要的通道修改。
<br/>【实验目标】在5.的实验基础之上，添加一路ADC采样通道，比如将PB04作为增加的一路ADC输入。
![image](https://github.com/yuchengstudio/SAME54/blob/master/ADC/reference/ADC_example_007.png)

## 6.1 在5.实验基础上添加修改ADC采样通道的代码

![image](https://github.com/yuchengstudio/SAME54/blob/master/ADC/reference/ADC_example_008.png)
