/*########################################################
##File Name: common.c
##Created Time:2016年01月05日 星期二 08时41分15秒
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
#include"../include/user.h"

char *random_uuid(char* buf) {
    const char *c = "89ab";
    char *p = buf;
    int n;
    for( n = 0; n < 16; ++n ){
        int b = rand()%255;
        switch( n ){
            case 6:
                sprintf(p, "4%x", b%15 );
                break;
            case 8:
                sprintf(p, "%c%x", c[rand()%strlen(c)], b%15 );
                break;
            default:
                sprintf(p, "%02x", b);
                break;
        }

        p += 2;
        switch( n ){
            case 3:
            case 5:
            case 7:
            case 9:
                *p++ = '-';
                break;
        }
    }    
    *p = 0;
    return buf;
}
