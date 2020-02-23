#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
#define ODU_CLASS_331 "331"
#define ODU_CLASS_335 "335"


//ODU����
enum class ODU_CLASS {
	ODU331,
	ODU335,
	ODU_ON
};


//ODU��,���ڴ�����ʽODU331
class ODU
{
public:
	ODU();
	virtual int getTxFre();//��ȡ����Ƶ��
	virtual bool setTxFre(int);//���÷���Ƶ��

	virtual int getRxFre();//��ȡ����Ƶ��
	virtual bool setRxFre(int);//���ý���Ƶ��

	virtual float getTxPower();//��ȡ���书��
	virtual bool setTxPower(float);//���÷��书��

	virtual float getRxl();//��ȡ���յ�ƽ

	virtual bool heartBeat();//������

	virtual string oduName();//��ȡ���豸����

	ODU_CLASS oduClass();//��ȡ��ǰ����

protected:
	int txfre;//����Ƶ��
	int rxfre;//����Ƶ��
	float txpower;//���书��
	float rxl;//���յ�ƽ

	ODU_CLASS odu;
};

