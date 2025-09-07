#ifndef __DAC8562_H
#define __DAC8562_H

#include "stm32f1xx_hal.h"


#define DAC8562_SYNC_PIN    GPIO_PIN_12 
#define DAC8562_SYNC_PORT   GPIOB
#define DAC8562_CLR_PIN     GPIO_PIN_8  
#define DAC8562_CLR_PORT    GPIOA
#define DAC8562_LDAC_PIN    GPIO_PIN_11 
#define DAC8562_LDAC_PORT   GPIOA

#define DAC8562_SYNC_H      HAL_GPIO_WritePin(DAC8562_SYNC_PORT, DAC8562_SYNC_PIN, GPIO_PIN_SET)
#define DAC8562_SYNC_L      HAL_GPIO_WritePin(DAC8562_SYNC_PORT, DAC8562_SYNC_PIN, GPIO_PIN_RESET)
#define DAC8562_CLR_H       HAL_GPIO_WritePin(DAC8562_CLR_PORT, DAC8562_CLR_PIN, GPIO_PIN_SET)
#define DAC8562_CLR_L       HAL_GPIO_WritePin(DAC8562_CLR_PORT, DAC8562_CLR_PIN, GPIO_PIN_RESET)
#define DAC8562_LDAC_H      HAL_GPIO_WritePin(DAC8562_LDAC_PORT, DAC8562_LDAC_PIN, GPIO_PIN_SET)
#define DAC8562_LDAC_L      HAL_GPIO_WritePin(DAC8562_LDAC_PORT, DAC8562_LDAC_PIN, GPIO_PIN_RESET)

#define CMD_PWR_UP_A          0x20  

#define DATA_PWR_UP_A         0x0001 // bit0=1(通道A上电)

#define DATA_GAIN             0x0003


#define CMD_SETA_UPDATEA      		0x18	// A通道命令+16位A路数据
#define CMD_SETB_UPDATEB      		0x19	// B通道命令+16位B路数据
#define CMD_UPDATE_ALL_DACS	   		0x0F	// 更新两路寄存器命令，后16位只需时钟即可
 
#define CMD_GAIN	    			0x02	// 内部放大倍数命令
#define DATA_GAIN_B2_A2    		    0x0000	// B路2倍，A路1倍
#define DATA_GAIN_B2_A1       		0x0001	// B路1倍，A路2倍
#define DATA_GAIN_B1_A2         	0x0002	// B路2倍，A路2倍
#define DATA_GAIN_B1_A1       		0x0003	// B路1倍，A路1倍				  
 
#define CMD_PWR_UP_A_B		      	0x20	// 命令：上电A、B路
#define DATA_PWR_UP_A_B		      	0x0003	// 数据：Power up DAC-A and DAC-B	data
 
#define CMD_RESET_ALL_REG	      	0x28	// 命令：所有寄存器复位、清空寄存器
#define DATA_RESET_ALL_REG     		0x0001	// 数据：所有寄存器复位、清空寄存器
 
#define CMD_LDAC_DIS	        	0x30	// LDAC脚功能命令
#define DATA_LDAC_DIS       		0x0003	// LDAC脚不起作用
 
#define CMD_INTERNAL_REF_DIS    	0x38	// 命令：Disable internal reference and reset DACs to gain = 1
#define DATA_INTERNAL_REF_DIS    	0x0000	// 数据：Disable internal reference and reset DACs to gain = 1
#define CMD_INTERNAL_REF_EN         0x38	// 命令：Enable Internal Reference & reset DACs to gain = 2
#define DATA_INTERNAL_REF_EN    	0x0001	// 数据：Enable Internal Reference & reset DACs to gain = 2





void DAC8562_Init(void);
void DAC8562_WriteReg(uint8_t Command,uint16_t Data);
void DAC8562_PWR_UP_A(void);
void DAC8562_REF_EN(void);
void DAC8562_SetVoltage(float voltage);
void DAC8562_PrintVoltage(void);

#endif
