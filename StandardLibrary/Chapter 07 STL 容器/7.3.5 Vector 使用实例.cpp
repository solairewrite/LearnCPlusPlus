// ʾ��: cont/vector1.cpp
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator> // ostream_iterator

using namespace std;

//int main()
//{
//	vector<string> sentence;
//
//	// reserve 5��Ԫ��,�������·���
//	sentence.reserve(5);
//
//	sentence.push_back("Hello,");
//	sentence.insert(sentence.end(), { "how","are","you","?" });
//
//	// ��ӡԪ��,�ÿո�ָ�
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
//	// ��?ǰ�����always
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