// P61 pair �����б�
#include <iostream>
#include <utility> // std::pair
#include <functional> // std::ref
#include <tuple> // std::tie

using namespace std;

// ���ͺ���ģ��(generic function template),��pairд��stream
template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& strm, const std::pair<T1, T2>& p)
{
	return strm << "[" << p.first << "," << p.second << "]";
}

// ��pairʹ��tuple-like�ӿ�
void TupleLikeInterface()
{
	typedef std::pair<int, float> IntFloatPair;
	IntFloatPair p(42, 3.14);

	// ���Զ�pairʹ��tuple-like�ӿ�
	cout << std::get<0>(p) << endl; // 42
	cout << std::get<1>(p) << endl; // 3.14
	cout << std::tuple_size<IntFloatPair>::value << endl; // 2
	// ��ӡ������
	cout << typeid(float).name() << endl; // float
	cout << typeid(std::tuple_element<0, IntFloatPair>::type).name() << endl; // int
}

// ��ݺ���make_pair()
void Test_make_pair();

// ����pairΪʵ�εĺ���
void f(std::pair<int, const char*>) {};
void g(std::pair<const int, std::string>) {};

//int main()
//{
//	//TupleLikeInterface();
//
//	Test_make_pair();
//}

void Test_make_pair()
{
	std::pair<int, char>(42, '@');
	// ģ�庯��make_pair()����д������
	std::make_pair(42, '@');

	f(std::make_pair(42, "empty"));
	g(std::make_pair(42, "chair"));

	// Ҳ����ʹ�ó�ֵ��
	f({ 42,"empty" });
	g({ 42,"chair" });

	// ������ move semantic
	std::string s, t;
	auto p = std::make_pair(std::move(s), move(t));

	// reference semantic
	int i = 0;
	auto p2 = make_pair(std::ref(i), ref(i));
	++p2.first; // .��������ȼ���
	++p2.second;
	cout << i << endl; // 2

	// ʹ��tie()�ӿ�,��ȡpair��value
	pair<char, char> p3 = make_pair('x', 'y');
	char c;
	std::tie(std::ignore, c) = p3; // extract second value into c
	cout << c << endl; // y
}