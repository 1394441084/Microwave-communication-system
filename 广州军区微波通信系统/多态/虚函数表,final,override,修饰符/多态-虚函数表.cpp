#include <stdlib.h>
#include "Son.h"

//�Զ��庯��ָ������
typedef void(*func_t)(void);//��������void,����void
typedef int int_32;

/*
��̬�ı��ʣ�
��ʽ�ϣ�ʹ��ͳһ�ĸ���ָ����һ���Դ���
����ʵ��ִ��ʱ�����ָ�����ָ���������
��ʽ�ϣ�ԭ�����ø���ķ���������ʵ���ϻ���������ͬ��������

��ע�⡿
����ִ��ʱ������ָ��ָ������󣬻��������ʱ������ʽ�����޷��ֱ�ģ�
ֻ��ͨ����̬���ƣ�����ִ��������Ӧ�ķ�����
*/

void �����麯������ڴ�����();
void ʹ�ü̳е��麯������ڴ�����();
void ʹ�ö��ؼ̳е��麯������ڴ�����();
void ��̬Ӧ��();
/*
final:
��class Father final{};
���������࣬�ø��಻�ܱ��̳�
��⣺ʹ�ø����սᣡ

������������麯����ʹ�ø��麯���������У����ܱ���д
��⣺ʹ�øù����սᣡ
��:virtual void func1() final;//����������

override�������������麯����//����������
���ã�
1.��ʾ������Ķ��ߣ������������д����Ĺ��ܡ�
��ֹ����Ա����д����ĺ���ʱ���Ѻ�����д��
��:void func1() override;//������������
*/

int main(void) {
	//�����麯������ڴ�����();
	//ʹ�ü̳е��麯������ڴ�����();
	ʹ�ö��ؼ̳е��麯������ڴ�����();
	//��̬Ӧ��();


	system("pause");
	return 0;
}

void �����麯������ڴ�����() {
	while (1) {
		Father father;
		//�ڴ�ֲ���
		cout << "sizeof(father) ==" << sizeof(father) << endl;
		/*
		�����ڣ����ȴ洢���ǡ��麯����ָ�롱���ֳơ����ָ�롱��
	Ȼ���ٴ洢�Ǿ�̬���ݳ�Ա��//�ĸ��ֽ�

	����ķ��麯������������Ĵ����У�
	������ڴ棬ֻ�洢�麯��������ݳ�Ա
	����ľ�̬���ݳ�Ա���������������У��Ͷ����Ƿֿ��洢�ģ�

	����麯���󣬶�����ڴ�ռ䲻�䣡���麯�����������Ŀ
	������󣬹���ͬһ���麯����
		*/
		int_32 jj = 22;
		cout << "�����ַ:" << (int*)&father << endl; \
			/*
			&father��ת��int*ָ��(int*)&father;//�������ַת��Ϊָ��
			�ٷ������������*(int*)(&father);//����ָ��ֵȡ��һ������
			ȡ��������������ת����ָ��(int*)*(int*)(&father);//���ֻ������ת��,��ֵ���޸ı�
			*/
			int* p = (int*)*(int*)(&father);
		cout << "���õ�һ���麯��:";
		((func_t) * (p + 0))();//��������ת��

		cout << "���õڶ����麯��:";
		((func_t) * (p + 1))();//��������ת��

		cout << "���õ������麯��:";
		((func_t) * (p + 2))();//��������ת��

		//cout << "���õ��ĸ��麯��:";//û�е��ĸ��麯��,�쳣
		//((func_t) * (p + 4))();//��������ת��

		cout << "��һ�����ݳ�Ա��ַ:" << endl;
		cout << &father.X << endl;
		//hex���ܽ�����ĵ�ַ��Ϊ16����
		cout << hex << (int)&father + 4 << endl;
		cout << "��һ�����ݳ�Ա��ֵ:" << endl;
		//dec���ܽ�����ĸ�Ϊ10����
		cout << dec << father.X << endl;
		//�����ַƫ���ĸ��ֽ�,ȡ��X��ַ,תΪint����,תΪָ��,����ȡֵ
		cout << *(int*)((int)&father + 4) << endl;
		/*
		�����ַָ��:
		0.�麯��ָ��(�麯����)
		1.X  (���ݳ�Ա)
		2.Y  (���ݳ�Ա)
		*/
		cout << "�ڶ������ݳ�Ա��ַ:" << endl;
		cout << &father.Y << endl;
		cout << hex << (int)&father + 8 << endl;
		cout << "�ڶ������ݳ�Ա��ֵ:" << endl;
		cout << dec << father.Y << endl;
		cout << *(int*)((int)&father + 8) << endl;
		/*
		VS�Ķ����ڴ�ֲ�������
	��Ŀ(����)����������������ӣ� /d1 reportSingleClassLayoutFather
		*/
		break;
	}
}

