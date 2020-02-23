#include "ODU335.h"

ODU335::ODU335()
{
	odu = ODU_CLASS::ODU335;
	cout << "调用ODU335()\n";

}

bool ODU335::heartBeat()
{
	cout << oduName() << "\t模拟串口协议读取数据: 获取心跳包的反馈...[" << ODU_CLASS_335 << "]";
	string str;
	cin >> str;
	if (str == ODU_CLASS_335) {
		odu = ODU_CLASS::ODU335;
		return true;
	}
	else {
		return false;
	}
}
