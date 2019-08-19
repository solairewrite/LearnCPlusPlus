// Duration是一个数值(表现tick数)和一个分数(表现时间单位,以秒记)的组合
// P146 duration的算术运算列表
// P147 duration提供的其他操作和类型
#include <iostream>
#include <chrono> // 处理日期和时间
#include <iomanip> // setfill

using namespace std;
using namespace std::chrono;

void test_duration_calc()
{
	std::chrono::seconds d1(42);
	std::chrono::milliseconds d2(10);
	auto d3 = d1 - d2;
	cout << "tick: " << d3.count() << endl;
	cout << "unit: " << typeid(decltype(d3)::period).name() << endl;
	cout << "seconds: " << duration_cast<seconds>(d3).count() << endl;
}

void test_duration_unit()
{
	seconds twentySeconds(20);
	hours aDay(24);
	milliseconds ms(0);

	ms += twentySeconds + aDay;
	--ms;
	ms *= 2;
	cout << ms.count() << " ms" << endl;
	cout << nanoseconds(ms).count() << " ns" << endl;
}

template <typename V, typename R>
ostream& operator<<(ostream& s, const chrono::duration<V, R>& d)
{
	s << "[" << d.count() << " of " << R::num << "/" << R::den << "]";
	return s;
}

void test_operator_overload()
{
	milliseconds d(42);
	cout << d << endl;
}

void test_duration_cast()
{
	milliseconds ms(7255042);

	hours hh = duration_cast<hours>(ms);
	minutes mm = duration_cast<minutes>(ms % hours(1));
	seconds ss = duration_cast<seconds>(ms % minutes(1));
	milliseconds msec = duration_cast<milliseconds>(ms % seconds(1));

	cout << "raw:\t" 
		<< hh << "::" 
		<< mm << "::" 
		<< ss << "::" 
		<< msec << endl;

	cout << "\t" << setfill('0')
		<< setw(2) << hh.count() << "::"
		<< setw(2) << mm.count() << "::"
		<< setw(2) << ss.count() << "::"
		<< setw(3) << msec.count() << endl;
}

//int main()
//{
//	//test_duration_calc();
//	//test_duration_unit();
//	//test_operator_overload();
//	test_duration_cast();
//}