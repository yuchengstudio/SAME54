目标说明：
Master 与 slaver通信实验
```
硬件平台：Atmel SAME54Xplained PRO
硬件连接：
Master    <--> Slave
PB26(SCK) <--> PC05(SCK)

PB27(MOSI) ---> PC07(MOSI)

PB29(MISO) <--- PC04(MISO)

PB28       ---> PC06(_SS)

```
```
工程1：LED switcher_print_SPI.atzip 
描述：master SPI采用 syn模式， slave SPI采用asyn模式，收发成功
1.main主程序请用如下代码替换：
2.操作说明：每按一次SW0按键，LEO0翻转一次，在串口输出 hello world字符，同时执行一次Master SPI写操作，Slaver SPI读操作。
可以在debug环境下查看slaver spi的读缓存器 example_Master_SPI_slaver[] 与 Master SPI 发送缓存example_Master_SPI[]是否一致。

```
https://github.com/yuchengstudio/SAME54/blob/master/SPI/Master_Slave_transmition/LED%20switcher_print_SPI.atzip

```
#include "atmel_start.h"
#include <hal_gpio.h>
#include <hal_delay.h>
/**
 * Example of using Master_SPI to write "Hello World" using the IO abstraction.
 */
static uint8_t example_Master_SPI[12] = "Hello World!";
static uint8_t example_Master_SPI_slaver[12];

//define callback for slaver SPI TX
static void complete_cb_Slaver_SPI_TX(const struct spi_s_async_descriptor *const desc)
{
	/* Transfer completed */
}

//define callback for slaver SPI RX
static void complete_cb_Slaver_SPI_RX(const struct spi_s_async_descriptor *const desc)
{
	/* Receiver completed */
}
int main(void)
{
	atmel_start_init();

	gpio_set_pin_pull_mode(SW0, GPIO_PULL_UP);
	
	//Master SPI initialization
	struct io_descriptor *io_spi_master;
	spi_m_sync_get_io_descriptor(&Master_SPI, &io_spi_master);
	spi_m_sync_enable(&Master_SPI);
	//io_write(io, example_Master_SPI, 12);
	
	//Slaver SPI initialization
	struct io_descriptor *io_spi_slaver;
	spi_s_async_get_io_descriptor(&Slaver_SPI, &io_spi_slaver);

	spi_s_async_register_callback(&Slaver_SPI, SPI_S_CB_TX, (FUNC_PTR)complete_cb_Slaver_SPI_TX);
	spi_s_async_register_callback(&Slaver_SPI, SPI_S_CB_RX, (FUNC_PTR)complete_cb_Slaver_SPI_RX);
	
	spi_s_async_enable(&Slaver_SPI);

	while (true) {
		do {
			delay_ms(100);
		} while (gpio_get_pin_level(SW0));

		gpio_toggle_pin_level(LED0);
		printf("hello world\n\r");
		gpio_set_pin_level(Master_SPI_SS,false);
		io_write(io_spi_master, example_Master_SPI, 12);
		gpio_set_pin_level(Master_SPI_SS,true);
		
		io_read(io_spi_slaver, example_Master_SPI_slaver, 12);
		
		do {
			delay_ms(100);
		} while (!gpio_get_pin_level(SW0));
	}
}

```
```
工程2：LED switcher_print_SPI3.atzip 
描述：master SPI采用 syn模式， slave SPI采用asyn模式，提高内核时钟到120M,同时SPI时钟调整到12M, 
1.main主程序请用如下代码替换：
2.操作说明：
master SPI发送，slaver SPI接收：每按一次SW0按键，LEO0翻转一次，在串口输出 hello world字符，同时执行一次Slaver SPI写操作，Master SPI读操作。
可以在debug环境下查看Master spi的读缓存器 example_Master_SPI[] 与 Slaver SPI example_Master_SPI_slaver[]是否一致。

```
https://github.com/yuchengstudio/SAME54/blob/master/SPI/Master_Slave_transmition/LEDswitcher_print_SP_12M_SCK.zip

```
注意事项：请开启advanced configuration, 并选择clock phase 为：sample input on trailing edge, 否则接收数据会发送错位现象。
```
![images](https://github.com/yuchengstudio/SAME54/blob/master/SPI/Master_Slave_transmition/pictures/SPI_commnication_001.jpg)




```
工程3：LED switcher_0511_master_asyn_verify.atzip
描述：master SPI采用 asyn模式，slave SPI采用asyn模式，SPImaster发送有数据，但slave接收不到数据，中断也没有进。
main主程序请用如下代码替换：
```
```
#include "atmel_start.h"
#include <hal_gpio.h>
#include <hal_delay.h>

uint8_t break_identify;
//master callback
static void complete_cb_Master_SPI(const struct spi_m_async_descriptor *const io_descr)
{
	/* Transfer completed */
	break_identify = 0x02;
}

/**
 * Example of using Master_SPI to write "Hello World" using the IO abstraction.
 */
static uint8_t example_Master_SPI[12] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c};
static uint8_t example_Master_SPI_slaver[12];

//define callback for slaver SPI TX
static void complete_cb_Slaver_SPI_TX(const struct spi_s_async_descriptor *const desc)
{
	/* Transfer completed */
}

//define callback for slaver SPI RX
static void complete_cb_Slaver_SPI_RX(const struct spi_s_async_descriptor *const desc)
{
	/* Receiver completed */
	break_identify = 0x01;
}
int main(void)
{
	atmel_start_init();

	gpio_set_pin_pull_mode(SW0, GPIO_PULL_UP);
	
	//Master SPI initialization
	struct io_descriptor *io_spi_master;
	spi_m_async_get_io_descriptor(&Master_SPI, &io_spi_master);
	spi_m_async_register_callback(&Master_SPI, SPI_M_ASYNC_CB_XFER, (FUNC_PTR)complete_cb_Master_SPI);
	spi_m_async_enable(&Master_SPI);
	//io_write(io, example_Master_SPI, 12);
	
	//Slaver SPI initialization
	struct io_descriptor *io_spi_slaver;
	spi_s_async_get_io_descriptor(&Slaver_SPI, &io_spi_slaver);

	spi_s_async_register_callback(&Slaver_SPI, SPI_S_CB_TX, (FUNC_PTR)complete_cb_Slaver_SPI_TX);
	spi_s_async_register_callback(&Slaver_SPI, SPI_S_CB_RX, (FUNC_PTR)complete_cb_Slaver_SPI_RX);
	
	spi_s_async_enable(&Slaver_SPI);

	while (true) {
		do {
			delay_ms(100);
		} while (gpio_get_pin_level(SW0));

		gpio_toggle_pin_level(LED0);
		printf("hello world\n\r");
		gpio_set_pin_level(Master_SPI_SS,false);
		io_write(io_spi_master, example_Master_SPI, 12);
		gpio_set_pin_level(Master_SPI_SS,true);
		
		io_read(io_spi_slaver, example_Master_SPI_slaver, 12);
		
		do {
			delay_ms(100);
		} while (!gpio_get_pin_level(SW0));
	}
}
```
