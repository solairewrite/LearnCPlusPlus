# LearnC++
## 使用g++编译cpp文件
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
## VS2019设置
### Run窗口打开VS
win+R打开Run窗口,输入devenv  
### 打开命令行
安装插件 Extensions -> Manage Extensions -> Open Command Line  
Alt + Space 可以打开文件所在目录的cmd  
### 常用插件
Open Command Line 打开命令行  
Visual Assist  
Markdown Editor 右侧预览.md  
Output enhancer 输出窗口彩色文字  
Viasfora 彩色括号  
ClaudiaIDE 背景图片  
设置: Tools -> Options -> ClaudiaIDE
默认图片路径: C:\Users\Administrator\AppData\Local\Microsoft\VisualStudio\16.0_660e1384\Extensions\ornt1lf3.e2w\Images
### 其他
+ 预编译头: 右键项目属性->配置属性->C/C++->预编译头->不使用预编译头  
## cmd命令
+ 进入磁盘: D:  
+ 删除文件: del a.exe  
+ 清屏: cls  
+ 当前路径下的所有文件: dir  
+ 创建txt: echo "abc" > tmpfile.txt  
+ 打开记事本: notepad  
+ 关机: shutdown -s -t 00  
## 多态 polymorphism
### 多态
允许将子类型的指针赋值给父类型的指针  
运行时,可以通过指向基类的指针,调用派生类中的方法  
多态性通过虚函数实现  
### 动态绑定
在执行期间判断所引用对象的实际类型,根据实际的类型调用其相应的方法  
动态绑定通过虚函数实现,虚函数通过虚函数表实现  
这个表中记录了虚函数的地址,保证动态绑定时能够根据对象的实际类型调用正确的函数  
编译器必须保证虚函数表的指针存在于对象实例中最前面的位置(为了保证正确取到虚函数的偏移量)  
通过对象实例的地址得到这张虚函数表  
然后遍历其中的函数指针,并调用相应的函数  
### 虚函数表
虚函数表是一块连续的内存,每个内存单元记录一个JMP指令的地址  
编译器会为每个有虚函数的类创建一个虚函数表,该虚函数表被该类的所有对象共享  
类的每个虚成员占虚函数表中的一行  
在有虚函数的类的实例中分配了指向这个表的指针的内存  
当父类的指针操作子类时,虚函数表指明了实际所应调用的函数  
