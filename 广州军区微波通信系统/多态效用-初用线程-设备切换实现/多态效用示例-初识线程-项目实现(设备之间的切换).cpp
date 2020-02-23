#include "ODU335.h"
#include <thread> //�߳�ͷ�ļ�
#include <Windows.h>

ODU* odu = NULL;

void test(ODU* odu) {
	odu->setTxFre(35588);
	cout << odu->getTxFre() << endl;
	odu->heartBeat();
}

//odu�������������
void oduMonitorHeartBeat() {
	while (1) {
		//�ж�������
		if (odu->heartBeat()==false) {
			//�л�ODU�豸
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
				return;//�߳̽���
			}
		}
		Sleep(3000);
	}
}

void test1() {
	/*
//odu�Ǹ���ָ��,����ָ����
ODU* odu = new ODU;
odu->setTxFre(35588);
cout << odu->getTxFre() << endl;
odu->heartBeat();

//odu����ָ������
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

	//����һ���߳�,���ڶ�ODU�����������
	thread oduMonitor(oduMonitorHeartBeat);

	//���̵߳ȴ�oduMonitor���߳̽���
	oduMonitor.join();

	delete odu;
	odu = NULL;

	system("pause");
	return 0;
}