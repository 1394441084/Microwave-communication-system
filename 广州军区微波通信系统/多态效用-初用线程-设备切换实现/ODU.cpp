#include "ODU.h"

ODU::ODU()
{
	txfre = 34400;
	rxfre = 31100;
	txpower = 20;
	rxl = 0;
	odu = ODU_CLASS::ODU331;
	cout << "调用ODU()" << endl;
}

int ODU::getTxFre()
{
	return txfre;
}

bool ODU::setTxFre(int ff)
{
	txfre = ff;
	cout << oduName()<<"发射频率已经设置为" << txfre <<"Hz"<< endl;
	return true;
}

int ODU::getRxFre()
{
	return rxfre;
}

bool ODU::setRxFre(int ff)
{
	rxfre = ff;
	cout << oduName()<<"接收频率已经设置为" << rxfre << "Hz" << endl;
	return true;
}

float ODU::getTxPower()
{
	return txpower;
}

bool ODU::setTxPower(float ff)
{
	txpower = ff;
	cout << oduName()<<"发射功率已经设置为" << txpower << "dBm" << endl;
	return true;
}

float ODU::getRxl()
{
	return rxl;
}

bool ODU::heartBeat()
{
	cout << oduName() << "\t模拟串口协议读取数据: 获取心跳包的反馈...[" << ODU_CLASS_331 << "]";
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




