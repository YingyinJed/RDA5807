//Ӱ����
/*���ļ���Ҫ������֮ǰ��д��I2C�ļ�*/
#ifndef _RDA5807_H_
#define _RDA5807_H_

#define READ	        1   
#define WRITE	        0

#define ADRW 	        0x20	//RDA5807Pд�Ĵ�����ַ
#define ADRR 	        0x21	//RDA5807P���Ĵ�����ַ

#include <string.h>
#include "I2C.h"
//������д���ݵ�RDA5807P
unsigned char OperationRDAFM_2w(unsigned char operation,unsigned char *datas,unsigned char numBytes);

#endif