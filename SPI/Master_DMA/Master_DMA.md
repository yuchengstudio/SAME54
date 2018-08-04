#目标：
##利用START 产生Master 的DMA模式，调试发送及接收功能


## DMA发送成功的工程：
https://github.com/yuchengstudio/SAME54/blob/master/SPI/Master_DMA/picture/SPI_DMA_SAME540.zip

## DMAC模块配置
![images](https://github.com/yuchengstudio/SAME54/blob/master/SPI/Master_DMA/picture/DMA_configuration_001.png)


## 在SPI_DMA_SAME540工程基础上添加更改波特率的功能
```
void SPI_0_example(void)
{
	struct io_descriptor *io;
	spi_m_dma_get_io_descriptor(&SPI_0, &io);

	spi_m_dma_register_callback(&SPI_0, SPI_M_DMA_CB_TX_DONE, tx_complete_cb_SPI_0);
	spi_m_dma_enable(&SPI_0);
	io_write(io, example_SPI_0, 12);
	
	delay_ms(100);

	//change the SPI baudrate
	spi_m_dma_disable(&SPI_0);
	test = spi_m_dma_set_baudrate(&SPI_0, 10000);
	spi_m_dma_enable(&SPI_0);
   	
	io_write(io, example_SPI_0, 12);
}

```
注意：<br/>1.在更改波特率之前需要关闭。
      <br/>2.更改波特率的第二个参数计算方式
      The argument 'baud_val' in function 'spi_m_dma_set_baudrate' represents the 'BAUD' register value which needs to be set.
To calculate the 'BAUD' register value, please refer to the 'Synchronous Operating Mode' section of 'Table 33-2. Baud Rate Equations' in the SAME5x/D5x datasheet.
	From that we can understand, BAUD = (fref/(2*fbaud))-1. Here 'fbaud' represents the 'baudtate' to be set.
	In your case, BAUD = (12000000/(2*50000)) - 1
	Please vary the 'fbaud' to calculate the 'BAUD' register value.




