# LearnC++
## VS2019设置
### 打开命令行
安装插件 Extensions -> Manage Extensions -> Open Command Line  
Alt + Space 可以打开文件所在目录的cmd  
### 使用g++编译cpp文件
安装 MinGW: Minimalist GNU for Windows  
>下载mingw-get-setup.exe, 这是个安装器  
>打开后选中mingw32-gcc-g++-bin, Installation->Applay Changes 进行安装  

配置环境变量
>Advanced system settings -> Environment Variables -> System variables  

方法1:
>New  
>Variable name: MinGW  
>Variable value: F:\Env\MinGW\bin  
>Path中添加%MinGW%  

方法2:
>Path中添加F:\Env\MinGW\bin  
>
查看是否安装成功  
>g++ -v  

运行
>g++ xx.cpp 生成 a.exe  
>a.exe  

>g++ xx.cpp -o xx.exe 生成 xx.exe  
>xx.exe  

### 其他
+ 预编译头: 右键项目属性->配置属性->C/C++->预编译头->不使用预编译头  
## cmd命令
+ 进入磁盘: D:  
+ 删除文件: del a.exe  
+ 清屏: cls  
+ 当前路径下的所有文件: dir  
+ 创建txt: echo "abc" > tmpfile.txt  
+ 打开记事本: notepad  
## 多态 polymorphism
### 多态
允许将子类型的指针赋值给父类型的指针  
运行时,可以通过指向基类的指针,调用派生类中的方法  
多态性通过虚函数实现  
### 动态绑定
在执行期间判断所引用对象的实际类型,根据实际的类型调用其相应的方法  
动态绑定通过虚函数实现,虚函数通过虚函数表实现  
这个表中记录了虚函数的地址,保证动态绑定时能够根据对象的实际类型调用正确的函数  
