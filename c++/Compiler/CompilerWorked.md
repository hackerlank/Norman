###################################################
## Create Date:2016年01月13日 星期三 08时35分10秒
##
##Author:Norman
##
##Description: C/C++编译器原理
###################################################

####了解链接器:
    目录:
        1.各部分命名:看看C文件中都包含了哪些内容
        2.C编译器都做了些什么
            *剖析目标文件
        3.链接器都做了什么(1)
            *重复的符号
        4.操作系统做了什么
        5.链接器都做了什么(2)
            *静态库
            *共享库
            *Windows DLLs
                *导出符号
                *LIB以及其它与库相关的文件
                *导入符号
                *循环依赖
        6.将C++加入示意图
            *函数重载和命名改编
            *静态初始化
            *模板
        7.运态载入库
            *动态载入与C++特性交互
        8.参考资料