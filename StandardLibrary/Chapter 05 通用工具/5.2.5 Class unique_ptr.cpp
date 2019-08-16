#include <iostream>
#include <memory>

using namespace std;

void test_unique_ptr()
{
	// 必须直接初始化
	std::unique_ptr<std::string> up(new std::string("nico"));

	(*up)[0] = 'N';
	up->append("lai");
	cout << *up << endl;

	// 不一定拥有对象,可以是empty
	up = nullptr;
	up.reset();

	// 调用release(),获得unique_ptr拥有的对象并放弃拥有权
	unique_ptr<string> up2(new string("nico"));
	string* sp = up2.release();

	unique_ptr<string> up3(new string("nico3"));
	// 使用操作符bool()检查是否拥有对象
	if (up3)
	{
		cout << "bool(up3)\t" << *up3 << endl;
	}
	if (up3 != nullptr)
	{
		cout << "up3 != nullptr" << endl;
	}
	if (up3.get() != nullptr)
	{
		cout << "up3.get() != nullptr" << endl;
	}
}

void test_move()
{
	unique_ptr<string> up1(new string("lala"));
	unique_ptr<string> up2(std::move(up1));
	unique_ptr<string> up3 = std::move(up2);
	// 初始赋值时,新值必须是unique_ptr
	unique_ptr<string> up4;
	up4 = unique_ptr<string>(new string("kk"));
}

// C++无法区分pointer是'指向单对象'或'指向array'
// 对于array应该使用delete[]
void test_array()
{
	std::unique_ptr<std::string[]> up(new std::string[10]);

	cout << up[0] << endl;
}

int main()
{
	//test_unique_ptr();

	//test_move();

	test_array();
}