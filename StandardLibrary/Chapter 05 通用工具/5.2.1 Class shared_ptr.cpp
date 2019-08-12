// ʾ��: util/sharedptr1.cpp
#include <memory> // std::shared_ptr
#include <string>
#include <iostream>

using namespace std;

// ����
void test_shared_ptr()
{
	// explicit���캯��
	std::shared_ptr<std::string> pNico1(new std::string("nico"));
	// ��ʽ��ʼ���﷨
	shared_ptr<string> pNico2{ new string("nico") };
	// ʹ�ñ�ݺ���make_shared()
	shared_ptr<string> pNico3 = std::make_shared<string>("nico");
	// ������,����reset()��ֵ
	shared_ptr<string> pNico4;
	pNico4.reset(new string("nico"));
}

// ����Deleter
void test_lambda_deleter()
{
	auto lamb = [](string* p) {
		cout << "delete: " << *p << endl;
		delete p;
	};

	shared_ptr<string> sp(new string("nico"), lamb);

	sp = nullptr;
}

// ����array deleter
void test_array_deleter()
{
	auto lamb = [](int* p) {
		delete[] p;
	};
	// lambda
	shared_ptr<int> p1(new int[10], lamb);
	// ���߸�������
	shared_ptr<int> p2(new int[10], std::default_delete<int[]>());
}

int main()
{
	//test_shared_ptr();

	//test_lambda_deleter();

	test_array_deleter();
}