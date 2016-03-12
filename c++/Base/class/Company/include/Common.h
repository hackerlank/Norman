/**
* Create Date:2016年03月10日星期四 13:37:26
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/

#ifndef _STRUCT_H
#define _STRUCT_H
#include <iostream>
#include <list>
using namespace std;
#define FILE_STORAGE_PATH "../db/employee.txt"

enum pType {
    FULLTIME,
    PARTTIME
};

enum jobStatus {
    ONJOB,
    RESIGN
};

enum POST {
    SALEMANAGER,
    TECHNICIAN,
    SALESMAN,
    MANAGER
};

struct EmployeeInfo_s {
    unsigned long id;
    char name[20];
    int age;
    char sex[4];
    char post[20];
};

struct Node {
    unsigned long id;
    char name[20];
    int age;
    char sex[4];
    int type;
    char post[20];
    int level;
    float basePay;
    int status;
    Node* next;
    Node* pre;
};

using EmployeeInfo_t = list<EmployeeInfo_s>;
#endif
