/*****************************************************************/
/****************** Name    : Ahmed Zaky *************************/
/****************** Date    : 4/2/2021   *************************/
/****************** Version : 1.0V       *************************/
/****************** SWC     : RCC        *************************/
/*****************************************************************/

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/*
ClockType Configuration :                         
   1-HSI                                     
   2-HSE                                     
   3-PLL                                     
	   3.1-PLL_HSI_DIVIDED_BY_2              
	   3.2-PLL_HSE                           
	   3.3-PLL_HSE_DIVIDED_BY_2              
   4-HSE_BYPASS    

*/	

#define CLOCK_TYPE       HSE
#define PLL_SOURCE       PLL_HSE_DIVIDED_BY_2


/*
ClockFactor For PLL:   
	01-PLL_CLOCKk_MULTIPLE_BY_2    
	02-PLL_CLOCKk_MULTIPLE_BY_3    
	03-PLL_CLOCKk_MULTIPLE_BY_4    
	04-PLL_CLOCKk_MULTIPLE_BY_5    
	05-PLL_CLOCKk_MULTIPLE_BY_6    
	06-PLL_CLOCKk_MULTIPLE_BY_7    
	07-PLL_CLOCKk_MULTIPLE_BY_8    
	08-PLL_CLOCKk_MULTIPLE_BY_9    
	09-PLL_CLOCKk_MULTIPLE_BY_10   
	10-PLL_CLOCKk_MULTIPLE_BY_11  
	11-PLL_CLOCKk_MULTIPLE_BY_12  
	12-PLL_CLOCKk_MULTIPLE_BY_13  
	13-PLL_CLOCKk_MULTIPLE_BY_14  
	14-PLL_CLOCKk_MULTIPLE_BY_15  
	15-PLL_CLOCKk_MULTIPLE_BY_16  
*/

#define CLOCK_FACTOR     PLL_CLOCKk_MULTIPLE_BY_9

           
/*
	Clock Security System 
	1-Enable:                                         
		-To Set HSI By H.W When There are Failure In HSE 
	2-Disable
*/

#define CLOCK_SECURITY_SYSTEM     DISABLE_CLOCK_SECURITY_SYSTEM


#endif
