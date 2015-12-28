/*########################################################
##File Name: socket_client.c
##Created Time:2015年12月21日 星期一 15时49分12秒
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
#include "head.h"

int main(){
    int sfd,ret;
    struct sockaddr_in sin;
    struct sockaddr_in cin;
    int len;
    char buf[1024]= {0};

    sfd = socket(AF_INET,SOCK_DGRAM,0);
    if(sfd == -1){
        perror("socket");
        return -1;
    }

    sin.sin_family = AF_INET;
    sin.sin_port = htons(5002);

    if(inet_pton(AF_INET,"127.0.0.1",&sin.sin_addr.s_addr)<=0){
        perror("inet_pton");
        return -1;
    }

    while(1){
        len = sizeof(sin);
        ret = read(0,buf,1024);
        buf[ret] = 0;
        printf("send to \n");
        sendto(sfd,buf,strlen(buf),0,(struct sockaddr*)&sin,len);
    }
    close(sfd);

    return 0;
}
