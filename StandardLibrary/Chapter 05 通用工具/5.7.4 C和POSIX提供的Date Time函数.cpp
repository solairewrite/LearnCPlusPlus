// P158 <ctime>�ж������
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main()
{
	// 5.7.5 �Լ�ʱ��ͣ���߳� (Blocking with Timer)
	cout << "begin" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(3));
	cout << "end" << endl;
}