/*########################################################
##File Name: AdminMenu.c
##Created Time:2015年11月30日 星期一 19时58分22秒
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
#include <stdlib.h>
#include "AdminMenu.h"
#include "../utils/DataConst.h"

void ShowAdminMenu() {
    char ch;

    while(1) {
        system("clear");
        printf("\t\t##################################################\n");
        printf("\t\t##              %s            ##\n",MAIN_MENU_WELCOME_TITLE);
        printf("\t\t##################################################\n");
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 1.%s               ##\n",ADD_USER_INFOMATION);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 2.%s               ##\n",MODIFY_USER_INFOMATION);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 3.%s               ##\n",DEL_USER_INFOMATION);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 4.%s               ##\n",SEARCH_USER_INFOMATION);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 5.%s               ##\n",RETURN_PARENT_FOLDER);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 6.%s                       ##\n",LOGOUT);
        printf("\t\t##################################################\n");
        
        printf("\n\n");
        printf("%s",SELECT_MENU_ELEMENT);
        getchar();
        ch = getchar();
        switch(ch) {
            case '1':
                break;
            case '2':
                break;
            case '3':
                break;
            case '4':
                break;
            case '5':
                break;
            case '6':
                exit(0);
                break;
            default:
                break;
        }
    }   
}
