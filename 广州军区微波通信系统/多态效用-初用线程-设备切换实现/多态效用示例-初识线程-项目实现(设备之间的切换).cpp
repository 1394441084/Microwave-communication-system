#include "ODU335.h"
#include <thread> //线程头文件
#include <Windows.h>

ODU* odu = NULL;

void test(ODU* odu) {
	odu->setTxFre(35588);
	cout << odu->getTxFre() << endl;
	odu->heartBeat();
}

//odu监测心跳包函数
void oduMonitorHeartBeat() {
	while (1) {
		//判断心跳包
		if (odu->heartBeat()==false) {
			//切换ODU设备
			ODU_CLASS oduclass = odu->oduClass();
			switch (oduclass) {
			case ODU_CLASS::ODU331:
				delete odu;
				odu = new ODU335();
				break;
			case ODU_CLASS::ODU335:
				delete odu;
				odu = new ODU();
				break;
			default:
				odu = NULL;
				return;//线程结束
			}
		}
		Sleep(3000);
	}
}

void test1() {
	/*
//odu是父类指针,现在指向父类
ODU* odu = new ODU;
odu->setTxFre(35588);
cout << odu->getTxFre() << endl;
odu->heartBeat();

//odu现在指向子类
odu = new ODU335;
odu->setTxFre(35590);
cout << odu->getTxFre() << endl;
odu->heartBeat();
*/

	ODU* odu1 = new ODU;
	test(odu1);

	odu1 = new ODU335;
	test(odu1);

	delete odu1;

}

int main(void) {
	odu = new ODU();

	//创建一个线程,用于对ODU进行心跳监测
	thread oduMonitor(oduMonitorHeartBeat);

	//主线程等待oduMonitor这线程结束
	oduMonitor.join();

	delete odu;
	odu = NULL;

	system("pause");
	return 0;
}