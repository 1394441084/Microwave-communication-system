#pragma once
#include <iostream>
using namespace std;

class Father {
public:
	//�麯��
	virtual void func1() {
		cout << "����Father::func1\n";
	}
	virtual void func2() {
		cout << "����Father::func2\n";
	}
	virtual void func3() {
		cout << "����Father::func3\n";
	}

	//���麯��
	void func4() {
		cout << "���麯��:Father::func4\n";
	}
	//private:
	int X = 100;
	int Y = 200;
	static int sti;
};
int Father::sti = 66;