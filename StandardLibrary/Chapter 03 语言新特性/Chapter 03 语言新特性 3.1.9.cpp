#include <iostream>
#include <bitset>
#include <vector>
#include <functional>
#include <map>

using namespace std;

void print()
{

}

// variadic template: ��������,���Ͳ�����ʵ��
template<typename T, typename... Types>
void print(const T& firstArg, const Types& ... args)
{
	cout << firstArg << endl;
	// �����ṩ��ģ�����غ���print(),���ܽ��������ݹ����
	print(args...);
}

// Lambda: ����inline�����Ķ���ʽ������һ������,����һ��local����
void Lambda()
{
	// ��С�͵�lambda����û�в���,ʲôҲ����
	[] {
		cout << "hello lambda 1" << endl;;
	};

	// ֱ�ӵ���
	[] {
		cout << "hello lambda 2" << endl;
	}();

	// ���ݸ�����
	auto lambda1 = [] {
		cout << "hello lambda 3" << endl;
	};
	lambda1();

	// ����
	auto lambda2 = [](const std::string& s) {
		cout << s << endl;
	};
	lambda2("hello lambda 4");

	// ����ֵ,�Զ��Ƶ�
	[] {
		return 42;
	};

	// ����ֵ,ָ��
	[]()->double {
		return 42;
	};

}

void Lambda2()
{
	int x = 0;
	int y = 42;
	// []�ڷ����ⲿ������, =��ʾ��ֵ�ķ�ʽ����, &��ʾ�����õķ�ʽ����
	// ����x��ֵ����0,��ʹ�����x���¸�ֵ
	auto qqq = [x, &y] {
		cout << "x: " << x << endl;
		cout << "y: " << y << endl;
		++y;
	};
	x = y = 77;
	qqq(); // x: 0, y: 77
	qqq(); // x: 0, y: 78
	cout << "final y:" << y << endl; // y: 79
}

void Lambda3()
{
	int id = 0;
	// mutableʹlambdaͨ����ֵ�ʹ������û��
	auto f = [id]()mutable {
		// ����id��ͨ��ֵ���ݵ�,���ǿ����޸�,�����ı��ⲿ��idֵ
		cout << "id: " << id << endl;
		++id;
	};
	id = 42;
	f(); // id: 0
	f(); // id: 1
	f(); // id: 2
	cout << id << endl; // id: 42
}

// �����ķ�������Ϊlambda
std::function<int(int, int)> returnLambda()
{
	return [](int x, int y) {
		return x * y;
	};
}

// �ؼ��� decltype: �ñ������ҳ����ʽ����
void decltypeTest()
{
	std::map<std::string, float> coll;
	decltype(coll)::value_type elem;
}

// �µĺ��������﷨,�������ķ�������ת�������ڲ�����֮��
template<typename T1, typename T2>
auto add(T1 x, T2 y) -> decltype(x + y)
{
	return x + y;
}

/**
int main()
{
	//print(7.5, "hello", std::bitset<16>(377), 42);

	//Lambda();
	//Lambda2();
	//Lambda3();

	//auto lf = returnLambda();
	//cout << lf(6, 7) << endl; // 42

	//decltypeTest();

	cout << int('b') << endl;
	cout << add('b', 1.2f) << endl;

	//system("pause");
}
*/