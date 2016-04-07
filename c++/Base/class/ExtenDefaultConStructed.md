/**
* Create Date:2016年03月13日星期日 08:34:29
* 
* Author:Norman
* 
* Description: 
*/

####默认构造函数:
    1.一个类,如果没有任何用户声明构造函数,那么会有一个默认构造函数被隐式声明出来.

####默认构造函数何时合成:
    默认构造函数在编译器需要的时候被合成.

####编译器需要合成默认构造函数情况:
####[1.类的成员变量带有默认构造函数](./Member_class_objects.cpp)
####[2.类的基类带有默认构造函数](./Base_class_objects.cpp)
####[3.类带有virtual函数](./Virtual_class_objects.cpp)
####[4.类带有一个virtual 基类](./Virtual_Base_class.cpp)
    且合成操作只有在构造函数真正需要被调用时才会被合成

####C++不同编译模块,避免合成多个默认:
    1.把合成的默认构造函数  复制构造函数 析构函数 赋值操作运算符等都以inline方式完成。
    2.函数太复杂不适合inline 就会成一个显式非inline的static函数
    3.以上方法都是为了不被文件以外者访问


####总结:
    1.若没有声明任何构造函数,编译器会为其合成一个默认的构造函数
    2.若已声明一个或多个构造函数,编译器会为每个构造函数安插一定代码来完成编译必要的工作
    3.被合成的构造函数称为"隐式有效的默认构造函数"
    4.合成出来的默认构造函数,只会初始化基类子对象和成员类对象,其他非static成员变量并不会被初始化

    错误点:
    1.任何class如果没有定义默认构造函数,就会被合成出来(只有付合上述四类条件)
    2.编译器合成的默认构造函数,会显式设定class内每一个成员数据默认值 