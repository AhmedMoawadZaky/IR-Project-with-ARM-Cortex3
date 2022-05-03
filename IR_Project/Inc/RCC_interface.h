/*****************************************************************/
/****************** Name    : Ahmed Zaky *************************/
/****************** Date    : 4/2/2021   *************************/
/****************** Version : 1.0V       *************************/
/****************** SWC     : RCC        *************************/
/*****************************************************************/

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_


#define    AHB_BUS       								0
#define    APB1_BUS      								1
#define    APB2_BUS      								2


#define ENABLE_PERIPHERAL     							1
#define DISABLE_PERIPHERAL    							0
#define RESET_PERIPHERAL      							2
/*
ClockTypes :                         
   1-HSI                                     
   2-HSE                                     
   3-PLL                                     
	   3.1-PLL_HSI_DIVIDED_BY_2              
	   3.2-PLL_HSE                           
	   3.3-PLL_HSE_DIVIDED_BY_2              
   4-HSE_BYPASS    

*/					   
#define HSI                         					1
#define HSE                         					2
#define PLL                         					3
#define PLL_HSI_DIVIDED_BY_2        					4
#define PLL_HSE                     					5
#define PLL_HSE_DIVIDED_BY_2        					6
#define HSE_BYPASS                  					7

/*
ClockFactor For PLL:   
	01-PLL_CLOCKk_MULTIPLE_BY_2    
	02-PLL_CLOCKk_MULTIPLE_BY_3    
	03-PLL_CLOCKk_MULTIPLE_BY_4    
	04-PLL_CLOCKk_MULTIPLE_BY_5    
	05-PLL_CLOCKk_MULTIPLE_BY_6    
	06-PLL_CLOCKk_MULTIPLE_BY_7    
	07-PLL_CLOCKk_MULTIPLE_BY_8    
	08-PLL_CLOCKk_MULTIPLE_BY_9    
	09-PLL_CLOCKk_MULTIPLE_BY_10   
	10-PLL_CLOCKk_MULTIPLE_BY_11  
	11-PLL_CLOCKk_MULTIPLE_BY_12  
	12-PLL_CLOCKk_MULTIPLE_BY_13  
	13-PLL_CLOCKk_MULTIPLE_BY_14  
	14-PLL_CLOCKk_MULTIPLE_BY_15  
	15-PLL_CLOCKk_MULTIPLE_BY_16  
*/

#define PLL_CLOCK_MULTIPLE_BY_2                        	0b0000
#define PLL_CLOCK_MULTIPLE_BY_3					       	0b0001
#define PLL_CLOCK_MULTIPLE_BY_4                        	0b0010
#define PLL_CLOCK_MULTIPLE_BY_5                        	0b0011
#define PLL_CLOCK_MULTIPLE_BY_6                        	0b0100
#define PLL_CLOCK_MULTIPLE_BY_7                        	0b0101
#define PLL_CLOCK_MULTIPLE_BY_8                        	0b0110
#define PLL_CLOCK_MULTIPLE_BY_9                        	0b0111
#define PLL_CLOCK_MULTIPLE_BY_10                       	0b1000
#define PLL_CLOCK_MULTIPLE_BY_11                       	0b1001
#define PLL_CLOCK_MULTIPLE_BY_12                       	0b1010
#define PLL_CLOCK_MULTIPLE_BY_13                       	0b1011
#define PLL_CLOCK_MULTIPLE_BY_14                       	0b1100
#define PLL_CLOCK_MULTIPLE_BY_15                       	0b1101
#define PLL_CLOCK_MULTIPLE_BY_16_1                      0b1110
#define PLL_CLOCK_MULTIPLE_BY_16_2                      0b1111
            
/*
	Clock Security System 
	1-Enable:                                         
		-To Set HSI By H.W When There are Failure In HSE 
	2-Disable
*/

#define DISABLE_CLOCK_SECURITY_SYSTEM              		0
#define ENABLE_CLOCK_SECURITY_SYSTEM               		1

/*
	Peripheral Clock Enable For AHB Bus 
*/


#define    DMA1_RCC         							0
#define    DMA2_RCC         							1
#define    SRAM_RCC         							2
#define    FLITF_RCC        							4
#define    CRC_RCC          							6
#define    FSMC_RCC         							8
#define    SDIO_RCC         							10


/*
	Peripheral Clock Enable For APB1 Bus
*/



#define    TIM2_RCC         							0
#define    TIM3_RCC         							1
#define    TIM4_RCC         							2
#define    TIM5_RCC         							3
#define    TIM6_RCC         							4
#define    TIM7_RCC         							5
#define    TIM12_RCC        							6
#define    TIM13_RCC        							7
#define    TIM14_RCC        							8
#define    WWDG_RCC         							11
#define    SPI2_RCC         							14
#define    SPI3_RCC         							15
#define    USART2_RCC       							17
#define    USART3_RCC       							18
#define    UART4_RCC        							19
#define    UART5_RCC        							20
#define    I2C1_RCC         							21
#define    I2C2_RCC         							22
#define    USB_RCC          							23
#define    CAN_RCC          							25
#define    BKP_RCC          							27
#define    PWR_RCC          							28
#define    DAC_RCC          							29


/*
	Peripheral Clock Enable For APB2 Bus 
*/

#define    AFIO_RCC         							0
#define    GPIOA_RCC        							2
#define    GPIOB_RCC        							3
#define    GPIOC_RCC        							4
#define    GPIOD_RCC        							5
#define    GPIOE_RCC        							6
#define    GPIOF_RCC        							7
#define    GPIOG_RCC        							8
#define    ADC1_RCC         							9
#define    ADC2_RCC         							10
#define    TIM1_RCC         							11
#define    SPI1_RCC         							12
#define    TIM8_RCC         							13
#define    USART1_RCC       							14
#define    ADC3_RCC         							15
#define    TIM9_RCC         							19
#define    TIM10_RCC        							20
#define    TIM11_RCC        							21


void RCC_VidInit( void );

void RCC_VidEnablePeripheralClock ( u8 Copy_u8PeripheralBus , u8 Copy_u8Peripheral );
void RCC_VidDisablePeripheralClock( u8 Copy_u8PeripheralBus , u8 Copy_u8Peripheral );


#endif
