/**********************************************************/
/************** Author    : Ahmed Zaky ********************/
/************** Date      : 22 August 2020 ****************/
/************** Version   : V01,V02(2021) *****************/
/**********************************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"EXTI_interface.h"
#include"EXTI_config.h"
#include"EXTI_PRivate.h"

static void(*EXTI_callback[16])(void)={	NULL,NULL,NULL,NULL,
										NULL,NULL,NULL,NULL,
										NULL,NULL,NULL,NULL,
										NULL,NULL,NULL,NULL};

void MEXTI_vidEnableLine (u8 copy_u8Line) {
    SET_BIT(EXTI->IMR, copy_u8Line);
}

void MEXTI_vidDisableLine (u8 copy_u8Line) {
    CLR_BIT(EXTI->IMR, copy_u8Line);
}

void MEXTI_vidSetSignalLatch (u8 copy_u8Line, u8 copy_u8SenseMood) {
    switch (copy_u8SenseMood)
    {
    case MEXTI_RISING_EDGE:
        SET_BIT(EXTI->RTSR, copy_u8Line);
        CLR_BIT(EXTI->FTSR, copy_u8Line);
        break;
    case MEXTI_FALLING_EDGE:
        SET_BIT(EXTI->FTSR, copy_u8Line);
        CLR_BIT(EXTI->RTSR, copy_u8Line);
        break;
    case MEXTI_ON_CHANGE:
        SET_BIT(EXTI->RTSR, copy_u8Line);
        SET_BIT(EXTI->FTSR, copy_u8Line);
        break;
    default:
        /*Return Error*/
        break;
    }
}

void MEXTI_vidSoftwareTrigger (u8 copy_u8Line) {
    SET_BIT(EXTI->SWIER, copy_u8Line);
}

void MEXTI_vidSetCallBack (u8 copy_u8Line, void (*ptr) (void)) {
    EXTI_callback[copy_u8Line] = ptr;
}

void EXTI0_IRQHandler (void) {
    EXTI_callback[0]();
    SET_BIT(EXTI->PR, 0);
}
void EXTI1_IRQHandler (void) {
    EXTI_callback[1]();
    SET_BIT(EXTI->PR, 1);
}
void EXTI2_IRQHandler (void) {
    EXTI_callback[2]();
    SET_BIT(EXTI->PR, 2);
}
void EXTI3_IRQHandler (void) {
    EXTI_callback[3]();
    SET_BIT(EXTI->PR, 3);
}
void EXTI4_IRQHandler (void) {
    EXTI_callback[4]();
    SET_BIT(EXTI->PR, 4);
}
void EXTI5_IRQHandler (void) {
    EXTI_callback[5]();
    SET_BIT(EXTI->PR, 5);
}
void EXTI6_IRQHandler (void) {
    EXTI_callback[6]();
    SET_BIT(EXTI->PR, 6);
}
void EXTI7_IRQHandler (void) {
    EXTI_callback[7]();
    SET_BIT(EXTI->PR, 7);
}
void EXTI8_IRQHandler (void) {
    EXTI_callback[8]();
    SET_BIT(EXTI->PR, 8);
}
void EXTI9_IRQHandler (void) {
    EXTI_callback[9]();
    SET_BIT(EXTI->PR, 9);
}
void EXTI10_IRQHandler (void) {
    EXTI_callback[10]();
    SET_BIT(EXTI->PR, 10);
}
void EXTI11_IRQHandler (void) {
    EXTI_callback[11]();
    SET_BIT(EXTI->PR, 11);
}
void EXTI12_IRQHandler (void) {
    EXTI_callback[12]();
    SET_BIT(EXTI->PR, 12);
}
void EXTI13_IRQHandler (void) {
    EXTI_callback[13]();
    SET_BIT(EXTI->PR, 13);
}
void EXTI14_IRQHandler (void) {
    EXTI_callback[14]();
    SET_BIT(EXTI->PR, 14);
}
void EXTI15_IRQHandler (void) {
    EXTI_callback[15]();
    SET_BIT(EXTI->PR, 15);
}
