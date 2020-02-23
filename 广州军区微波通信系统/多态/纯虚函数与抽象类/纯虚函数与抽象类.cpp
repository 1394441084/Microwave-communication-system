#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

//����:Abstract
class Abstract {
public:
	Abstract(const string& color = "White") { this->color = color; }
	//��ɫ
	string getcolor() { return color; }
	//��� //��area()����Ϊ���麯��
	virtual float area() = 0;//���麯��(�麯����=0������)

private:
	string color;//��ɫ
};

//԰
class Circle :public Abstract {
public:
	Circle(float rr = 0, const string& color = "White") :Abstract(color), r(rr) {}
	//�̳������Ĵ��麯��Ҫ��û�����Ļ�Ϊ������
	float area() { return 3.14 * r*r; }//�����˾��ܴ���������
private:
	float r;//�뾶
};

int main(void) {
	//Abstract k;//�д��麯������г�����,����new����,����������ֻ��������
	Circle cc;
	cout << cc.area() << endl;

	system("pause");
	return 0;
}