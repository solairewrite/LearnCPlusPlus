#include <iostream>
#include <type_traits>

using namespace std;

template<typename T>
void foo(const T& val)
{
	if (std::is_pointer<T>::value)
	{
		cout << "foo() called for a pointer" << endl;
	}
	else
	{
		cout << "foo() called for a value" << endl;
	}
}

template<typename T>
void foo2_impl(const T& val, std::true_type)
{
	cout << "foo2() called for a pointer" << endl;
}

template<typename T>
void foo2_impl(const T& val, std::false_type)
{
	cout << "foo2() called for a value" << endl;
}

template<typename T>
void foo2(const T& val)
{
	foo2_impl(val, std::is_pointer<T>());
}

template<typename T1, typename T2>
void foo3(const T1& x, const T2& y)
{
	cout << boolalpha << std::is_integral<T1>() << endl;
	cout << boolalpha << std::is_integral<T2>() << endl;
	cout << endl;

	auto typename_string = typeid(string).name();
	cout << typename_string << endl;
	// class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >

	// 处理共通类型
	typename std::common_type<T1, T2> val;
	cout << typeid(val).name() << endl; // struct std::common_type<int,char [5]>
	// declval<>: 辅助性trait,依据传入的类型提供一个值,配合decltype推断类型
	auto typename_T1 = typeid(decltype(declval<T1>())).name();
	cout << typename_T1 << endl;
	cout << endl;
}

// 处理共通类型 std::common_type
template<typename T1, typename T2>
typename std::common_type<T1, T2>::type minval(const T1& x, const T2& y)
{
	return (x < y) ? x : y;
}

int main()
{
	//foo(3);
	//foo(new string("lala"));

	//foo2(3);
	//foo2(new string("lala"));

	foo3(3, "lala");

	cout << minval(10, 3.7) << endl;
}