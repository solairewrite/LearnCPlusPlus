// 示例: cont/vector1.cpp
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator> // ostream_iterator

using namespace std;

//int main()
//{
//	vector<string> sentence;
//
//	// reserve 5个元素,避免重新分配
//	sentence.reserve(5);
//
//	sentence.push_back("Hello,");
//	sentence.insert(sentence.end(), { "how","are","you","?" });
//
//	// 打印元素,用空格分隔
//	copy(sentence.begin(), sentence.end(),
//		ostream_iterator<string>(cout, " "));
//	cout << endl;
//
//	cout << "max_size(): " << sentence.max_size() << endl;
//	cout << "size()    : " << sentence.size() << endl; // 5
//	cout << "capacity(): " << sentence.capacity() << endl; // 5
//
//	swap(sentence[1], sentence[3]);
//
//	// 在?前面插入always
//	sentence.insert(find(sentence.begin(), sentence.end(), "?"),
//		"always");
//
//	sentence.back() = "!";
//
//	copy(sentence.begin(), sentence.end(),
//		ostream_iterator<string>(cout, " "));
//	cout << endl; // Hello, you are how always !
//
//	cout << "size()    : " << sentence.size() << endl; // 6
//	cout << "capacity(): " << sentence.capacity() << endl; // 7
//
//	sentence.pop_back();
//	sentence.pop_back();
//	
//	sentence.shrink_to_fit();
//
//	cout << "size()    : " << sentence.size() << endl; // 4
//	cout << "capacity(): " << sentence.capacity() << endl; // 4
//}