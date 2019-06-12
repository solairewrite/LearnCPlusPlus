### 第3章 资源管理
#### 13: 以对象管理资源
为防止资源泄露,请使用RAII()对象,它们在构造函数中获得资源,并在析构函数中释放资源  
两个常被使用的 RAII classes 分别是 tr1::shared_ptr 和 auto_ptr  
#### 14: 在资源管理类中小心 copying 行为
#### 15: 在资源管理器中提供对原始资源的访问
APIs往往需要访问原始资源(raw resources),所以每一个 RAII class 应该提供一个"取得其所管理之资源"的办法  
对原始资源的访问可能经由显示转换或隐式转换.一般而言显示转换比较安全,但隐式转换对客户比较方便  
#### 16: 成对使用new和delete时要采取相同形式
如果在 new 表达式中使用 [], 必须在相应的 delete 表达式中也使用 []  
#### 17: 以独立语句将 newed 对象置入智能指针
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