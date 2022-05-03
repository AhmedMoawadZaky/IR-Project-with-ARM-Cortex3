/*****************************************************************/
/****************** Name    : Ahmed Zaky *************************/
/****************** Date    : 4/2/2021   *************************/
/****************** Version : 1.0V       *************************/
/****************** SWC     : RCC        *************************/
/*****************************************************************/
#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

typedef struct{
	volatile u32 CR;
	volatile u32 CFGR;
	volatile u32 CIR;
	volatile u32 APB2RSTR;
	volatile u32 APB1RSTR;
	volatile u32 AHBENR;
	volatile u32 APB2ENR;
	volatile u32 APB1ENR;
	volatile u32 BDCR;
	volatile u32 CSR;
}RCC;


#define RCC ((volatile RCC *)0x40021000)   
         


#endif
