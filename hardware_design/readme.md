# 1.说明：
     本文将指导基于SAMD5X/E5X芯片的硬件设计。
# 2.参考：请参考SAMD5X/E5X数据手册的 58章节 schematic checklist
https://github.com/yuchengstudio/SAME54/blob/master/SAMD5X:E5X%20datasheet.pdf
<br/>备注：最新的数据手册请在https://www.microchip.com/网站获取

# 3.硬件设计检查的主要内容
硬件设计检查主要设计有“芯片供电设计”，“外部模拟参考源连接”，“编程、调试口设计”，“振荡器、晶体设计”的相关内容。

## 3.1 在噪声环境下的操作
![image](https://github.com/yuchengstudio/SAME54/blob/master/hardware_design/reference/hardware_checklist.png)
```
如果设备在电磁噪声下工作，除了基本的EMC设计指导之外，必须遵循如下硬件设计检查的部分，特别是
1.退耦电容尽可能挨着电源管脚放置。
2.在RESET引脚放置RC滤波电路。
3.SWCLK引脚放置上拉电阻对芯片稳定工作非常重要。（该电阻可在1k ~ 10k之间选择）。
4.消除或减弱噪声也很重要为了避免它到达电源引脚，I / O引脚和晶体。

```

## 3.2 芯片供电设计
![image](https://github.com/yuchengstudio/SAME54/blob/master/hardware_design/reference/hardware_checklist__002.png)
```
SAM D5x / E5x支持1.71V至3.63V的单电源或双电源供电。 必须对VDDIO和VDDANA施加相同的电压。 VDDIOB级别必须低于或等于VDDIO / VDDANA。
当VDDIOB簇中的I / O焊盘复用为模拟焊盘时，VDDANA用于为I / O供电。
如果VDDIOB电压不同于此，则使用此配置可能会导致电气冲突VDDIO / VDDANA。 如果应用程序有这样的要求，则需要为VDDIOB，VDDIO和
VDDANA来自相同的电源，以确保它们始终处于相同的电压。

内部电压调整器有4种不同模式
1.线性模式：这种模式不需要外部的电感，当芯片及外设运行时，该模式为默认模式。
2.开关模式（buck）:该模式我CPU内核及外设运行时，电源最有效的模式。
3.低功耗(LP)模式: 当芯片进入待机（standby）模式运行时，电源运行在该模式。
4.关机（shutdown）模式：当芯片工作在备用电源（backup）模式时,内部电压调整器关闭。

在开关模式和线性模式之间选择可以通过软件即时完成，但电源的设计必须按照对应模式所使用的方式。
```

## 3.3 芯片供电连接方式
模式1 开关电源模式或线性电源模式
![image](https://github.com/yuchengstudio/SAME54/blob/master/hardware_design/reference/hardware_checklist__003.png)

<br/>模式2 线性电源模式
![image](https://github.com/yuchengstudio/SAME54/blob/master/hardware_design/reference/hardware_checklist__004.png)

<br/>模式3 带备份电源的供电模式
![image](https://github.com/yuchengstudio/SAME54/blob/master/hardware_design/reference/hardware_checklist__005.png)

<br/>*备注* 以上硬件供电连接的中的被动器件参数仅仅是个典型的例子，准确的数值需要参考数据手册中的电器参数说明
![image](https://github.com/yuchengstudio/SAME54/blob/master/hardware_design/reference/hardware_checklist__006.png)

## 3.4外部模拟参考连接
说明：如果在实际应用中需要连接外模模拟的参考，需要遵循下面的设计原则，如果使用的是芯片内部的参考，那么这一章节内容可以略过。


## 3.5外部复位电路
![image](https://github.com/yuchengstudio/SAME54/blob/master/hardware_design/reference/hardware_checklist__007.png)


