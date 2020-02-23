#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
#define ODU_CLASS_331 "331"
#define ODU_CLASS_335 "335"


//ODU类型
enum class ODU_CLASS {
	ODU331,
	ODU335,
	ODU_ON
};


//ODU类,用于处理老式ODU331
class ODU
{
public:
	ODU();
	virtual int getTxFre();//获取发射频率
	virtual bool setTxFre(int);//设置发射频率

	virtual int getRxFre();//获取接收频率
	virtual bool setRxFre(int);//设置接收频率

	virtual float getTxPower();//获取发射功率
	virtual bool setTxPower(float);//设置发射功率

	virtual float getRxl();//获取接收电平

	virtual bool heartBeat();//心跳包

	virtual string oduName();//获取该设备名字

	ODU_CLASS oduClass();//获取当前类型

protected:
	int txfre;//发射频率
	int rxfre;//接收频率
	float txpower;//发射功率
	float rxl;//接收电平

	ODU_CLASS odu;
};

