/**
* Create Date:2016年01月20日 星期三 20时44分21秒
* 
* Author:Norman
* 
* Description: 
*/

解释:
    模板实现与定义分开,在模板类所在的编译单元里不可能知道模板参数是什么
    只要把模板定义放到每一个引用它的地方,就可以完成展开

    模板定义其实应该算是模板声明,真正的定义是在你确认了模板类型参数之后(由编译器自动生成代码)

    C++中每一个对象所占用的空间大小,是在编译时就确定的,模板类没有真正被使用之前,编译器无法知道,模板类中使用模板类型的对象所占用的空间大小.只有在被真正使用时,编译器才知道模板套用什么类型,应该分配多少空间。(模板不是泛型的原因)


问题:
    出现链接时对构造函数未定义的引用

解决方案:
    1.直接在main里包含templateDemo.cpp

    2.新增一个impl.cpp文件
    #include"TemplateDemo.cpp"
    template <class T> A<T>;

    3.在模板定义中使用export关键字。
