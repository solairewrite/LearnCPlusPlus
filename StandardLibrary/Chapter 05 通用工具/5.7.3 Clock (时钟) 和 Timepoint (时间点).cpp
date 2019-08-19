// P149 Clock提供的操作和类型列表
// 示例: util/clock1.cpp
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
	// 时间单位是否小于毫秒
	typedef typename C::period P; // 时间单位类型
	if (ratio_less_equal<P, milli>::value)
	{
		// 转为毫秒并打印
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
		// 1毫秒最多进行 492851 次 i++
		// 50万次/ms,5亿次/s
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