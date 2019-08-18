// 示例: util/ratio1.cpp
// P141 ratio<>的各种运算列表
#include <ratio>
#include <iostream>

using namespace std;

int main()
{
	typedef ratio<5, 3> FiveThirds;
	cout << FiveThirds::num << "/" << FiveThirds::den << endl; // 5/3

	typedef ratio<25, 15> AlsoFiveThirds;
	cout << AlsoFiveThirds::num << "/" << AlsoFiveThirds::den << endl; // 5/3

	ratio<42, 42> one;
	cout << one.num << "/" << one.den << endl; // 1/1

	ratio<0> zero;
	cout << zero.num << "/" << zero.den << endl; // 0/1

	typedef ratio<7, -3> Neg;
	cout << Neg::num << "/" << Neg::den << endl; // -7/3

	auto ratio_typename = typeid(std::ratio_add<ratio<2, 7>, ratio<2, 6>>::type).name();
	cout << ratio_typename << endl; // struct std::ratio<13,21>

	auto isRatioEqual = ratio_equal<ratio<5, 3>, ratio<25, 15>>::value;
	cout << "ratio_equal: " << boolalpha << isRatioEqual << endl; // true
}