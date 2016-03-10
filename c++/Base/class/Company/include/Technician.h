/**
* Create Date:2016年03月10日星期四 16:10:54
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/

#ifndef _TECHNICIAN_H
#define _TECHNICIAN_H
#include "Employee.h"
class CTechnician : public CEmployee {
public:
    CTechnician(int id,string name,int age,string sex,int type,string post,int level,float basePay,int status);
    ~CTechnician();
};

#endif
