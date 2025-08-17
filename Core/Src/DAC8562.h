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

#define CMD_SETA_UPDATEA      0x18  
#define CMD_PWR_UP_A          0x20  
#define DATA_PWR_UP_A         0x0001 // bit0=1(通道A上电)
#define CMD_INTERNAL_REF_EN   0x38  
#define DATA_INTERNAL_REF_EN  0x0001
#define CMD_GAIN              0x02
#define DATA_GAIN             0x0003

void DAC8562_Init(void);
void DAC8562_WriteReg(uint8_t code[]);
void DAC8562_PWR_UP_A(void);
void DAC8562_REF_EN(void);
void DAC8562_SetVoltage(float voltage);
void DAC8562_PrintVoltage(void);

#endif
