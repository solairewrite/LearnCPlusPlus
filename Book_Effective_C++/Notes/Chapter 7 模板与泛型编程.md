### 第7章 模板与泛型编程
#### 41: 了解隐式接口和编译期多态
classes 和 templates 都支持接口 (interfaces) 和多态 (polymorphism)  
对 classes 而言接口是显示的 (explicit),以函数签名为中心.多态则是通过 virtual 函数发生于运行期  
对 templates 参数而言,接口是隐式的 (implicit),奠基于有效表达式.多态则是通过 template 具现化和函数重载解析 (function overloading resolution) 发生于编译期  
#### 42: 了解 typename 的双重意义
声明 template 参数时,前缀关键字 class 和 typename 可互换  
请使用关键字 typename 标识嵌套从属类型名称  
#### 43: 学习处理模板化基类内的名称
可在 derived class templates 内通过 "this->" 指涉 base class templates 内的成员名称,或藉由一个明白写出的 "base class 资格修饰符"完成  
#### 44: 将参数无关的代码抽离templates
?  
#### 45: 运用成员函数模板接受所有兼容类型
?  
#### 46: 需要类型转换时请为模板定义非成员函数
?  
#### 47: 请使用 traits classes 表现类型信息
#### 48: 认识template元编程
Template metaprogramming(TMP, 模板元编程)可将工作由运行期移往编译期,因而得以实现早期错误侦测和更高的执行效率  
