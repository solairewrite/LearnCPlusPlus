//#include <chrono>
//#include <ctime> // std::ctime
//#include <string>
//#include <iostream>
//
//using namespace std;
//
//string asString(const chrono::system_clock::time_point& tp)
//{
//	// 转为system time
//	std::time_t t = chrono::system_clock::to_time_t(tp);
//	// 转为日历表示法
//	string ts = std::asctime(gmtime(&t));
//	// 跳过末尾的新行
//	ts.resize(ts.size() - 1);
//	return ts;
//}
//
//int main()
//{
//	// time_point默认构造函数为epoch
//	chrono::system_clock::time_point tp;
//	cout << "epoch:\t" << asString(tp) << endl;
//
//	// current time
//	tp = chrono::system_clock::now();
//	cout << "now:\t" << asString(tp) << endl;
//
//	// minimun time
//	tp = chrono::system_clock::time_point::min();
//	cout << "min:\t" << asString(tp) << endl;
//}