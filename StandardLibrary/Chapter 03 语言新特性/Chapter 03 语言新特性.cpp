#include <iostream>
#include <vector>
#include <set>

using namespace std;

void UniformInitialization();
void print(std::initializer_list<int> vals);
void RangeBasedFor();

template<typename T>
void printElements(const T& coll);

void MoveSemanticRvalueReference();
void StringLiteral();

int main()
{
	//UniformInitialization();

	// 使用自定义初值列
	//print({12,3,5,7});

	//RangeBasedFor();

	// 调用泛型函数
	//std::vector<int> vec{ 1,4,6 };
	//printElements(vec);

	//MoveSemanticRvalueReference();

	StringLiteral();
}

// 一致性初始化
void UniformInitialization()
{
	// 面对任何初始化动作,可以使用相同语法,也就是使用大括号
	int values[]{ 1,2,3 };
	std::vector<int> v{ 2,3,5 };
	// 初值列 initializer list, 变量被初始化为0或nullptr
	int j{}; // 初始化为0
	int* q{}; // 初始化为nullptr
}

// 自定义初值列 std::initializer_list<>
void print(std::initializer_list<int> vals)
{
	for (auto p = vals.begin(); p != vals.end(); ++p)
	{
		cout << *p << "\n";
	}
}

// 迭代
void RangeBasedFor()
{
	for (int i : {2, 3, 5, 7})
	{
		//cout << i << std::endl;
	}

	std::vector<double> vec{ 1,2,3 };
	// 声明elem为引用很重要,若不这么做,for循环中的语句会作用在元素的一份local copy身上
	for (auto& elem : vec)
	{
		elem *= 3;
		cout << elem << std::endl;
	}
}

// 泛型函数
template<typename T>
void printElements(const T& coll)
{
	for (const auto& elem : coll)
	{
		cout << elem << std::endl;
	}
}

// Move语义和Rvalue Reference
void MoveSemanticRvalueReference()
{
	int i = 6, j = 7;
	std::set<int> set;

	// X&&是一种新类型,表示变量不会被使用,可以直接移动,而不用创建副本
	// std::move(x)将x转为X&&类型
	set.insert(std::move(i));
	set.insert(std::move(j));

	printElements(set);
}

// 字符串字面常量
void StringLiteral()
{
	// Raw string,转义字符为纯字符, R"( ... )"
	auto rstring = R"(\\n)";
	cout << rstring << "\n";
	
	// 编码前缀encoding prefix,为string literal定义字符编码
	// u8: UTF-8
	// L: wide string literal, wchar_t. 注意要使用wcout输出
	cout << u8"UTF8-encoding" << endl;
	std::wcout << L"wide string literal, wchar_t" << endl;
}