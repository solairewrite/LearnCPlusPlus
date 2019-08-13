// weak_ptr共享但不拥有对象,访问对象必须加上lock()

// 检查weak_ptr背后的对象是否仍旧存活
// 1,调用expired(),它会在weak_ptr不再共享对象时返回true
// 2,使用shared_ptr构造函数将weap_ptr转换为一个shared_ptr.如果对象不存在,构造函数抛出bad_weak_ptr异常
// 3,调用use_count().如果返回0表示不存在任何有效对象

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