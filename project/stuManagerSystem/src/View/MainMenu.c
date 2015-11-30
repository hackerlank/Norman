/*########################################################
##File Name: MainMenu.c
##Created Time:2015年11月29日 星期日 19时15分31秒
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
#include<stdlib.h>
#include "../utils/DataConst.h"
#include "../utils/DataEnum.h"
#include "../Controller/AppController.h"
#include "../Controller/LoginController.h"


void ShowLoginMenu(int logintype) {
    int userid;
    char passwd[32] = {0};
    size_t ret;

    while(1) {
        system("clear");
        switch(logintype) {
            case STUDENT:
                printf("%s",PLEASE_INPUT_STUDENT_ID);
                scanf("%d",&userid);
                ret = onLoginAuthUserId(STUDENT,userid);
                if(ret == 0) {
                    printf("%s",PLEASE_INPUT_STUDENT_PASSWD);
                    scanf("%s",passwd);
                } else {
                    printf("%s\n",LOGIN_FAILED_INFO);
                    sleep(3);
                }
                break;
            case TEACHER:
                printf("%s\n",PLEASE_INPUT_TEACHER_ID);
                scanf("%d",&userid);
                printf("%s\n",PLEASE_INPUT_TEACHER_PASSWD);
                scanf("%s",passwd);
                break;
            case ADMINISTRATOR:
                printf("%s\n",PLEASE_INPUT_ADMIN_ID);
                scanf("%d",&userid);
                printf("%s\n",PLEASE_INPUT_ADMIN_PASSWD);
                scanf("%s",passwd);
                break;
            default:
                break;
        }
    }   
}

void ShowLoginSuccessMenu() {
    
}

void ShowLoginFailedMenu() {

}

void ShowMainMenu() {
    char ch;
    while(1) {
        system("clear");
        printf("\t\t##################################################\n");
        printf("\t\t##              %s            ##\n",MAIN_MENU_WELCOME_TITLE);
        printf("\t\t##################################################\n");
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 %s                 ##\n",LOGIN_SELECT_USER);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 1.%s                   ##\n",LOGIN_SELECT_STUDENT);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 2.%s                   ##\n",LOGIN_SELECT_TEACHER);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 3.%s                 ##\n",LOGIN_SELECT_ADMIN);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 4.%s                       ##\n",LOGOUT);
        printf("\t\t##################################################\n");

        printf("\n\n");
        printf("%s",SELECT_LOGIN_USER);
        
        ch=getchar();
        switch(ch) {
            case '1':
                ShowLoginMenu(STUDENT);
                break;
            case '2':
                ShowLoginMenu(TEACHER);
                break;
            case '3':
                ShowLoginMenu(ADMINISTRATOR);
                break;
            case '4':
                ReleaseAppController();
                exit(0);
                break;
            default:
                break;
        }
    }
}
