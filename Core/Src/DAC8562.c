#include "DAC8562.h"
#include "math.h"
#include <stdio.h>
#include <string.h>

extern SPI_HandleTypeDef hspi2; 

void DAC8562_Init(void) {
    __HAL_RCC_SPI2_CLK_ENABLE();
	  DAC8562_LDAC_L;
	  DAC8562_CLR_L;
	DAC8562_WriteReg(CMD_GAIN,DATA_GAIN_B1_A1);
	HAL_Delay(10);
    DAC8562_PWR_UP_A(); //开启通道A
	HAL_Delay(10);
    DAC8562_REF_EN();//参考电压2.5V
	HAL_Delay(10);
}

void DAC8562_WriteReg(uint8_t Command,uint16_t Data) {
	
    DAC8562_SYNC_L;  // 启动传输
	uint8_t txData[3] = {Command,(uint8_t)(Data >> 8) , (uint8_t)Data & 0xFF};
    HAL_SPI_Transmit(&hspi2, txData, 3, HAL_MAX_DELAY);
    DAC8562_SYNC_H;  // 结束传输数据

}

void DAC8562_PWR_UP_A(void) {
    uint8_t txData2[3] = {0x20, 0x00, 0x01};
    DAC8562_SYNC_L;  // 启动传输
    HAL_SPI_Transmit(&hspi2, txData2, 3, HAL_MAX_DELAY);
    DAC8562_SYNC_H;  // 结束传输数据

}

void DAC8562_REF_EN(void) {
    uint8_t txData3[3] = {CMD_INTERNAL_REF_EN, 0x00, 0x01};
    DAC8562_SYNC_L;  // 启动传输
    HAL_SPI_Transmit(&hspi2, txData3, 3, HAL_MAX_DELAY);
    DAC8562_SYNC_H;  // 结束传输数据
	
}

void DAC8562_SetVoltage(float voltage) {
	if (voltage < 0) voltage = 0;
    if (voltage > 2.5f) voltage = 2.5f;

    // 2. 计算DAC代码 (16位)
    // 公式: code = (voltage / Vref) * 65536
    uint32_t code = (uint32_t)((voltage / 2.5f) * 65536.0f);
    if (code > 0xFFFF) code = 0xFFFF; // 限制最大值
	DAC8562_WriteReg(CMD_SETA_UPDATEA,code);
}

//    // 3. 构造SPI数据
//    uint8_t txData[3] = {
//        0x18,              // 命令: 更新通道A (0x18)
//        (uint8_t)(code >> 8), // 高8位数据
//        (uint8_t)(code)       // 低8位数据
//    };
//    DAC8562_WriteReg(txData);//写入并更新通道A，0x18
//}

//void DAC8562_PrintVoltage(void) {  
    //char msg[50];
    //snprintf(msg, sizeof(msg), "VOUTA: %.3f V\r\n", current_voltage);
    //HAL_UART_Transmit(&huart1, (uint8_t*)msg, strlen(msg), 100);
//}


