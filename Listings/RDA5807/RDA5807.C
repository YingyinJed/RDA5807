//Ӱ����
#include "RDA5807.h"
/*******************************************************************************
* ������         :OperationRDAFM_2w()
* ��������     	 :������д���ݵ�RDA5807
* ����           :operation   ���� ����ѡ��"��READ/дWRITE"
                  datas       ���� ����д������ָ��"
                  numBytes    ���� ��Ҫ����дnumBytes���ֽ�
* ���           :��
*******************************************************************************/
unsigned char OperationRDAFM_2w(unsigned char operation,unsigned char *datas,unsigned char numBytes)
{
    unsigned char j,acknowledge = 0;
    I2C_Start();
    if(operation == READ)
    {
        I2C_Send_Byte(ADRR);//���Ͷ��źŸ�RDA5807
        acknowledge = Test_ACK();//�ȴ������Ӧ���ź�
    }
    else
    {
        I2C_Send_Byte(ADRW);//����д�źŸ�RDA5807
        acknowledge = Test_ACK();//�ȴ������Ӧ���ź�
    }
    for(j = 0;j < numBytes;j++,datas++)
    {
        if(operation == READ)
        {
            if(j == (numBytes - 1))
            {
                *datas = I2C_Read_Byte();//���մ�I2C���յ����ź�
                Master_ACK(I2C_NACK);//��������Ӧ��Ӧ���ź�
            }
            else
            {
                *datas = I2C_Read_Byte();//���մ�I2C���յ����ź�
                Master_ACK(I2C_ACK);//��������Ӧ��Ӧ���ź�
            }
        }
        else
        {
            I2C_Send_Byte(*datas);//�������ݸ�RDA5807
            acknowledge = Test_ACK();//�ȴ������Ӧ���ź�
        }
    }
    I2C_Stop();
    return acknowledge;
}