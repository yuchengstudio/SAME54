#目标：
##利用START 产生Master 的DMA模式，调试发送及接收功能

![image](https://github.com/yuchengstudio/SAME54/blob/master/SPI/Master_DMA/picture/master_dma_config.png)

![image](https://github.com/yuchengstudio/SAME54/blob/master/SPI/Master_DMA/picture/master_spi_pin.png)

工程中的led_switcher_main.c函数请用如下代码替代

```
#include "atmel_start.h"
#include <hal_gpio.h>
#include <hal_delay.h>

int main(void)
{
	atmel_start_init();

	gpio_set_pin_pull_mode(SW0, GPIO_PULL_UP);

	while (true) {
		do {
			delay_ms(100);
		} while (gpio_get_pin_level(SW0));

		gpio_toggle_pin_level(LED0);
		
		//add SPI_DMA TX example
		Master_SPI_example();

		do {
			delay_ms(100);
		} while (!gpio_get_pin_level(SW0));
	}
}
```


## DMA发送成功的工程：
https://github.com/yuchengstudio/SAME54/blob/master/SPI/Master_DMA/picture/SPI_DMA_SAME540.zip

后续工作：
分析如何配置DMAC模块，如果要使用DMA通道的话，这一块内容必须配置。




