/**********************************************************/
/************** Author    : Ahmed Zaky ********************/
/************** Date      : 22 August 2020 ****************/
/************** Version   : V01,V02(2021) *****************/
/**********************************************************/

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

typedef struct{
	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;
	
}EXTI_t;

#define EXTI ((volatile EXTI_t *) 0x40010400 )

#endif
