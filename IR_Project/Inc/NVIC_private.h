/*****************************************************************/
/****************** Name    : Ahmed Zaky *************************/
/****************** Date    : 11/2/2021  *************************/
/****************** Version : 1.0V       *************************/
/****************** SWC     : NVIC       *************************/
/*****************************************************************/

#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

typedef struct{

	volatile u32 ISER    [ 32 ];
	volatile u32 ICER    [ 32 ];
	volatile u32 ISPR    [ 32 ];
	volatile u32 ICPR    [ 32 ];
	volatile u32 IABR    [ 32 ];
	volatile u32 RESERVED[ 32 ];
	volatile u8 IPR      [ 128];

}NVIC;

#define MNVIC     	 	((volatile NVIC *)0xE000E100  )


#endif
