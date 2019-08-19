// P149 Clock�ṩ�Ĳ����������б�
// ʾ��: util/clock1.cpp
#include <iostream>
#include <chrono>
#include <iomanip>
#include <limits>

using namespace std;
using namespace std::chrono;

template<typename C>
void printClockData()
{
	cout << "- precision: ";
	// ʱ�䵥λ�Ƿ�С�ں���
	typedef typename C::period P; // ʱ�䵥λ����
	if (ratio_less_equal<P, milli>::value)
	{
		// תΪ���벢��ӡ
		typedef typename ratio_multiply<P, kilo>::type TT;
		cout << fixed << double(TT::num) / (TT::den)
			<< " milliseconds" << endl;
	}
	else
	{
		cout << fixed << double(P::num) / P::den
			<< " seconds" << endl;
	}
	cout << "- is_steady: " << boolalpha << C::is_steady << endl;
}

void test_print_clock()
{
	cout << "system_clock: " << endl;
	printClockData<system_clock>();
	cout << "\nhigh_resolution_clock: " << endl;
	printClockData<high_resolution_clock>();
	cout << "\nsteady_clock: " << endl;
	printClockData<steady_clock>();
}

void test_timepoint()
{
	auto system_start = system_clock::now();

	for (int i = 1; i < 492851; i++)
	{
		// 1���������� 492851 �� i++
		// 50���/ms,5�ڴ�/s
	}

	auto diff = system_clock::now() - system_start;
	if (diff > milliseconds(1))
	{
		cout << "system life > 1 millisec" << endl;
	}

	auto microsec = duration_cast<microseconds>(diff);
	cout << "program runs: " << microsec.count() << " microseconds" << endl;
}

int main()
{
	//test_print_clock();
	test_timepoint();
}