// weak_ptr������ӵ�ж���,���ʶ���������lock()

// ���weak_ptr����Ķ����Ƿ��Ծɴ��
// 1,����expired(),������weak_ptr���ٹ������ʱ����true
// 2,ʹ��shared_ptr���캯����weap_ptrת��Ϊһ��shared_ptr.������󲻴���,���캯���׳�bad_weak_ptr�쳣
// 3,����use_count().�������0��ʾ�������κ���Ч����

#include <iostream>
#include <memory>

using namespace std;

//int main()
//{
//	try
//	{
//		shared_ptr<string> sp(new string("hi"));
//		weak_ptr<string> wp = sp;
//		sp.reset();
//		cout << wp.use_count() << endl; // 0
//		cout << wp.expired() << endl; // 1
//		cout << boolalpha << wp.expired() << endl; // true
//		shared_ptr<string> p(wp); // throws std::bad_weak_ptr
//	}
//	catch (const std::exception& e)
//	{
//		cerr << "exception: " << e.what() << endl; // bad_weap_ptr
//	}
//}