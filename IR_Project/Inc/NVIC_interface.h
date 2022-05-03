/*****************************************************************/
/****************** Name    : Ahmed Zaky *************************/
/****************** Date    : 11/2/2021  *************************/
/****************** Version : 1.0V       *************************/
/****************** SWC     : NVIC       *************************/
/*****************************************************************/

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

enum IQR{

	WWDG,
	PVD,
	TAMPER,
	RTC,
	FLASH,
	RCC,
	EXTI0,
	EXTI1,
	EXTI2,
	EXTI3,
	EXTI4,
	DMA1_Channel1,
	DMA1_Channel2,
	DMA1_Channel3,
	DMA1_Channel4,
	DMA1_Channel5,
	DMA1_Channel6,
	DMA1_Channel7,
	ADC1_2,
	USB_HP_CAN_TX,
	USB_LP_CAN_RX0,
	CAN_RX1,
	CAN_SCE,
	EXTI9_5,
	TIM1_BRK_TIM9,
	TIM1_UP_TIM10,
	TIM1_TRG_COM_TIM11,
	TIM1_CC,
	TIM2,
	TIM3,
	TIM4,
	I2C1_EV,
	I2C1_ER,
	I2C2_EV,
	I2C2_ER,
	SPI1,
	SPI2,
	USART1,
	USART2,
	USART3,
	EXTI15_10,
	RTCAlarm,
	USBWakeUp,
	TIM8_BRK_TIM12,
	TIM8_UP_TIM13,
	TIM8_TRG_COM_TIM14,
	TIM8_CC,
	ADC3,
	FSMC,
	SDIO,
	TIM5,
	SPI3,
	UART4,
	UART5,
	TIM6,
	TIM7,
	DMA2_Channel1,
	DMA2_Channel2,
	DMA2_Channel3,
	DMA2_Channel4_5,

};

u8 MNVIC_u8EnablePeripheral  	( u8 Copy_u8INTID );
u8 MNVIC_u8DisablePeripheral 	( u8 Copy_u8INTID );

u8 MNVIC_u8SetPendingFlag       ( u8 Copy_u8INTID );
u8 MNVIC_u8ClearPendingFlag   	( u8 Copy_u8INTID );

u8 MNVIC_u8GetActiveFlag		(u8 Copy_u8INTID , u8 * Copy_Pu8ActiveVal);

u8 MNVIC_u8SetPriority       	( u8 Copy_u8INTID , u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority );


#endif
