#include <stdlib.h>
#include "Son.h"

//自定义函数指针类型
typedef void(*func_t)(void);//返回类型void,参数void
typedef int int_32;

/*
多态的本质：
形式上，使用统一的父类指针做一般性处理，
但是实际执行时，这个指针可能指向子类对象，
形式上，原本调用父类的方法，但是实际上会调用子类的同名方法。

【注意】
程序执行时，父类指针指向父类对象，或子类对象时，在形式上是无法分辨的！
只有通过多态机制，才能执行真正对应的方法。
*/

void 单类虚函数表的内存刨析();
void 使用继承的虚函数表的内存刨析();
void 使用多重继承的虚函数表的内存刨析();
void 多态应用();
/*
final:
如class Father final{};
用来修饰类，让该类不能被继承
理解：使得该类终结！

用来修饰类的虚函数，使得该虚函数在子类中，不能被重写
理解：使得该功能终结！
如:virtual void func1() final;//声明中修饰

override仅能用于修饰虚函数。//声明中修饰
作用：
1.提示程序的阅读者，这个函数是重写父类的功能。
防止程序员在重写父类的函数时，把函数名写错。
如:void func1() override;//无其它作用了
*/

int main(void) {
	//单类虚函数表的内存刨析();
	//使用继承的虚函数表的内存刨析();
	使用多重继承的虚函数表的内存刨析();
	//多态应用();


	system("pause");
	return 0;
}

void 单类虚函数表的内存刨析() {
	while (1) {
		Father father;
		//内存分布刨
		cout << "sizeof(father) ==" << sizeof(father) << endl;
		/*
		对象内，首先存储的是“虚函数表指针”，又称“虚表指针”。
	然后再存储非静态数据成员。//四个字节

	对象的非虚函数，保存在类的代码中！
	对象的内存，只存储虚函数表和数据成员
	（类的静态数据成员，保存在数据区中，和对象是分开存储的）

	添加虚函数后，对象的内存空间不变！仅虚函数表中添加条目
	多个对象，共享同一个虚函数表！
		*/
		int_32 jj = 22;
		cout << "对象地址:" << (int*)&father << endl; \
			/*
			&father需转成int*指针(int*)&father;//将对象地址转换为指针
			再访问里面的内容*(int*)(&father);//根据指针值取出一个数组
			取出的是整数需再转换成指针(int*)*(int*)(&father);//最后只是类型转换,对值并无改变
			*/
			int* p = (int*)*(int*)(&father);
		cout << "调用第一个虚函数:";
		((func_t) * (p + 0))();//进行类型转换

		cout << "调用第二个虚函数:";
		((func_t) * (p + 1))();//进行类型转换

		cout << "调用第三个虚函数:";
		((func_t) * (p + 2))();//进行类型转换

		//cout << "调用第四个虚函数:";//没有第四个虚函数,异常
		//((func_t) * (p + 4))();//进行类型转换

		cout << "第一个数据成员地址:" << endl;
		cout << &father.X << endl;
		//hex是能将下面的地址改为16进制
		cout << hex << (int)&father + 4 << endl;
		cout << "第一个数据成员的值:" << endl;
		//dec是能将下面的改为10进制
		cout << dec << father.X << endl;
		//对象地址偏移四个字节,取出X地址,转为int类型,转为指针,解引取值
		cout << *(int*)((int)&father + 4) << endl;
		/*
		对象地址指向:
		0.虚函数指针(虚函数表)
		1.X  (数据成员)
		2.Y  (数据成员)
		*/
		cout << "第二个数据成员地址:" << endl;
		cout << &father.Y << endl;
		cout << hex << (int)&father + 8 << endl;
		cout << "第二个数据成员的值:" << endl;
		cout << dec << father.Y << endl;
		cout << *(int*)((int)&father + 8) << endl;
		/*
		VS的对象内存分布分析：
	项目(属性)的命令行配置中添加： /d1 reportSingleClassLayoutFather
		*/
		break;
	}
}

void 使用继承的虚函数表的内存刨析() {
	while (1) {
		Son son;
		cout << "son对象地址:" << &son << endl;
		cout << "son对象地址:" << (int*)&son << endl;
		int* s = (int*)*(int*)&son;
		cout << "虚函数表指针s:" << s << endl;
		//调用虚函数表
		for (int i = 0; i < 4; i++) {
			cout << "调用第" << i + 1 << "个虚函数:";
			((func_t) * (s + i))();
		}
		//调用对象数据成员
		for (int i = 0; i < 2; i++) {
			cout << *(int*)((int)&son + 4 + i * 4) << endl;
		}

		cout << "sizeof(son)==" << sizeof(son) << endl;
		/*
		对象内，首先存储的是“虚函数表指针”，又称“虚表指针”。
然后再存储非静态数据成员。

对象的非虚函数，保存在类的代码中！
对象的内存，只存储虚函数表和数据成员
（类的静态数据成员，保存在数据区中，和对象是分开存储的）

添加虚函数后，对象的内存空间不变！仅虚函数表中添加条目
多个对象，共享同一个虚函数表！
		*/
		break;
	}
}

void 多态应用() {
	while (1) {
		//Father father;
		Son son;
		Father* father = &son;
		father->func1();
		/*
		子类的虚函数表的构建过程:
1)直接复制父类的虚函数表
Father:func1
Father:func2
Father:func3
2)如果子类重写了父类的某个虚函数
那么就在这个虚函数表中进行相应的替换
Son::func1
Father.:func2
Father:func3
3)如果子类增加了新的虚函数，就把这个
虚函数添加到虚函数表中(在尾部添加)
Son::func1
Father.func2
Father:func3
Son::func5
		*/
		//Son ez;
		//mother* mm=(mother*)&ez;
		//mm->handle1;


		break;
	}
}

void 使用多重继承的虚函数表的内存刨析() {
	Son son;
	int* p = (int*)*(int*)&son;
	cout << "第一个虚函数表指针:" << *p << endl;
	for (int i = 0; i < 4; i++) {
		cout << "调用第" << i + 1 << "个虚函数" ;
		((func_t)* (p + i))();
	}
	for (int i = 0; i < 2; i++) {
		cout << "调用第" << i + 1 << "个数据成员:"<<*(int*)((int)&son+4+i*4) << endl;
	}

	int* pm = (int*)*((int*)&son + 3);
	for (int i = 0; i < 3; i++) {
		cout << "调用第" << i + 1 << "个虚函数" ;
		((func_t) * (pm + i))();
	}
	for (int i = 0; i < 2; i++) {
		cout << "调用第" << i + 1 << "个数据成员:" << *(int*)((int)&son + 16 + i * 4) << endl;
	}
	/*
	son对象内存布局:
	0.Father虚表
	1.数据成员
	2.数据成员
	3.mother虚表
	4.数据成员
	5.数据成员
	*/
	/*
	Father虚表{

	virtual void func1() {
		cout << "调用Son::func1\n";
	}

	virtual void func2() {
		cout << "调用Father::func2\n";
	}

	virtual void func3() {
		cout << "调用Father::func3\n";
	}

	virtual void func5() {
		cout << "调用Son::func5\n";
	}
	}
	*/

	/*
	mother虚表:
	void mother::handle1()
{
	cout << "调用Son::handle1\n";
}

void mother::handle2()
{
	cout << "mother::handle2" << endl;
}

void mother::handle3()
{
	cout << "mother::handle3" << endl;
}
	*/
}