// P61 struct pair ���������б�
#include <iostream>
#include <utility>

using namespace std;

// ���ͺ���ģ��(generic function template),��pairд��stream
template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& strm, const std::pair<T1, T2>& p)
{
	return strm << "[" << p.first << "," << p.second << "]";
}

// ��pairʹ��tuple-like�ӿ�
void TupleLikeInterface()
{
	typedef std::pair<int, float> IntFloatPair;
	IntFloatPair p(42, 3.14);

	// ���Զ�pairʹ��tuple-like�ӿ�
	cout << std::get<0>(p) << endl; // 42
	cout << std::get<1>(p) << endl; // 3.14
	cout << std::tuple_size<IntFloatPair>::value << endl; // 2
	// ��ӡ������
	cout << typeid(float).name() << endl; // float
	cout << typeid(std::tuple_element<0, IntFloatPair>::type).name() << endl; // int
}

int main()
{
	TupleLikeInterface();
}