#include <iostream>
#include <vector>

using namespace std;

// Scoped Enumeration
// enum��ָ���ؼ���class
// ������ʽת����/��int, ������ʾָ���ײ�����(������char),Ĭ��int
// ����������,дΪ Salutation::mr
enum class Salutation :char
{
	mr,
	ms,
	co,
	none,
};

// Class Template ����ӵ��Ĭ��ʵ��,����ǰһ��ʵ��Ϊ���ݶ�����
template<typename T, typename container = vector<T>>
class MyClass
{

};

// typename: ָ�����������Ǹ�����
template<typename T>
class TypenameClass
{
public:

	TypenameClass()
	{
		ptr = nullptr;
	};

	// typename����SubType�Ǹ�����
	// ����typename,SubType�ᱻ��Ϊstatic��Ա
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
	cout << *x.ptr << endl; // ��������ȼ� "." > "*"
	cout << x.ptr << endl;

	system("pause");
}

// ��Աģ��
template<typename T>
class MemberTemplateClass
{
private:
	T value;
public:
	// ��Աģ��,����������벻ͬ��ģ������
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