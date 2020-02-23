#pragma once
#include "Father.h"
#include "mother.h"

class Son :public Father, public mother {
public:
	//子类的虚函数virtual可加可不加,编译器会自动生成
	void func1() {
		cout << "调用Son::func1\n";
	}
	virtual void handle1() { cout << "调用Son::handle1\n"; }
	//子类的虚函数:先复制父类的虚函数表,再修改子类重写同名的函数,再增加子类所添加的虚函数
	virtual void func5() {
		cout << "调用Son::func5\n";
	}

	//private:

};