// Tuple 不定数的值组, P71 tuple操作列表
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

// 便捷函数make_tuple()
void test_make_tuple()
{
	make_tuple(22, 44, "nico");

	string s("s");
	auto x = std::make_tuple(s);
	std::get<0>(x) = "valueX"; // 修改了x,但是没有修改s
	cout << get<0>(x) << " " << s << endl;

	auto y = make_tuple(std::ref(s));
	std::get<0>(y) = "valueY"; // 修改了s
	cout << get<0>(y) << " " << s << endl;
}

int main()
{
	//TestTuple();

	test_make_tuple();
}