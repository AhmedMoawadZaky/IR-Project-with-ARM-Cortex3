/*****************************************************************/
/****************** Name    : Ahmed Zaky *************************/
/****************** Date    : 11/2/2021  *************************/
/****************** Version : 1.0V       *************************/
/****************** SWC     : NVIC       *************************/
/*****************************************************************/

#include "STD_TYPES.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

u8 MNVIC_u8EnablePeripheral ( u8 Copy_u8INTID ){

	u8 Local_u8ErroreState = STD_TYPES_NOK;

	if(Copy_u8INTID <= DMA2_Channel4_5 ){
		/*
		 * Copy_u8INTID / 32 -> Refer to Register Number For the Target IRQ
		 * Copy_u8INTID % 32 -> Refer to Bit Number For the Target IRQ in the Register
		 *
		 * */
		MNVIC->ISER[ Copy_u8INTID / 32 ] = 1 << ( Copy_u8INTID % 32 );
		Local_u8ErroreState = STD_TYPES_OK;
	}
	return Local_u8ErroreState;
}

u8 MNVIC_u8DisablePeripheral ( u8 Copy_u8INTID ){

	u8 Local_u8ErroreState = STD_TYPES_NOK;

	if(Copy_u8INTID <= DMA2_Channel4_5 ){
		/*
		 * Copy_u8INTID / 32 -> Refer to Register Number For the Target IRQ
		 * Copy_u8INTID % 32 -> Refer to Bit Number For the Target IRQ in the Register
		 *
		 * */
		MNVIC->ICER[ Copy_u8INTID / 32 ] = 1 << ( Copy_u8INTID % 32 ) ;
		Local_u8ErroreState = STD_TYPES_OK;
	}
	return Local_u8ErroreState;
}

u8 MNVIC_u8SetPendingFlag ( u8 Copy_u8INTID ){

	u8 Local_u8ErroreState = STD_TYPES_NOK;

	if(Copy_u8INTID <= DMA2_Channel4_5 ){
		/*
		 * Copy_u8INTID / 32 -> Refer to Register Number For the Target IRQ
		 * Copy_u8INTID % 32 -> Refer to Bit Number For the Target IRQ in the Register
		 *
		 * */
		MNVIC->ISPR[ Copy_u8INTID / 32 ] = 1 << ( Copy_u8INTID % 32 ) ;
		Local_u8ErroreState = STD_TYPES_OK;
	}
	return Local_u8ErroreState;
}

u8 MNVIC_u8ClearPendingFlag ( u8 Copy_u8INTID ){

	u8 Local_u8ErroreState = STD_TYPES_NOK;

	if(Copy_u8INTID <= DMA2_Channel4_5 ){
		/*
		 * Copy_u8INTID / 32 -> Refer to Register Number For the Target IRQ
		 * Copy_u8INTID % 32 -> Refer to Bit Number For the Target IRQ in the Register
		 *
		 * */
		MNVIC->ICPR[ Copy_u8INTID / 32 ] = 1 << ( Copy_u8INTID % 32 ) ;
		Local_u8ErroreState = STD_TYPES_OK;
	}
	return Local_u8ErroreState;
}

u8 MNVIC_u8GetActiveFlag(u8 Copy_u8INTID , u8 * Copy_Pu8ActiveVal){

	u8 Local_u8ErroreState = STD_TYPES_NOK;
	if(Copy_u8INTID <= DMA2_Channel4_5 && Copy_Pu8ActiveVal != NULL){
		/*
		 * Copy_u8INTID / 32 -> Refer to Register Number For the Target IRQ
		 * Copy_u8INTID % 32 -> Refer to Bit Number For the Target IRQ in the Register
		 *
		 * */
		*Copy_Pu8ActiveVal = (MNVIC->IABR[ Copy_u8INTID/32 ] >> (Copy_u8INTID % 32)) & 1;
		Local_u8ErroreState = STD_TYPES_OK;
	}
	return Local_u8ErroreState ;

}

u8 MNVIC_u8SetPriority( u8 Copy_u8INTID , u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority ){

	u8 Local_u8ErroreState = STD_TYPES_NOK;

	if(Copy_u8INTID <= DMA2_Channel4_5 && Copy_u8GroupPriority <= 3 && Copy_u8SubPriority <= 3){

		u8 Local_u8Priority =  Copy_u8SubPriority | ( Copy_u8GroupPriority <<  2 )  ;
		MNVIC->IPR[ Copy_u8INTID ] = Local_u8Priority << 4 ;
		Local_u8ErroreState = STD_TYPES_OK;
	}
	return Local_u8ErroreState;
}

