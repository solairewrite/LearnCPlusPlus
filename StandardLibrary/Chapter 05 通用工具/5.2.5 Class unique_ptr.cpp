#include <iostream>
#include <memory>

using namespace std;

void test_unique_ptr()
{
	// ����ֱ�ӳ�ʼ��
	std::unique_ptr<std::string> up(new std::string("nico"));

	(*up)[0] = 'N';
	up->append("lai");
	cout << *up << endl;

	// ��һ��ӵ�ж���,������empty
	up = nullptr;
	up.reset();

	// ����release(),���unique_ptrӵ�еĶ��󲢷���ӵ��Ȩ
	unique_ptr<string> up2(new string("nico"));
	string* sp = up2.release();

	unique_ptr<string> up3(new string("nico3"));
	// ʹ�ò�����bool()����Ƿ�ӵ�ж���
	if (up3)
	{
		cout << "bool(up3)\t" << *up3 << endl;
	}
	if (up3 != nullptr)
	{
		cout << "up3 != nullptr" << endl;
	}
	if (up3.get() != nullptr)
	{
		cout << "up3.get() != nullptr" << endl;
	}
}

int main()
{
	test_unique_ptr();
}