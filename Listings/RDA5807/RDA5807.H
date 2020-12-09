//影隐劫
/*该文件需要依赖于之前编写的I2C文件*/
#ifndef _RDA5807_H_
#define _RDA5807_H_

#define READ	        1   
#define WRITE	        0

#define ADRW 	        0x20	//RDA5807P写寄存器地址
#define ADRR 	        0x21	//RDA5807P读寄存器地址

#include <string.h>
#include "I2C.h"
//读或者写数据到RDA5807P
unsigned char OperationRDAFM_2w(unsigned char operation,unsigned char *datas,unsigned char numBytes);

#endif