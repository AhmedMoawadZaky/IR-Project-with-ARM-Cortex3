/**********************************************************/
/************** Author    : Ahmed Zaky ********************/
/************** Date      : 22 August 2020 ****************/
/************** Version   : V01,V02(2021) *****************/
/**********************************************************/

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

void MEXTI_vidEnableLine 		(u8 copy_u8Line);
void MEXTI_vidDisableLine		(u8 copy_u8Line);
void MEXTI_vidSetSignalLatch 	(u8 copy_u8Line, u8 copy_u8SenseMood);
void MEXTI_vidSoftwareTrigger 	(u8 copy_u8Line);
void MEXTI_vidSetCallBack 		(u8 copy_u8Line, void (*ptr) (void));

#define MEXTI_RISING_EDGE    0
#define MEXTI_FALLING_EDGE   1
#define MEXTI_ON_CHANGE      2

#define MEXTI_LINE0     0
#define MEXTI_LINE1     1
#define MEXTI_LINE2     2
#define MEXTI_LINE3     3
#define MEXTI_LINE4     4
#define MEXTI_LINE5     5
#define MEXTI_LINE6     6
#define MEXTI_LINE7     7
#define MEXTI_LINE8     8
#define MEXTI_LINE9     9
#define MEXTI_LINE10    10
#define MEXTI_LINE11    11
#define MEXTI_LINE12    12
#define MEXTI_LINE13    13
#define MEXTI_LINE14    14
#define MEXTI_LINE15    15

#endif
