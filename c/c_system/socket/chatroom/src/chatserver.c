/*########################################################
##File Name: chatserver.c
##Created Time:2015年12月25日 星期五 17时04分03秒
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
#include"../include/chatserver.h"

int main(int argc,char *argv[]){
    SEVCF cf;
    USERINFO uinfo;
    SOCK sock;
    int i,ret,cfd;
    int nfound,len;
    char buf[1024];

    //初始化配置文件
    ret = nv_init_conf(&cf,DEFAULT_CFGPATH);
    if(-1 == ret){
        fprintf(stderr,"load %s conf error!\n",DEFAULT_CFGPATH);
        exit(2);
    }
    
    //printf("loaded conf successfuly!\n");
    //TODO:初始化数据库
    ret = nv_init_db(&uinfo,cf.dbpath);
    if(-1 == ret){
        fprintf(stderr,"init db error!\n");
        exit(2);
    }
    printf("init db %p successfuly!\n",uhead);
    //nv_print_all_user();

    //TODO:初始化互斥锁
    ret = nv_init_thread_mutex(&td.mutex);
    if(-1 == ret){
        fprintf(stderr,"init thread mutex failed!\n");
        exit(2);
    }

    ret = nv_init_thread_cond(&td.cond);
    if(-1 == ret){
        fprintf(stderr,"init mutex cond failed!\n");
        exit(2);
    }
    
    //TODO:初始化线程池
    ret = nv_init_thread_pool(&td);
    if(-1 == ret){
        fprintf(stderr,"init thread pool failed!\n");
        exit(2);
    }
    
    //TODO:创建SOCK服务器
    ret = nv_init_socket(&sock,cf.server_ip,cf.server_port,cf.server_connum);
    if(-1 == ret){
        fprintf(stderr,"init socket failed!\n");
        exit(2);
    }

    ret = nv_init_epoll(cf.server_threadnum);
    if(-1 == ret){
        fprintf(stderr,"init epoll failed!\n");
        exit(2);
    }
    len = sizeof(sock.sin);
    nv_add_epoll(sock.sfd);

    while(1){
        nfound = nv_found_epoll();
        if(nfound <0){
            perror("epoll_wait");
            continue;
        } else if(nfound == 0){
            fprintf(stderr,"time out!\n");
            continue;
        } else {
            for(i=0;i<nfound;i++){
                if(evs[i].data.fd == sock.sfd){
                    cfd = accept(sock.sfd,(struct sockaddr*)&sock.cin,(socklen_t*)&len);
                    printf("client ip=%s port=%d\n",inet_ntop(AF_INET,&sock.cin.sin_addr.s_addr,buf,15),ntohs(sock.cin.sin_port));
                    if(-1 == cfd){
                        perror("accept");
                        continue;
                    } else {
                        ev.data.fd = cfd;
                        nv_add_epoll(cfd);
                        continue;
                    }
                } else if(evs[i].events == EPOLLIN|EPOLLET){
                    nv_parse_msg(evs[i].data.fd);
                }
            }
        }
    }
    close(sock.sfd);
    return 0;
}


