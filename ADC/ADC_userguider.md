# 1.参考文献
视频：https://www.youtube.com/watch?v=M3AGfdhPOIg

# 2.用用笔记
https://github.com/yuchengstudio/SAME54/blob/master/AD/reference/Atmel-42645-ADC-Configurations-with-Examples_ApplicationNote_AT11481.pdf

# 3.Salesforce参考号：00348307
https://microchip.my.salesforce.com/5001N00000fFH2w?srPos=0&srKp=500

# 5.开发板链接
https://github.com/yuchengstudio/SAME54/blob/master/SAM%20E54%20Xplained%20Pro%20User's%20Guide.pdf

# 4.使用START产生第一个ADC应用
## 4.1 在这个实验中，我们将使用外部扩展板IO1Xplained pro, 利用SAME54 xplained的ADC测量IO1Xplained pro的light sensor模拟量
![image](https://github.com/yuchengstudio/SAME54/blob/master/ADC/reference/ADC_example.jpg)

## 4.2 在SAM E54 Xplained Pro User's Guide文档中找到对应PB00对应的ADC通道
![image](https://github.com/yuchengstudio/SAME54/blob/master/ADC/reference/ADC_example_002.png)

## 4.3 在START中添加ADC driver,根据实际硬件的链接（PB00作为ADC输入）配置ADC
![image](https://github.com/yuchengstudio/SAME54/blob/master/ADC/reference/ADC_example_003.png)

## 4.4 将start生成的代码（ADC例子）移植到main函数中


