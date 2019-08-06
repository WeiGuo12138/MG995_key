#ifndef  _PROTOCAL_H
#define  _PROTOCAL_H

#include "usart.h"

//#define OpenmvUart huart2   //����2 �궨��

typedef enum
{
    //��ͷ1
    HEADER1,
    //��ͷ2
    HEADER2,
    //ID
    CMDID1,
    //����λ
    LENGTH1,
    //����λ
    DATA1,
    //У��λ
    CHECK1,
    //��β
    END,


} DEF_STATE;

//������Ϣ�ṹ��
typedef struct
{
    DEF_STATE state;
    unsigned char Cmd_ID;
    unsigned char  Length;
    unsigned char Re_Data[20];
    unsigned char Check;
} DEF_RE_RECEIVE;

//
typedef struct
{
    unsigned char ready_op;
} DEF_READ;

extern uint8_t check[20];
extern int16_t pack_motor[2];
void RECEIVE_PACK(unsigned char data);
void I2C_PACK(unsigned char data);

#endif
