#include "ODU335.h"

ODU335::ODU335()
{
	odu = ODU_CLASS::ODU335;
	cout << "����ODU335()\n";

}

bool ODU335::heartBeat()
{
	cout << oduName() << "\tģ�⴮��Э���ȡ����: ��ȡ�������ķ���...[" << ODU_CLASS_335 << "]";
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
