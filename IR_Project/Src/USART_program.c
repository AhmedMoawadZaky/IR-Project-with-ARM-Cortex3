
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"

void (*MUSART2_CallBack)(u8 Resive);

void MUSART1_voidInit(void)
{
	/*	baud rate = 9600		*/
	USART1 -> BRR = 0x341;

	USART1 -> SR = 0;						/* Clearing status register */

	CLR_BIT((USART1-> CR[0]), 5);
	CLR_BIT((USART1-> CR[0]), 6);
	CLR_BIT((USART1-> CR[0]), 7);
	CLR_BIT((USART1-> CR[0]), 10);

	CLR_BIT((USART1-> CR[1]), 12);
	CLR_BIT((USART1-> CR[1]), 13);

	SET_BIT((USART1-> CR[0]), 3);			/* Enabling Transmitter */
	SET_BIT((USART1-> CR[0]), 2);			/* Enabling Receiver */
	SET_BIT((USART1-> CR[0]), 13);			/* Enabling USART */

}

void MUSART1_voidTransmit(u8 data)
{

	USART1 -> DR = data;
	while((GET_BIT((USART1 -> SR), 6)) == 0);

	CLR_BIT(USART1 -> SR , 6);

}

u8 MUSART1_u8Receive(void)
{
	u8 Loc_u8ReceivedData = 0;
	while((GET_BIT((USART1 -> SR), 5)) == 0);
	Loc_u8ReceivedData = USART1 -> DR;
	return (Loc_u8ReceivedData);
}



void MUSART2_voidInit(void)
{
/*	baud rate = 9600		*/
	USART2 -> BRR = 0x341;

	USART2 -> SR = 0;						/* Clearing status register */

	SET_BIT((USART2-> CR[0]), 5); /* Enable RX Interrupt*/
	CLR_BIT((USART2-> CR[0]), 6);
	CLR_BIT((USART2-> CR[0]), 7);
	CLR_BIT((USART2-> CR[0]), 10);

	CLR_BIT((USART2-> CR[1]), 12);
	CLR_BIT((USART2-> CR[1]), 13);

	SET_BIT((USART2-> CR[0]), 3);			/* Enabling Transmitter */
	SET_BIT((USART2-> CR[0]), 2);			/* Enabling Receiver */
	SET_BIT((USART2-> CR[0]), 13);			/* Enabling USART */

}

void MUSART2_voidTransmit(u8 data){

	volatile u16 Local_Time_Out = 0;
	USART2 -> DR = data;
	while((GET_BIT((USART2 -> SR), 6)) == 0 && ++Local_Time_Out < 100000);
	CLR_BIT(USART2 -> SR , 6);

}

u8 MUSART2_u8Receive(void){

	volatile u16 Local_Time_Out = 0;
	u8 Loc_u8ReceivedData = 0;
	while((GET_BIT((USART2 -> SR), 5)) == 0 && ++Local_Time_Out < 100000);
	Loc_u8ReceivedData = USART2 -> DR;
	return (Loc_u8ReceivedData);
}



void MUSART2_VidSetCallBack( void (*ptr) (u8 Resive) ){

	MUSART2_CallBack = ptr ;

}

void USART2_IRQHandler(void){


	USART2 -> SR = 0 ;
	MUSART2_CallBack(USART2 -> DR);

}














