#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key.h"
#include "timer.h"
#include "protocol.h"
#include "i2c.h"


int main(void)
{
//	u8 dir=1;
    u8 pwmval=0;
    u8 i2c_receive=0;
    HAL_Init();                    	 	//��ʼ��HAL��
    Stm32_Clock_Init(RCC_PLL_MUL9);   	//����ʱ��,72M
    delay_init(72);               		//��ʼ����ʱ����
    uart_init(115200);					//��ʼ������
    LED_Init();							//��ʼ��LED
//	KEY_Init();							//��ʼ������
    TIM4_PWM_Init(200-1,7200-1);       	//72M/72=1M�ļ���Ƶ�ʣ��Զ���װ��Ϊ500����ôPWMƵ��Ϊ1M/500=2kHZ
    IIC_Init();                         //IIC��ʼ��
    
    while(1)
    {
        delay_ms(10);
        if(pack_motor[0]==1)
        {
            pwmval=189;
          //  TIM_SetTIM3Compare2(175);
           printf("1");
        }
        if(pack_motor[0]==2)
        {
            pwmval=194;
            printf("2");
         //   TIM_SetTIM3Compare2(195);
        }
         TIM_SetTIM3Compare2(pwmval);
        
//      �����ò�Ҫ����195 ��С��Ҫ����175
//        printf("hello world/n");
//        HAL_Delay(200);
//        HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,GPIO_PIN_SET);	//����
//        HAL_Delay(200);
//         HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,GPIO_PIN_RESET);	//����
//        HAL_Delay(200);
        i2c_receive = IIC_Read_Byte(0);
        I2C_PACK(i2c_receive);
        delay_ms(10);

    }
}
