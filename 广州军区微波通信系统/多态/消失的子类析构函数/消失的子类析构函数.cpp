#include <iostream>
#include <Windows.h>
#include <string.h>

using namespace std;

class Father {
public:
	Father(const char* addr = "中国") {
		cout << "执行了Father的构造函数" << endl;
		int len = strlen(addr) + 1;
		this->addr = new char[len];
		strcpy_s(this->addr, len, addr);
	}

	// 把Father类的析构函数定义为virtual函数时，
	// 如果对 Father类的指针使用delete操作时，
	// 就会对该指针使用“动态析构”：
	// 如果这个指针，指向的是子类对象，
	// 那么会先调用该子类的析构函数，再调用自己类的析构函数
	virtual ~Father() {
		cout << "执行了Father的析构函数" << endl;
		if (addr) {
			delete addr;
			addr = NULL;
		}
	}
private:
	char* addr;
};

class Son :public Father {
public:
	Son(const char* game = "吃鸡", const char* addr = "中国")
		:Father(addr) {
		cout << "执行了Son的构造函数" << endl;
		int len = strlen(game) + 1;
		this->game = new char[len];
		strcpy_s(this->game, len, game);
	}
	~Son() {
		cout << "执行了Son的析构函数" << endl;
		if (game) {
			delete game;
			game = NULL;
		}
	}
private:
	char* game;
};

int main(void) {
	cout << "----- case 1 -----" << endl;
	Father* father = new Father();
	delete father;

	cout << "----- case 2 -----" << endl;
	Son* son = new Son();
	delete son;

	cout << "----- case 3 -----" << endl;
	father = new Son();
	delete father;

	system("pause");
	return 0;
}