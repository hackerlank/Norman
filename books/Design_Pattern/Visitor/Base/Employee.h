/**
*  - version 1.0
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/
#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_
#pragma once
#include "IVisitor.h"

class CEmployee{
public:
    static int MALE;
    static int FEMALE;
    CEmployee();
    virtual ~CEmployee();
    string GetName();
    void SetName(string name);
    int GetSalary();
    void SetSalary(int v);
    int GetSex();
    void SetSex(int v);
    virtual void Accept(IVisitor *pVisitor) =0;
private:
    string m_name;
    int m_salary;
    int m_sex;
};

#endif
