// tuple2.cpp�е���
#include <tuple>
#include <iostream>

// helper: print elements with index IDX and higher of tuple t having MAX elements
// ��ӡ����[IDX, MAX)��Χ��Ԫ��
// ����:ģ�峬���,�ڱ����ڵݹ����
// ����: cout << mytuple;
template <int IDX, int MAX, typename... Args>
struct PRINT_TUPLE {
	// �ṹ������������
  static void print (std::ostream& strm, const std::tuple<Args...>& t) {
    strm << std::get<IDX>(t) << (IDX+1==MAX ? "" : ",");
    PRINT_TUPLE<IDX+1,MAX,Args...>::print(strm,t);
  }
};

// partial specialization to end the recursion
// ƫ�ػ��汾�ս�ݹ�
template <int MAX, typename... Args>
struct PRINT_TUPLE<MAX,MAX,Args...> {
  static void print (std::ostream& strm, const std::tuple<Args...>& t) {
  }
};

// output operator for tuples
template <typename... Args>
std::ostream& operator << (std::ostream& strm,
                           const std::tuple<Args...>& t)
{
    strm << "[";
    PRINT_TUPLE<0,sizeof...(Args),Args...>::print(strm,t);
    return strm << "]";
}
