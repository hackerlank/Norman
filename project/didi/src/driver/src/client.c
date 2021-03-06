/*########################################################
##File Name: client.c
##Created Time:2016年1月4日 星期一 14时50分56秒
##Author: Norman 
##Description: 
##
##Issue: 
##
##Analyze: 
##
##Induction:
##
##Summary:
##
##########################################################*/

#include<stdio.h>
#include "../include/user.h"
#include "../include/cjson.h"

void showUserMenu(){
    char ch;
    while(ch != '4'){
        system("clear");
        printf("##########################################\n");
        printf("##              1.我的历史订单          ##\n");
        printf("##                                      ##\n");
        printf("##              2.开始抢单              ##\n");
        printf("##                                      ##\n");
        printf("##              3.修改密码              ##\n");
        printf("##                                      ##\n");
        printf("##              4.退出登陆              ##\n");
        printf("##########################################\n");
        
        while((ch=getchar())!='\n');
        printf("请输入选择:");
        
        ch = getchar();
        switch(ch){
            case '1':
                query_order();
                break;
            case '2':
                printf("开始抢单!请等待...\n");
                sleep(1);
                taketoken();
                break;
            case '3':
                modifypasswd();
                break;
            case '4':
                logout();
                break;
            default:
                break;
        }
    }
}

void showMenu(){
    char ch;
    while(1){
        system("clear");
        printf("##########################################\n");
        printf("##               司机用户端             ##\n");
        printf("##########################################\n");
        printf("##              1.注册司机              ##\n");
        printf("##                                      ##\n");
        printf("##              2.司机登录              ##\n");
        printf("##                                      ##\n");
        printf("##              3.退出程序              ##\n");
        printf("##########################################\n");
        while((ch=getchar())!='\n');
        printf("请输入选择:");
        ch = getchar();
        switch(ch){
            case '1':
                register_user();
                break;
            case '2':
                login();
                break;
            case '3':
                close(sfd);
                exit(0);
                break;
            default:
                break;
        }
    }
}


int main(){
    int ret;
    ret = init_socket();
    if(-1 == ret){
        return -1;
    }
    showMenu();
}


