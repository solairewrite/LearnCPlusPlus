// tuple2.cpp中调用
#include <tuple>
#include <iostream>

// helper: print elements with index IDX and higher of tuple t having MAX elements
// 打印索引[IDX, MAX)范围的元素
// 运用:模板超编程,在编译期递归迭代
// 调用: cout << mytuple;
template <int IDX, int MAX, typename... Args>
struct PRINT_TUPLE {
	// 结构体内声明函数
  static void print (std::ostream& strm, const std::tuple<Args...>& t) {
    strm << std::get<IDX>(t) << (IDX+1==MAX ? "" : ",");
    PRINT_TUPLE<IDX+1,MAX,Args...>::print(strm,t);
  }
};

// partial specialization to end the recursion
// 偏特化版本终结递归
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
