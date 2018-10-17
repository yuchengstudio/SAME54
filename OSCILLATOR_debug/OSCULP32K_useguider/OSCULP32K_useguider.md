
参考文献：
https://microchip.secure.force.com/microchipknowledge/articles/en_US/FAQ/SAM-D5x-E5x--Atmel-START-DPLL-configuration/?q=SAM-D5x-E5x--Atmel-START-DPLL-configuration&l=en_US&fs=RelatedArticle

源代码参考：
https://github.com/yuchengstudio/SAME54/blob/master/OSCILLATOR_debug/OSCULP32K_useguider/picutures/SAME54_OSC32K_PLL.rar



配置注意事项
![image](https://github.com/yuchengstudio/SAME54/blob/master/OSCILLATOR_debug/OSCULP32K_useguider/picutures/OSC_configue_003.jpg)
![image](https://github.com/yuchengstudio/SAME54/blob/master/OSCILLATOR_debug/OSCULP32K_useguider/picutures/OSC_configue_004.jpg)

When using a low frequency input clock on FDPLLn, several FDPLL unlocks may occur while the output frequency is stable. As a workaround enable the lock bypass feature.
Refer the image below for Atmel START configuration.
![image](https://github.com/yuchengstudio/SAME54/blob/master/OSCILLATOR_debug/OSCULP32K_useguider/picutures/OSC_configue_005.jpg)
