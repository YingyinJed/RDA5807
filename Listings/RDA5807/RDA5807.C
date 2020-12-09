//影隐劫
#include "RDA5807.h"
/*******************************************************************************
* 函数名         :OperationRDAFM_2w()
* 函数功能     	 :读或者写数据到RDA5807
* 输入           :operation   —— 功能选择"读READ/写WRITE"
                  datas       —— 读或写的数据指针"
                  numBytes    —— 需要读或写numBytes个字节
* 输出           :无
*******************************************************************************/
unsigned char OperationRDAFM_2w(unsigned char operation,unsigned char *datas,unsigned char numBytes)
{
    unsigned char j,acknowledge = 0;
    I2C_Start();
    if(operation == READ)
    {
        I2C_Send_Byte(ADRR);//发送读信号给RDA5807
        acknowledge = Test_ACK();//等待并获得应答信号
    }
    else
    {
        I2C_Send_Byte(ADRW);//发送写信号给RDA5807
        acknowledge = Test_ACK();//等待并获得应答信号
    }
    for(j = 0;j < numBytes;j++,datas++)
    {
        if(operation == READ)
        {
            if(j == (numBytes - 1))
            {
                *datas = I2C_Read_Byte();//接收从I2C接收到的信号
                Master_ACK(I2C_NACK);//并发送相应的应答信号
            }
            else
            {
                *datas = I2C_Read_Byte();//接收从I2C接收到的信号
                Master_ACK(I2C_ACK);//并发送相应的应答信号
            }
        }
        else
        {
            I2C_Send_Byte(*datas);//发送数据给RDA5807
            acknowledge = Test_ACK();//等待并获得应答信号
        }
    }
    I2C_Stop();
    return acknowledge;
}