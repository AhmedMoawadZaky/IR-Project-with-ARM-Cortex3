/* LIB Layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL Layer */
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_Interface.h"
#include "USART_Interface.h"
#include "STK_interface.h"
#include "EXTI_interface.h"


volatile u8 IDX=0,StartBit=0,Data=0;
volatile u32 ArrOfTimeRelatedToBitsInFrame[50]={0};

void CallBack_GetFrame(void);
void TackAction(void);
void voidPlay(void);

int main(void){

	RCC_VidInit();
	/* Enable Clock For GPIOA To access GPIOA Pins */
	RCC_VidEnablePeripheralClock(APB2_BUS, GPIOA_RCC);

	/* Init Pin0 Direction to use as EXTI0 */
	GPIO_VidSetPinDirection(GPIOA, PIN0, INPUT_FLOATING);
	GPIO_VidSetPinDirection(GPIOA, PIN1, OUTPUT_SPEED_2MHZ_PP);
	GPIO_VidSetPinDirection(GPIOA, PIN2, OUTPUT_SPEED_2MHZ_PP);
	GPIO_VidSetPinDirection(GPIOA, PIN3, OUTPUT_SPEED_2MHZ_PP);

	/* Set CallBack Function which it call "CallBack_GetFrame" to IRQ_EXTI0 Interrupt */
	MEXTI_vidSetCallBack(MEXTI_LINE0,CallBack_GetFrame);

	/* First Init EXTI_0 Line Then Set Signal to Sense Falling Edge*/
	MEXTI_vidEnableLine(MEXTI_LINE0);
	MEXTI_vidSetSignalLatch(MEXTI_LINE0, MEXTI_FALLING_EDGE);

	/* Enable EXTI0 Peripheral by NVIC "To Execute INT If (PIF&PIE&GIE) = TRUE " */
	MNVIC_u8EnablePeripheral(EXTI0);

	/* SysTick Init */
	MSTK_voidInit(); /* Enable SysTick AHB/8 = 1MHZ */

	/* Loop forever */
	while(1){


	}
	return 0;
}

void CallBack_GetFrame(void){

	if(StartBit == 0){
		MSTK_voidSetIntervalSingle(100000UL, TackAction);
		StartBit=1;
	}
	else{
		ArrOfTimeRelatedToBitsInFrame[IDX++]=MSTK_u32GetElapsedTime();
		MSTK_voidSetIntervalSingle(100000UL, TackAction);
	}
}

void TackAction(){

	int i;
	Data=0;
	/*if((ArrOfTimeRelatedToBitsInFrame[0]>=10000) && (ArrOfTimeRelatedToBitsInFrame[0] <= 14000))*/{
		for (i=0;i<8;++i){
			if((ArrOfTimeRelatedToBitsInFrame[17+i]>2000) &&(ArrOfTimeRelatedToBitsInFrame[17+i]<2400)){
				SET_BIT(Data,i);
			}
			else{
				CLR_BIT(Data,i);
			}
		}
	}
	voidPlay();
	IDX=0;
	ArrOfTimeRelatedToBitsInFrame[0]=0;
	StartBit=0;
}


void voidPlay()
{
	switch (Data)
	{
		case 70: GPIO_VidSetPinValue(GPIOA,1,HIGH); break;
		case 69: GPIO_VidSetPinValue(GPIOA,1,LOW);  break;
		case 71: GPIO_VidSetPinValue(GPIOA,2,HIGH); break;
		case 68: GPIO_VidSetPinValue(GPIOA,2,LOW); break;
		case 64: GPIO_VidSetPinValue(GPIOA,3,HIGH);  break;
		case 67: GPIO_VidSetPinValue(GPIOA,3,LOW);  break;
	}
}
