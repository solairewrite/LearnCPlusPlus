// P61 pair 操作列表
#include <iostream>
#include <utility> // std::pair
#include <functional> // std::ref
#include <tuple> // std::tie

using namespace std;

// 泛型函数模板(generic function template),将pair写入stream
template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& strm, const std::pair<T1, T2>& p)
{
	return strm << "[" << p.first << "," << p.second << "]";
}

// 对pair使用tuple-like接口
void TupleLikeInterface()
{
	typedef std::pair<int, float> IntFloatPair;
	IntFloatPair p(42, 3.14);

	// 可以对pair使用tuple-like接口
	cout << std::get<0>(p) << endl; // 42
	cout << std::get<1>(p) << endl; // 3.14
	cout << std::tuple_size<IntFloatPair>::value << endl; // 2
	// 打印类型名
	cout << typeid(float).name() << endl; // float
	cout << typeid(std::tuple_element<0, IntFloatPair>::type).name() << endl; // int
}

// 便捷函数make_pair()
void Test_make_pair();

// 接受pair为实参的函数
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
	// 模板函数make_pair()无需写出类型
	std::make_pair(42, '@');

	f(std::make_pair(42, "empty"));
	g(std::make_pair(42, "chair"));

	// 也可以使用初值列
	f({ 42,"empty" });
	g({ 42,"chair" });

	// 新语义 move semantic
	std::string s, t;
	auto p = std::make_pair(std::move(s), move(t));

	// reference semantic
	int i = 0;
	auto p2 = make_pair(std::ref(i), ref(i));
	++p2.first; // .运算符优先级高
	++p2.second;
	cout << i << endl; // 2

	// 使用tie()接口,抽取pair的value
	pair<char, char> p3 = make_pair('x', 'y');
	char c;
	std::tie(std::ignore, c) = p3; // extract second value into c
	cout << c << endl; // y
}