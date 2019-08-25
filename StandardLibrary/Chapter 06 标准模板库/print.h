#include <iostream>
#include <string>

using namespace std;

template <typename T>
inline void PRINT_ELEMENTS(const T& coll, const string& optstr = "")
{
	cout << optstr;
	for (const auto& elem : coll)
	{
		cout << elem << ' ';
	}
	cout << endl;
}