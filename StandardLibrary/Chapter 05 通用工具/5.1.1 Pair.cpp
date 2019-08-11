// P61 struct pair 操作函数列表
#include <iostream>
#include <utility>

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

int main()
{
	TupleLikeInterface();
}