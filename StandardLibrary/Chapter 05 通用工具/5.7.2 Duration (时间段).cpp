// Duration��һ����ֵ(����tick��)��һ������(����ʱ�䵥λ,�����)�����
// P146 duration�����������б�
// P147 duration�ṩ����������������
#include <iostream>
#include <chrono> // �������ں�ʱ��
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