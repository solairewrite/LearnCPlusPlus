# 第7章 STL 容器
## 7.1 容器的共通能力和共通操作
| 操作 | 效果 |
| - | - |
| ContType c | Default 构造函数 |
| ContType c(c2) | Copy 构造函数 |
| ContType c = c2 | Copy 构造函数 |
| ContType c(rv) | Move 构造函数 |
| ContType c = rv | Move 构造函数 |
| ContType c(beg, end) | 建立一个容器,以[beg, end)区间内的所有元素拷贝为初值 |
| ContType c(initlist) | 建立一个容器,并以初值列initlist的拷贝为初值 |
| ContType c = initlist | 建立一个容器,并以初值列initlist的拷贝为初值 |
| c.~ContType() | 删除所有元素,释放内存 |
| c.empty() | 判断容器是否为空,相当于size()==0 |
| c.size() | 返回容器中的元素数量 |
| c.max_size() | 返回元素的最大可能数量 |
| c1 == c2 | 判断&emsp;!=&emsp;<&emsp;>&emsp;<=&emsp;>= |
| c = c2 | 将c2的所有元素赋值给c |
| c = rv | 将rvalue rv以move assign方式赋予c |
| c = initlist | 将初值列initlist中的所有元素赋值给c |
| c1.swap(c2) | 置换c1和c2的数据 |
| swap(c1, c2) | 同上,是个全局函数 |
| c.begin() | 返回一个iterator,指向第一个元素 |
| c.end() | 返回一个iterator,指向最末元素的下一个位置 |
| c.cbegin() | 返回一个const iterator,指向第一个元素 |
| c.cend() | 返回一个const iterator,指向最末元素的下一个位置 |
| c.clear() | 移除所有元素,令容器为空 |

| 类型 | 效果 |
| - | - |
| value_type | 元素的类型 |
| reference | 元素的reference的类型 |
| const_reference | 常量元素的reference的类型 |
| iterator | Iterator的类型 |
| const_iterator | "指向只读元素的"iterator的类型 |
| pointer | "指向元素的"pointer的类型 |
| const_pointer | "指向只读元素的"pointer的类型 |
