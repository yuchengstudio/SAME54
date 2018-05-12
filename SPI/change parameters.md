how to change the parameter of SPI module
```
All functions available HAL layer can be used from application firmware. To change the baud rate, you can use the below function in hal_spi_m_async.c

/** \brief Set SPI baudrate
*
* Works if the SPI is initialized as master.
* In the function a sanity check is used to confirm it's called in the correct mode.
*
* \param[in] spi Pointer to the HAL SPI instance.
* \param[in] baud_val The target baudrate value
* (see "baudrate calculation" for calculating the value).
*
* \return Operation status.
* \retval ERR_NONE Success.
* \retval ERR_BUSY Busy.
*/

int32_t spi_m_async_set_baudrate(struct spi_m_async_descriptor *spi, const uint32_t baud_val)
```


