<style>
table th:first-of-type {
	min-width: 230px;
}
</style>
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
## 7.2 Array
| 操作 | 效果 |
| - | - |
| c.fill(val) | 将val赋值给array c的每一个元素 |
| c[idx] | 返回索引idx所指的元素(不检查范围) |
| c.at(idx) | 返回索引idx所指的元素(如果idx超出范围就抛出range-error异常) |
| c.front() | 返回第一个元素(不检查是否存在第一元素) |
| c.back() | 返回第最末元素(不检查是否存在最末元素) |
## 7.3 Vector
| 操作 | 效果 |
| - | - |
| vector\<Elem> c(n) | 利用元素的default构造函数生成一个大小为n的vector |
| vector\<Elem> c(n, elem) | 建立一个大小为n的vector,每个元素值都为elem |
| vector\<Elem> c(beg, end) | 建立一个vector,以区间[beg, end)作为元素初值 |
| c.capacity() | 返回"不进行空间重新分配"条件下的元素最大容量 |
| c.reserve(num) | 如果容量不足,扩大之 |
 c.shrink_to_fit() | 要求降低容量,以符合元素个数 |
| c.assign(n, elem) | 赋值n个elem,赋值给c |
| c.assign(beg, end) | 将区间[beg, end)内的元素赋值给c |
| c.assign(initlist) | 将初值列的所有元素赋值给c |
| c[idx] | 返回索引idx所指的元素(不检查范围) |
| c.at(idx) | 返回索引idx所指的元素(如果idx超出范围就抛出range-error异常) |
| c.front() | 返回第一个元素(不检查是否存在第一元素) |
| c.back() | 返回第最末元素(不检查是否存在最末元素) |
| c.push_back(elem) | 附加一个elem的拷贝于末尾 |
| c.pop_back() | 移除最后一个元素,但是不返回它 |
| c.insert(pos, elem) | 在iterator位置pos之前方插入一个elem拷贝,并返回新元素的位置 |
| c.insert(pos, n, elem) | 在iterator位置pos之前方插入n个elem拷贝,并返回第一个新元素的位置(或返回pos--如果没有新元素的话) |
| c.insert(pos, beg, end) | 在iterator位置pos之前方插入区间[beg, end]内所有元素的一份拷贝,并返回第一个新元素的位置(或返回pos--如果没有新元素的话) |
| c.insert(pos, initlist) | 在iterator位置pos之前方插入初值列initlist内所有元素的一份拷贝,并返回第一个新元素的位置(或返回pos--如果没有新元素的话) |
| c.emplace(pos, args...) | 在iterator位置pos之前方插入一个以args为初值的元素,并返回 新元素的位置 |
| c.emplace_back(args...) | 附加一个以args为初值的元素于末尾,不返回任何东西 |
| c.erase(pos) | 移除iterator位置pos上的元素,返回下一元素的位置 |
| c.erase(beg, end) | 移除[beg, end)区间内的所有元素,返回下一元素的位置 |
| c.resize(num) | 将元素数量改为num(如果size()变大,多出来的新元素都需以default构造函数完成初始化) |
| c.resize(num, elem) | 将元素数量改为num(如果size()变大,多出来的新元素都是elem的拷贝) |
| c.clear() | 移除所有元素,将容器清空 |
## 7.4 Deque
接口类似Vector  
| 操作 | 效果 |
| - | - |
| c.push_front(elem) | 在头部插入elem的一个拷贝 |
| c.pop_front() | 移除第一个元素(但不返回) |
## 7.5 List
List对象自身提供了两个pointer,或称anchor(锚点),用来指向第一个和最末一个元素  
每个元素都有pointer指向前一个和下一个元素(或是指回anchor)  
如果想要安插新元素,只需操纵对应的pointer即可  
List提供deque的所有功能  
| 操作 | 效果 |
| - | - |
| c.front() | 返回第一元素(不检查是否存在第一元素) |
| c.back() | 返回最末元素(不检查是否存在最末元素) |
| c.remove(val) | 移除所有其值为val的元素 |
| c.remove_if(op) | 移除所有"造成op(elem)结果为true"的元素 |
| c.unique() | 如果存在若干相邻而数值相同的元素,就移除重复元素,只留一个 |
| c.unique(op) | 如果存在若干相邻元素都使op()的结果为true,则移除重复元素,只留一个 |
| c.splice(pos, c2) | 将c2内的所有元素转移(move)到c之内,迭代器pos之前 |
| c.splice(pos, c2, c2pos) | 将c2内的c2pos所指元素转移到c内的pos所指位置(c和c2可相同) |
| c.splice(pos, c2, c2beg, c2end) | 将c2内的[c2beg, c2end)区间内所有元素转移到c内的pos所指位置(c和c2可相同) |
| c.sort() | 以operator<为准则对所有元素排序 |
| c.sort(op) | 以op()为准则对所有元素排序 |
| c.merge(c2) | 假设c和c2容器都包含op()准则下的已排序(sorted)元素,将c2的全部元素转移到c,并保证合并后的list仍为已排序 |
| c.merge(c2, op) | 假设c和c2容器都包含已排序(sorted)元素,将c2的全部元素转移到c,并保证合并后的list在op()准则下仍为已排序 |
| c.reverse() | 将所有元素反序(reverse the order) |
## 7.6 Forward List
| 操作 | 效果 |
| - | - |
| c.front() | 返回第一元素(不检查是否存在第一元素) |
| c.before_begin() | 返回一个forward iterator指向第一元素的前一位置 |
| c.cbefore_begin() | 返回一个const forward iterator指向第一元素的前一位置 |
| c.push_front(elem) |  |
| c.pop_front() |  |
| c.insert_after(pos, elem) |  |
| c.insert_after(pos, n, elem) |  |
| c.insert_after(pos, beg, end) |  |
| c.insert_after(pos, initlist) |  |
| c.emplace_after(pos, args...) |  |
| c.emplace_front(args...) |  |
| c.erase_after(pos) |  |
| c.erase_after(beg, end) |  |
| c.remove(val) |  |
| c.remove_if(op) |  |
| c.resize(num) |  |
| c.resize(num, elem) |  |
| c.clear() |  |
| c.unique() | 移除重复而相邻的元素,只留一个 |
| c.unique(op) | 移除相邻而且都令op()结果为true的元素,只留一个 |
| c.splice_after(pos, c2) | 将c2的所有元素转移(move)到c之内,迭代器pos之后 |
| c.splice_after(pos, c2, c2pos) | 将c2内的c2pos所指元素转移到c内的pos所指位置(c和c2可以是同一容器) |
| c.splice_after(pos, c2, c2beg, c2end) | 将c2内的(c2beg, c2end)区间内(不含头尾)所有元素转移到c内的pos所指位置(c和c2可以是同一容器) |
| c.sort() | 以operator<为准则对所有元素排序 |
| c.sort(op) | 以op()为准则对所有元素排序 |
| c.merge(c2) | 假设c和c2容器都包含已排序(sorted)元素,将c2的全部元素转移(move)到c,并保证合并后合并后的所有元素仍为已排序(sorted) |
| c.merge(c2, op) |  |
| c.reverse() | 将所有元素反序 |
