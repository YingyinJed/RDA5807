#include "main.h"

int FRE_RDA5807 = 8880;//设置频率
unsigned int RSSI_RDA5807 = 0;//读取信号强度
unsigned char VOL_RDA5807 = 8;//设置音量
void main()
{
    Uart_init();//初始化串口
    TI = 1;
    //初始化RDA5807
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
    //设置初始频率
	RDA5807P_SetFreq(FRE_RDA5807);
    printf("FM_FRE = %d\n",FRE_RDA5807);
    //设置当前频率信号强度
    RSSI_RDA5807 = RDA5807P_GetSigLvl();
    printf("FM_RSSI = %d\n",RSSI_RDA5807);
    //设置当前音量值
    RDA5807P_SetVolumeLevel(VOL_RDA5807);
    printf("FM_VOL = %X\n",VOL_RDA5807);
    //初始化通过进入大循环
    while(1)
    {
        Delay_Ms_(100);
    }
}