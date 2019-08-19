### 第6章 继承与面向对象设计
#### 32: 确定你的public继承塑模处is-a关系
"public继承"意味is-a.适用于base classes身上的每一件事情一定也适用于derived classes身上,因为每一个derived class对象也都是一个base class对象  
#### 33: 避免遮掩继承而来的名称
#### 34: 区分接口继承和实现继承
接口继承和实现继承不同.在public继承之下,继承类总是继承基类的接口  
纯虚函数只具体指定接口继承  
非纯虚函数具体指定接口继承及缺省实现继承  
非虚函数具体指定接口继承及强制性实现继承  
#### 35: 考虑 virtual 函数以外的其他选择
+ 藉由 Non-Virtual Interface 手法实现 Template Method 模式  

NVI: non-virtual interface,令客户通过 public non-virtual 成员函数间接调用 private virtual 函数  
他是所谓 Template Method 设计模式(与C++ templates无关)的一个独特表现形式  
这个 non-virtual 函数称为 virtual 函数的外覆器(wrapper)  
外覆器(wrapper)确保得以在一个 virtual 函数被调用之前设定好适当场景,并在结束之后清理场景  
C++ derived class 可以重定义继承而来的 private virtual 函数  
+ 藉由 Function Pointers 实现 Strategy 模式  

优点:每个对象可各自拥有自己的计算函数,可在运行期改变计算函数  

+ 藉由 tr1::function 完成 Strategy 模式  

