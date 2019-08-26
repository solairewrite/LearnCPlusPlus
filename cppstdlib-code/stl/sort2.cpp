#include <algorithm>
#include <deque>
#include <string>
#include <iostream>
using namespace std;

class Person
{
public:
	string firstname() const;
	string lastname() const;
	//...
};

int main()
{
	deque<Person> coll;
	//...

	// sort Persons according to lastname (and firstname):
	sort(coll.begin(), coll.end(),                // range
		[](const Person& p1, const Person& p2) { // sort criterion
			return p1.lastname() < p2.lastname() ||
				(p1.lastname() == p2.lastname() &&
					p1.firstname() < p2.firstname());
		});
	//...
}
