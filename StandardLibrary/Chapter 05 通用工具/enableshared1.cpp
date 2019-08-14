// 必须确保对象只被一组shared pointer拥有,否则会被释放多次

#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

// std::enable_shared_from_this<>表现出被shared pointer管理的对象
// 然后就可以使用shared_from_this()建立源自this的正确shared_ptr
class Person :public enable_shared_from_this<Person>
{
public:
	string name;
	shared_ptr<Person> mother;
	shared_ptr<Person> father;
	vector<weak_ptr<Person>> kids;

	Person(const string& n)
		:name(n)
	{
		// 不能在构造函数中调用shared_from_this();
	}

	void setParentsAndTheirKids(shared_ptr<Person> m = nullptr,
		shared_ptr<Person> f = nullptr)
	{
		mother = m;
		father = f;
		if (m != nullptr)
		{
			m->kids.push_back(shared_from_this());
		}
		if (f != nullptr)
		{
			f->kids.push_back(shared_from_this());
		}
	}

	~Person()
	{
		cout << "delete " << name << endl;
	}
};

namespace enableshared1
{
	shared_ptr<Person> initFamily(const string& name)
	{
		shared_ptr<Person> mom(new Person(name + "'s mom"));
		shared_ptr<Person> dad(new Person(name + "'s dad"));
		shared_ptr<Person> kid(new Person(name));
		kid->setParentsAndTheirKids(mom, dad);
		return kid;
	}
}

int main()
{
	shared_ptr<Person> p = enableshared1::initFamily("nico");
	cout << "mico's family exists" << endl;
	cout << "mico is shared " << p.use_count() << " times" << endl;
	cout << "name of 1st kid of nico's mom: " << endl;
}