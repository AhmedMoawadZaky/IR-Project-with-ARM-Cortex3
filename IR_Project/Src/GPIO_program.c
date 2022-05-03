/*****************************************************************/
/****************** Name    : Ahmed Zaky *************************/
/****************** Date    : 6/2/2021   *************************/
/****************** Version : 1.0V       *************************/
/****************** SWC     : GPIO       *************************/
/*****************************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

volatile GPIO *Global_ArrPtrStr_GPIOX[3]={ GPIOA_ADDRESS , GPIOB_ADDRESS , GPIOC_ADDRESS };

u8 	GPIO_VidSetPinDirection( u8 Copy_u8Port , u8 Copy_u8Pin , u8 u8Copy_u8Mode ){

	u8 Local_u8ErroreState = STD_TYPES_OK;

	if(Copy_u8Pin <= PIN7 && Copy_u8Port <= GPIOC ){//low

		Global_ArrPtrStr_GPIOX[Copy_u8Port]->CRL &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ));
		Global_ArrPtrStr_GPIOX[Copy_u8Port]->CRL |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 );
	}
	else if(Copy_u8Pin <= PIN15 && Copy_u8Port <= GPIOC ){//high

		Global_ArrPtrStr_GPIOX[Copy_u8Port]->CRH &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ));
		Global_ArrPtrStr_GPIOX[Copy_u8Port]->CRH |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 );
	}
	else{
		Local_u8ErroreState = STD_TYPES_NOK;
	}
	if(u8Copy_u8Mode == INPUT_PULLUP_PULLDOWN){
		SET_BIT(Global_ArrPtrStr_GPIOX[Copy_u8Port]->ODR , Copy_u8Pin);
	}
	/*else if(u8Copy_u8Mode == INPUT_PULLUP_PULLDOWN){
		SET_BIT(Global_ArrPtrStr_GPIOX[Copy_u8Port]->ODR , Copy_u8Pin);
	}*/
	return Local_u8ErroreState;
}

u8 	GPIO_VidSetPinValue( u8 Copy_u8Port , u8 Copy_u8Pin , u8 u8Copy_u8Value ){

	u8 Local_u8ErroreState = STD_TYPES_OK;

	if(Copy_u8Pin <= PIN15 && Copy_u8Port <= GPIOC && u8Copy_u8Value == HIGH ){//high

		Global_ArrPtrStr_GPIOX[Copy_u8Port]->BSRR = (1 << Copy_u8Pin );
	}
	else if(Copy_u8Pin <= PIN15 && Copy_u8Port <= GPIOC && u8Copy_u8Value == LOW ){//low

		Global_ArrPtrStr_GPIOX[Copy_u8Port]->BRR = (1 << Copy_u8Pin );
	}
	else{
		Local_u8ErroreState = STD_TYPES_NOK;
	}

	return Local_u8ErroreState;
}

u8 	GPIO_u8GetPinValue( u8 Copy_u8Port , u8 Copy_u8Pin ){

	u8 LOC_u8Result = 0 ;

	LOC_u8Result = GET_BIT( Global_ArrPtrStr_GPIOX[Copy_u8Port]->IDR , Copy_u8Pin );

	return LOC_u8Result;
}

u8  GPIO_u8ToglPinValue( u8 Copy_u8Port , u8 Copy_u8Pin){

	u8 Local_u8ErroreState = STD_TYPES_OK;

	if(Copy_u8Pin <= PIN15 && Copy_u8Port <= GPIOC ){

		TOG_BIT( Global_ArrPtrStr_GPIOX[Copy_u8Port]->ODR , Copy_u8Pin );
	}
	else{
		Local_u8ErroreState = STD_TYPES_NOK;
	}

	return Local_u8ErroreState;
}

u8 	GPIO_VidSetPortDirection( u8 Copy_u8Port , u8 Copy_u8Position , u8 Copy_u8Mode ){

	u8 Local_u8ErroreState = STD_TYPES_OK;

	if(Copy_u8Position == LOW && Copy_u8Port <= GPIOC ){

		Global_ArrPtrStr_GPIOX[Copy_u8Port]->CRL = ( 0x11111111 * Copy_u8Mode ) ;
	}
	else if( Copy_u8Position == HIGH && Copy_u8Port <= GPIOC ) {

		Global_ArrPtrStr_GPIOX[Copy_u8Port]->CRH = ( 0x11111111 * Copy_u8Mode ) ;
	}
	else{
		Local_u8ErroreState = STD_TYPES_NOK;
	}

	return Local_u8ErroreState;
}

u8 	GPIO_VidSetPortValue( u8 Copy_u8Port , u8 Copy_u8Position , u16 Copy_u8Value ){

	u8 Local_u8ErroreState = STD_TYPES_OK;

	if(Copy_u8Position == LOW && Copy_u8Port <= GPIOC ){

		Global_ArrPtrStr_GPIOX[Copy_u8Port]->ODR = (Global_ArrPtrStr_GPIOX[Copy_u8Port]->ODR & 0xFF00 ) | ( (u8)Copy_u8Value ) ;
	}
	else if( Copy_u8Position == HIGH && Copy_u8Port <= GPIOC ) {

		Global_ArrPtrStr_GPIOX[Copy_u8Port]->ODR = (Global_ArrPtrStr_GPIOX[Copy_u8Port]->ODR & 0x00FF ) | (     Copy_u8Value ) ;
	}
	else{
		Local_u8ErroreState = STD_TYPES_NOK;
	}

	return Local_u8ErroreState;
}

u16 MGPIO_u16GetPortValue( u8 Copy_u8Port , u8 Copy_u8Position ){

	u16 LOC_u16Result = Global_ArrPtrStr_GPIOX[Copy_u8Port]->IDR;

	if( Copy_u8Position == LOW  ){
		LOC_u16Result &= 0x00FF ;
	}
	else if ( Copy_u8Position == HIGH ){
		LOC_u16Result &= 0xFF00 ;
	}

	return LOC_u16Result ;
}
