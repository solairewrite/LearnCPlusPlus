#include <iostream>
#include <vector>

using namespace std;

// Scoped Enumeration
// enum后指明关键字class
// 不会隐式转换至/自int, 可以显示指定底层类型(这里是char),默认int
// 在作用域外,写为 Salutation::mr
enum class Salutation :char
{
	mr,
	ms,
	co,
	none,
};

// Class Template 可以拥有默认实参,以其前一个实参为依据而定义
template<typename T, typename container = vector<T>>
class MyClass
{

};

// typename: 指明紧跟其后的是个类型
template<typename T>
class TypenameClass
{
public:

	TypenameClass()
	{
		ptr = nullptr;
	};

	// typename表明SubType是个类型
	// 不加typename,SubType会被视为static成员
	typename T::SubType* ptr;
};

class Q
{
public:
	typedef int SubType;
};

void typenameTest()
{
	TypenameClass<Q> x;
	int i = 5;
	x.ptr = &i;
	cout << *x.ptr << endl; // 运算符优先级 "." > "*"
	cout << x.ptr << endl;

	system("pause");
}

// 成员模板
template<typename T>
class MemberTemplateClass
{
private:
	T value;
public:
	// 成员模板,允许参数传入不同的模板类型
	template<typename X>
	void assign(const MemberTemplateClass<X>& x)
	{
		value = x.getValue();
	}
	T getValue() const
	{
		return value;
	}
};

void MemberTemplateTest()
{
	MemberTemplateClass<double> d;
	MemberTemplateClass<int> i;
	d.assign(d);
	d.assign(i);
}

int main()
{
	//MyClass<int> x1;

	//typenameTest();

	MemberTemplateTest();


	system("pause");
}