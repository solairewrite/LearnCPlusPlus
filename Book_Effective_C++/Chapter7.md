### 第7章 模板与泛型编程
#### 41: 了解隐式接口和编译期多态
classes 和 templates 都支持接口 (interfaces) 和多态 (polymorphism)  
对 classes 而言接口是显示的 (explicit),以函数签名为中心.多态则是通过 virtual 函数发生于运行期  
对 templates 参数而言,接口是隐式的 (implicit),奠基于有效表达式.多态则是通过 template 具现化和函数重载解析 (function overloading resolution) 发生于编译期  
#### 42: 了解 typename 的双重意义
声明 template 参数时,前缀关键字 class 和 typename 可互换  
请使用关键字 typename 标识嵌套从属类型名称  