void ʹ�ü̳е��麯������ڴ�����() {
	while (1) {
		Son son;
		cout << "son�����ַ:" << &son << endl;
		cout << "son�����ַ:" << (int*)&son << endl;
		int* s = (int*)*(int*)&son;
		cout << "�麯����ָ��s:" << s << endl;
		//�����麯����
		for (int i = 0; i < 4; i++) {
			cout << "���õ�" << i + 1 << "���麯��:";
			((func_t) * (s + i))();
		}
		//���ö������ݳ�Ա
		for (int i = 0; i < 2; i++) {
			cout << *(int*)((int)&son + 4 + i * 4) << endl;
		}

		cout << "sizeof(son)==" << sizeof(son) << endl;
		/*
		�����ڣ����ȴ洢���ǡ��麯����ָ�롱���ֳơ����ָ�롱��
Ȼ���ٴ洢�Ǿ�̬���ݳ�Ա��

����ķ��麯������������Ĵ����У�
������ڴ棬ֻ�洢�麯��������ݳ�Ա
����ľ�̬���ݳ�Ա���������������У��Ͷ����Ƿֿ��洢�ģ�

����麯���󣬶�����ڴ�ռ䲻�䣡���麯�����������Ŀ
������󣬹���ͬһ���麯����
		*/
		break;
	}
}

void ��̬Ӧ��() {
	while (1) {
		//Father father;
		Son son;
		Father* father = &son;
		father->func1();
		/*
		������麯����Ĺ�������:
1)ֱ�Ӹ��Ƹ�����麯����
Father:func1
Father:func2
Father:func3
2)���������д�˸����ĳ���麯��
��ô��������麯�����н�����Ӧ���滻
Son::func1
Father.:func2
Father:func3
3)��������������µ��麯�����Ͱ����
�麯����ӵ��麯������(��β�����)
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

void ʹ�ö��ؼ̳е��麯������ڴ�����() {
	Son son;
	int* p = (int*)*(int*)&son;
	cout << "��һ���麯����ָ��:" << *p << endl;
	for (int i = 0; i < 4; i++) {
		cout << "���õ�" << i + 1 << "���麯��" ;
		((func_t)* (p + i))();
	}
	for (int i = 0; i < 2; i++) {
		cout << "���õ�" << i + 1 << "�����ݳ�Ա:"<<*(int*)((int)&son+4+i*4) << endl;
	}

	int* pm = (int*)*((int*)&son + 3);
	for (int i = 0; i < 3; i++) {
		cout << "���õ�" << i + 1 << "���麯��" ;
		((func_t) * (pm + i))();
	}
	for (int i = 0; i < 2; i++) {
		cout << "���õ�" << i + 1 << "�����ݳ�Ա:" << *(int*)((int)&son + 16 + i * 4) << endl;
	}
	/*
	son�����ڴ沼��:
	0.Father���
	1.���ݳ�Ա
	2.���ݳ�Ա
	3.mother���
	4.���ݳ�Ա
	5.���ݳ�Ա
	*/
	/*
	Father���{

	virtual void func1() {
		cout << "����Son::func1\n";
	}

	virtual void func2() {
		cout << "����Father::func2\n";
	}

	virtual void func3() {
		cout << "����Father::func3\n";
	}

	virtual void func5() {
		cout << "����Son::func5\n";
	}
	}
	*/

	/*
	mother���:
	void mother::handle1()
{
	cout << "����Son::handle1\n";
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