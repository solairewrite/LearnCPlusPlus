//#include <chrono>
//#include <ctime> // std::ctime
//#include <string>
//#include <iostream>
//
//using namespace std;
//
//string asString(const chrono::system_clock::time_point& tp)
//{
//	// תΪsystem time
//	std::time_t t = chrono::system_clock::to_time_t(tp);
//	// תΪ������ʾ��
//	string ts = std::asctime(gmtime(&t));
//	// ����ĩβ������
//	ts.resize(ts.size() - 1);
//	return ts;
//}
//
//int main()
//{
//	// time_pointĬ�Ϲ��캯��Ϊepoch
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