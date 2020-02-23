#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

//抽象:Abstract
class Abstract {
public:
	Abstract(const string& color = "White") { this->color = color; }
	//颜色
	string getcolor() { return color; }
	//面积 //把area()定义为纯虚函数
	virtual float area() = 0;//纯虚函数(虚函数加=0就是了)

private:
	string color;//颜色
};

//园
class Circle :public Abstract {
public:
	Circle(float rr = 0, const string& color = "White") :Abstract(color), r(rr) {}
	//继承下来的纯虚函数要是没重做的话为抽象类
	float area() { return 3.14 * r*r; }//重做了就能创建对象了
private:
	float r;//半径
};

int main(void) {
	//Abstract k;//有纯虚函数的类叫抽像类,不能new对象,抽象类作用只派生子类
	Circle cc;
	cout << cc.area() << endl;

	system("pause");
	return 0;
}