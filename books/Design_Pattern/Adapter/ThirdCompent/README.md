/**
* Create Date:2016年01月24日 星期日 15时35分32秒
* 
* Author:Norman
* 
* Description: 
*/

####Adapter模式:
    接口继承和实现继承区别:
        接口继承:
            通过继承子类获得父类的接口
        实现继承:
            通过继承子类获得父类的实现

    C++中public继承既是接口继承又是实现继承,因为子类在继承父类后既可以对外提供父类中的接口操作,又可以获得父类的接口实现

    模拟单独的接口继承和实现继承方式:
        1.通过private继承获得实现继承的效果 private继承后,父类中接口都变为private 
        2.通过纯抽象基类模拟接口继承的效果
        3.但是在C++中pure virtual function也可提供默认实现,因此这是不纯正的接口继承.
        4.在java中可以interface来获得真正的接口继承