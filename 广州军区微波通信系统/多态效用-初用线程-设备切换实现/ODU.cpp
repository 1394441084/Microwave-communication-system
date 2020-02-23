#include "ODU.h"

ODU::ODU()
{
	txfre = 34400;
	rxfre = 31100;
	txpower = 20;
	rxl = 0;
	odu = ODU_CLASS::ODU331;
	cout << "����ODU()" << endl;
}

int ODU::getTxFre()
{
	return txfre;
}

bool ODU::setTxFre(int ff)
{
	txfre = ff;
	cout << oduName()<<"����Ƶ���Ѿ�����Ϊ" << txfre <<"Hz"<< endl;
	return true;
}

int ODU::getRxFre()
{
	return rxfre;
}

bool ODU::setRxFre(int ff)
{
	rxfre = ff;
	cout << oduName()<<"����Ƶ���Ѿ�����Ϊ" << rxfre << "Hz" << endl;
	return true;
}

float ODU::getTxPower()
{
	return txpower;
}

bool ODU::setTxPower(float ff)
{
	txpower = ff;
	cout << oduName()<<"���书���Ѿ�����Ϊ" << txpower << "dBm" << endl;
	return true;
}

float ODU::getRxl()
{
	return rxl;
}

bool ODU::heartBeat()
{
	cout << oduName() << "\tģ�⴮��Э���ȡ����: ��ȡ�������ķ���...[" << ODU_CLASS_331 << "]";
	string str;
	cin >> str;
	if (str == ODU_CLASS_331) {
		odu = ODU_CLASS::ODU331;
		return true;
	}
	else {
		return false;
	}
}

string ODU::oduName()
{
	string str;
	switch (odu) {
	case ODU_CLASS::ODU331:
		str = "ODU331";
		break;
	case ODU_CLASS::ODU335:
		str = "ODU335";
		break;
	case ODU_CLASS::ODU_ON:
	default:
		str = "ODU_ON";
	}

	return str;
}

ODU_CLASS ODU::oduClass()
{
	return odu;
}




