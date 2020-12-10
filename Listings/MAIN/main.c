#include "main.h"

int FRE_RDA5807 = 8880;//����Ƶ��
unsigned int RSSI_RDA5807 = 0;//��ȡ�ź�ǿ��
unsigned char VOL_RDA5807 = 8;//��������
void main()
{
    Uart_init();//��ʼ������
    TI = 1;
    //��ʼ��RDA5807
    if(RDA5807P_Intialization())
    {
        printf("FM Init OK!\n");
        Delay_Ms_(600);
        Delay_Ms_(600);
    }
    else
    {
        printf("FM Init Fail!\n");
        while(1);
    }
    //���ó�ʼƵ��
	RDA5807P_SetFreq(FRE_RDA5807);
    printf("FM_FRE = %d\n",FRE_RDA5807);
    //���õ�ǰƵ���ź�ǿ��
    RSSI_RDA5807 = RDA5807P_GetSigLvl();
    printf("FM_RSSI = %d\n",RSSI_RDA5807);
    //���õ�ǰ����ֵ
    RDA5807P_SetVolumeLevel(VOL_RDA5807);
    printf("FM_VOL = %X\n",VOL_RDA5807);
    //��ʼ��ͨ�������ѭ��
    while(1)
    {
        Delay_Ms_(100);
    }
}