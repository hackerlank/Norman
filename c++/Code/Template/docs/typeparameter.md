/**
* Create Date:2016年01月20日 星期三 13时30分07秒
* 
* Author:Norman
* 
* Description: 
*/

####类型形参:
    1.类型形参由关键字class或typename后接说明符构成
    类型形参名由自己确定,表示一个未知类型
    模板类型形参可作为类型说明符用在模板中的任何地方,与内置类型说明符或类类型说明符使用方式完全相同
    即可用于指定返回类型,变量声明等

    2.函数模板中不能给形参指定两种类型
     在类模板中可以但会警告(自动类型转换)