#pragma once
#include "Father.h"
#include "mother.h"

class Son :public Father, public mother {
public:
	//������麯��virtual�ɼӿɲ���,���������Զ�����
	void func1() {
		cout << "����Son::func1\n";
	}
	virtual void handle1() { cout << "����Son::handle1\n"; }
	//������麯��:�ȸ��Ƹ�����麯����,���޸�������дͬ���ĺ���,��������������ӵ��麯��
	virtual void func5() {
		cout << "����Son::func5\n";
	}

	//private:

};