#pragma once
#include <iostream>
using namespace std;

class Father {
public:
	//虚函数
	virtual void func1() {
		cout << "调用Father::func1\n";
	}
	virtual void func2() {
		cout << "调用Father::func2\n";
	}
	virtual void func3() {
		cout << "调用Father::func3\n";
	}

	//非虚函数
	void func4() {
		cout << "非虚函数:Father::func4\n";
	}
	//private:
	int X = 100;
	int Y = 200;
	static int sti;
};
int Father::sti = 66;