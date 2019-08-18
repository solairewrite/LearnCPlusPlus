// std::function<>�ṩ��̬�⸲��,���Ը���function pointer�Ǻ�
// ͨ������ָ����ú���
// ����ָ������ָ��һ������,�������Ǻ��������ڵ�ַ
#include <iostream>
#include <functional> // std::function
#include <vector>

using namespace std;

void func(int x, int y)
{
	cout << "func(" << x << ", " << y << ") = " << x + y << endl;
}

class C
{
public:
	void memfunc(int x, int y) const
	{
		cout << "C::memfunc(" << x << ", " << y << ") = " << x + y << endl;
	}
};

int main()
{
	auto lam = [](int x, int y) {
		cout << "lam(" << x << ", " << y << ") = " << x + y << endl;
	};

	// ����������������,����ִ��
	std::vector<std::function<void(int, int)>> tasks;
	tasks.push_back(func);
	tasks.push_back(lam);

	for (std::function<void(int, int)> f : tasks)
	{
		f(33, 66);
	}
	cout << endl;

	// ��Ա�����ĵ��ö���,������Ϊ��һ��ʵ��
	std::function<void(const C&, int, int)> mf;
	mf = &C::memfunc;
	mf(C(), 42, 77);
}