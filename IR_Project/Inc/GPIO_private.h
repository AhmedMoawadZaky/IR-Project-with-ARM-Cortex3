/*****************************************************************/
/****************** Name    : Ahmed Zaky *************************/
/****************** Date    : 6/2/2021   *************************/
/****************** Version : 1.0V       *************************/
/****************** SWC     : GPIO       *************************/
/*****************************************************************/

#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

typedef struct{

	volatile u32 CRL  ;//0x00
	volatile u32 CRH  ;//0x04
	volatile u32 IDR  ;//0x08
	volatile u32 ODR  ;
	volatile u32 BSRR ;
	volatile u32 BRR  ;
	volatile u32 LCKR ;

}GPIO;

#define GPIOA_ADDRESS 			((volatile GPIO*)0x40010800)
#define GPIOB_ADDRESS 			((volatile GPIO*)0x40010C00)
#define GPIOC_ADDRESS 			((volatile GPIO*)0x40011000)

#endif