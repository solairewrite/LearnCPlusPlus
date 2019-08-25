// 示例: stl/prime1.cpp
// 示例: stl/sort1.cpp
#include <list>
#include <algorithm>
#include <iostream>
#include <cstdlib> // abs()
#include <deque>
#include <string>

using namespace std;

// 是否是质数
bool isPrime(int number)
{
	number = abs(number);

	if (number == 0 || number == 1)
	{
		return false;
	}

	int divisor;
	for (divisor = number / 2; number % divisor != 0; --divisor)
	{
		;
	}

	return divisor == 1;
}

void prime1()
{
	list<int> coll;

	for (int i = 24; i <= 30; ++i)
	{
		coll.push_back(i);
	}

	// 搜索质数
	auto pos = find_if(coll.cbegin(), coll.cend(),
		isPrime);

	if (pos != coll.end())
	{
		cout << *pos << " is first prime number found" << endl;
	}
	else
	{
		cout << "no prime number found" << endl;
	}
}

class Person
{
private:
	string fn;
	string ln;
public:
	Person()
	{
	}
	Person(const string& f, const string& l)
		:fn(f), ln(l)
	{
	}
	string firstname() const;
	string lastname() const;
};

inline string Person::firstname() const
{
	return fn;
}

inline string Person::lastname() const
{
	return ln;
}

ostream& operator<<(ostream& s, const Person& p)
{
	s << "[" << p.firstname() << " " << p.lastname() << "]";
	return s;
}

// 双参判断式
bool personSortCriterion(const Person& p1, const Person& p2)
{
	return p1.lastname() < p2.lastname() ||
		(p1.lastname() == p2.lastname() &&
			p1.firstname() < p2.firstname());
}

void sort1()
{
	Person p1("nicolai", "josuttis");
	Person p2("ulli", "josuttis");
	Person p3("anica", "josuttis");
	Person p4("lucas", "josuttis");
	Person p5("lucas", "otto");
	Person p6("lucas", "arm");
	Person p7("anica", "holle");

	deque<Person> coll;
	coll.push_back(p1);
	coll.push_back(p2);
	coll.push_back(p3);
	coll.push_back(p4);
	coll.push_back(p5);
	coll.push_back(p6);
	coll.push_back(p7);

	cout << "deque before sort(): " << endl;
	deque<Person>::iterator pos;
	for (pos = coll.begin(); pos != coll.end(); ++pos)
	{
		cout << *pos << endl;
	}
	cout << endl;

	sort(coll.begin(), coll.end(),
		personSortCriterion);

	cout << "deque after sort(): " << endl;
	for (pos = coll.begin(); pos != coll.end(); ++pos)
	{
		cout << *pos << endl;
	}
	cout << endl;
}

int main()
{
	//prime1();
	sort1();
}