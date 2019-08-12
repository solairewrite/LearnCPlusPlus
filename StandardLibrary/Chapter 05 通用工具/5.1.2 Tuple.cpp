// Tuple ��������ֵ��, P71 tuple�����б�
#include <iostream>
#include <tuple>
#include <string>
#include <functional> // std::ref()

using namespace std;

void TestTuple()
{
	tuple<string, int, float> t;
	tuple<int, float, string> t1(41, 6.3, "nico");

	cout << get<0>(t1) << " ";
	cout << get<1>(t1) << " ";
	cout << get<2>(t1) << " ";
	cout << endl;

	auto t2 = make_tuple(22, 44, "nico");

	get<1>(t1) = get<1>(t2);

	if (t1 < t2)
	{
		t1 = t2;
	}
}

// ��ݺ���make_tuple()
void test_make_tuple()
{
	make_tuple(22, 44, "nico");

	string s("s");
	auto x = std::make_tuple(s);
	std::get<0>(x) = "valueX"; // �޸���x,����û���޸�s
	cout << get<0>(x) << " " << s << endl;

	auto y = make_tuple(std::ref(s));
	std::get<0>(y) = "valueY"; // �޸���s
	cout << get<0>(y) << " " << s << endl;
}

// ��������,����make_tuple,�Ϳ�����ȡtuple��Ԫ��ֵ,��ĳЩ����ֵ�������
void test_ref_make_tuple()
{
	std::tuple<int, float, std::string> t(77, 1.1, "more light");
	int i;
	float f;
	std::string s;
	// ��t��ֵ���i,f,s
	std::make_tuple(std::ref(i), ref(f), ref(s)) = t;

	cout << i << "\t" << f << "\t" << s << endl;

	i = 8;
	cout << i << "\t" << get<0>(t) << endl; // 8	77

	get<1>(t) = 1.2f;
	cout << f << "\t" << get<1>(t) << endl; // 1.1	1.2
}

// tie()�����ں�reference��tuple
void test_tie()
{
	std::tuple<int, float, std::string> t(77, 1.1, "more light");
	int i, i2;
	float f;
	std::string s, s2;
	// ��t��ֵ���i,f,s
	std::tie(i, f, s) = t;
	cout << i << "\t" << f << "\t" << s << endl;

	// ʹ��std::ignore����ĳЩԪ��
	std::tie(i2, std::ignore, s2) = t;
	cout << i2 << endl << s2 << endl;
}

// ��ֵ��
void test_initializer_list()
{
	std::tuple<int, double> t1(42, 3.14); // old syntax
	tuple<int, double> t2{ 42,3.14 }; // new syntax
}

// tuple����
void test_tuple_func()
{
	typedef std::tuple<int, float, std::string> TupleType;

	// ���Ԫ�ظ���
	cout << std::tuple_size<TupleType>::value << endl;
	// ���Ԫ������
	cout << typeid(std::tuple_element<1, TupleType>::type).name() << endl;
	// ƴ�Ӷ��tuple
	int n;
	auto tt = std::tuple_cat(std::make_tuple(42, 7.7), std::tie(n));
}

int main()
{
	//TestTuple();

	//test_make_tuple();

	//test_ref_make_tuple();

	//test_tie();

	//test_initializer_list();

	test_tuple_func();
}