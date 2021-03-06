/**
* Create Date:2016年03月10日星期四 10:23:58
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/

#include<iostream>
#include<string.h>
using namespace std;
#include "../include/Employee.h"
#include "../include/DBManage.h"
#include "../include/Common.h"

DBManage::DBManage():
    head(nullptr),
    tail(nullptr),
    size(0){
    cout << " DBManage Structor" << endl;
}

DBManage::~DBManage(){
    if (head != nullptr ) {
        cout << "del head" << endl; 
        head = nullptr;
    }

    if(tail != nullptr ) {
        cout << "del tail" << endl;
        tail = nullptr;
    }

    cout << "Destructor DBManage" << endl;
}

bool DBManage::readDatabase(const string& fileName) {
    FILE* fp;
    Node* pn = nullptr;
    fp = fopen(fileName.c_str(),"r+");

    if(fp == nullptr) {
        perror("fopen");
        return false;
    }
    while(feof(fp)==0) {
        pn = new Node;
        if(pn == nullptr) {
            printf("new failed!\n");
            return false;
        }
        
        int i = fscanf(fp,"%lu%s%d%s%d%s%d%f%d",
                &pn->id,
                pn->name,
                &pn->age,
                pn->sex,
                &pn->type,
                pn->post,
                &pn->level,
                &pn->basePay,
                &pn->status
                );

        if(i == EOF) {
            delete pn;
            break;
        }
        
        if(head) {
            pn->next = nullptr;
            pn->pre = tail;
            tail->next = pn;
        } else {
            pn->next = head;
            pn->pre = head;
            head = pn;
        }
        tail = pn;
        size++;
        CEmployee e;
        e.m_id++;
    }
    fclose(fp);
    return true;
}

bool DBManage::writeDatabase(const string& fileName) {
    FILE* fp;
    Node* pn;

    fp = fopen(fileName.c_str(),"w");
    if(fp == nullptr) {
        perror("fopen()");
        return false;
    }
    
    pn = head;
    while(pn) {
        fprintf(fp,"%lu\t%s\t%d\t%s\t%d\t%s\t%d\t%f\t%d\n",
                pn->id,
                pn->name,
                pn->age,
                pn->sex,
                pn->type,
                pn->post,
                pn->level,
                pn->basePay,
                pn->status);
        pn = pn->next;
    }
    fclose(fp);
    return true;
}

void DBManage::show() {
    auto pn = head;
    while(pn) {
        cout << "工号:" << pn->id ;
        cout << " 姓名:" << pn->name ;
        cout << " 性别:" << pn->sex ;
        cout << " 岗位类型:" << pn->type ;
        cout << " 职位:" << pn->post ;
        cout << " 级别:" << pn->level ;
        cout << " 基本工资:" << pn->basePay ;
        cout << " 是否在职:" << pn->status ;
        cout << endl;
        pn = pn->next;
    }
}

bool DBManage::queryUserInfo(EmployeeInfo_t& userInfo) {
    EmployeeInfo_s userInfo_s;
    auto pn = head;
    if(pn == nullptr) return false;
    while(pn) {
        userInfo_s.id = pn->id;
        strcpy(userInfo_s.name,pn->name);
        userInfo_s.age = pn->age;
        strcpy(userInfo_s.sex,pn->sex);
        strcpy(userInfo_s.post,pn->post);
        userInfo.push_back(userInfo_s);
        pn = pn->next;
    }
    return true;   
}

bool DBManage::queryUserInfo(EmployeeInfo_s& userInfo,unsigned int jobNum) {
    auto pn = head;
    if(pn == nullptr) return false;
    while(pn) {
        if (pn->id == jobNum) {
            userInfo.id = pn->id;
            strcpy(userInfo.name,pn->name);
            userInfo.age = pn->age;
            strcpy(userInfo.sex,pn->sex);
            strcpy(userInfo.post,pn->post);
        }
        pn = pn->next;
    }
    return true;   
}

bool DBManage::checkUserExist(unsigned int id) {
    auto pn = head;
    while(pn) {
        if(pn->id == id) {
            return true;
        }
        pn = pn->next;
    }
    return false;
}

bool DBManage::addUserInfo(Node*& userNode) {
    auto pn = userNode;
    if(head != nullptr) {
        pn->next = nullptr;
        pn->pre = tail;
        tail->next = pn;
    } else {
        pn->next = head;
        pn->pre = head;
        head = pn;
    }
    tail = pn;
    return true;
}


Node* DBManage::getHead() {
    return head;
}

Node* DBManage::getTail() {
    return tail;
}
