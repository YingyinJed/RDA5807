//Ӱ���٣�ZGT��
#ifndef _I2C_H
#define _I2C_H

#include <reg52.h>
#include <intrins.h>

#define  I2C_ACK     0
#define  I2C_NACK    1

#define AT24C02_ADDR 0xa0			//����ʵ�����AT24C02��ַ��EEPROM�ⲿ�ڴ�ĵ�ַ
#define PCF8591_ADDR 0x90			//����ʵ�����PCF8591��ַ��ģ��ת���ĵ�ַ
#define DACOUT_EN	 0x40			//DAC���ʹ��

#ifndef Main_Fosc
#define Main_Fosc	 11059200UL		//������ʱ�ӵ�HZ							
#endif

sbit SDA = P2^0;	//��һ�������ߺ�һ��ʱ���߸���ʵ�ʵ�·����
sbit SCL = P2^1;	//ʵ����в��õ���P2^0��P2^1

void Delay_5us(void);										//��ʱ5us����I2CЭ���еĸ�����ʱ
void I2C_Init(void);										//I2C��ʼ��
void I2C_Start(void);										//I2C��ʼ�ź�
void I2C_Stop(void);										//I2C��ֹ�ź�
void Master_ACK(bit i);										//����Ӧ���ź�
bit	 Test_ACK(void);										//���شӻ�Ӧ���ź�
void I2C_Send_Byte(unsigned char byte);						//����ͨ��I2C����һ���ֽ�
unsigned char I2C_Read_Byte(void);							//����ͨ��I2C��ȡһ���ֽ�
//bit I2C_TransmitData(unsigned char Slave_ADDR,ADDR,DATA);	//����һ���ֽ����ݵ��ض��ĵ�ַ(�������ʹ����AT24C02��PCF8591Ҫ��˵)
//unsigned char I2C_ReceiveData(unsigned char Slave_ADDR,ADDR);//��������һ���ض����豸��ַ������(ͬ��)
//int I2C_ReceiveData1(unsigned char Slave_ADDR,ADDR);		//������ĺ���һ���������������ʹ洢����
/*-----------------------------------------------------------------
��������Ӻ������÷��Ƚ��������Ҫ�ο���Ӧ����Ҫ�Ի���I2C�豸���ֲ�
����ԭ//��ע����AT24C02��ע�Ͷ�PCF8591������ͬ
	I2C_TransmitData(PCF8591_ADDR,DACOUT_EN,100);//��PCF8591���ǵڶ���������ģ�������ʹ�ܣ�����������AT24C02һ��
	I2C_ReceiveData(PCF8591_ADDR,ADDR);			 //��PCF8591�еڶ��������ǿ����ֽڣ�������AT24C02һ��
*/
#endif