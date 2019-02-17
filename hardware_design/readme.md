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

