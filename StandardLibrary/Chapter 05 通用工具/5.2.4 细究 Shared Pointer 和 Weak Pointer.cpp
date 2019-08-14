// P93 shared_ptr 的各项操作
// P97 weak_ptr 的所有操作

#include <memory>
#include <iostream>

using namespace std;

void test_get_deleter()
{
	auto del = [](int* p) {
		delete p;
	};
	std::shared_ptr<int> p(new int, del);
	decltype(del)* pd = std::get_deleter<decltype(del)>(p);
}

void test_aliasing_constructor()
{
	struct X
	{
		X(int a) :a(a)
		{
		};
		int a;
	};
	shared_ptr<X> px(new X(3));
	shared_ptr<int> pi(px, &px->a);

	cout << px->a << endl;
	cout << px.use_count() << endl;
}

void test_pointer_cast()
{
	// 内部维护void*
	shared_ptr<void> sp(new int);
	shared_ptr<int*> pi = static_pointer_cast<int*>(sp);
}

//int main()
//{
//	//test_get_deleter();
//
//	//test_aliasing_constructor();
//
//	test_pointer_cast();
//}