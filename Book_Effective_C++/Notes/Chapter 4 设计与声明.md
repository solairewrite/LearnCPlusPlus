### 第4章 设计与声明
#### 18: 让接口容易被正确使用,不易被误用
"阻止误用"的办法包括建立新类型,限制类型上的操作,束缚对象值,消除客户的资源管理责任  
比如将返回的指针包装 tr1::shared_ptr<>() 
#### 19: 设计 class 犹如设计 type
#### 20: 宁以 pass-by-reference-to-const 替换 pass-by-value
尽量以 pass-by-reference-to-const 替换 pass-by-value. 前者通常比较高效,并可以避免切割问题(slicing problem)  
以上规则并不适用于内置类型,以及 STL 的迭代器和函数对象. 对它们而言, pass-by-value 往往比较适当  
#### 21: 必须返回对象时,别妄想返回其 reference
#### 22: 将成员变量声明为 private
#### 23: 宁以 non-member, non-friend 替换 member 函数
#### 24: 若所有参数皆需类型转换,请为此采用 non-member 函数
#### 25: 考虑写出一个不抛异常的 swap 函数
当 std::swap 对你的类型效率不高时,提供一个 swap 成员函数,并确定这个函数不抛出异常  
如果你提供一个 member swap, 也该提供一个 non-member swap 来调用前者  
对于 classes (而非 templates), 也请特化 std\::swap  
调用 swap 时,应针对 std\::swap 使用 using 声明式,然后调用 swap 而不带任何"命名空间修饰"  
为"用户定义类型"进行 std templates 全特化是好的.但千万不要尝试在 std 内加入某些对 std 而言全新的东西  