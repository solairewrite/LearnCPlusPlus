// P158 <ctime>中定义的项
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main()
{
	// 5.7.5 以计时器停滞线程 (Blocking with Timer)
	cout << "begin" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(3));
	cout << "end" << endl;
}