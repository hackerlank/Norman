/*########################################################
##File Name: head.h
##Created Time:2016年1月04日 星期一 15时18分25秒
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

#ifndef _CHATSERVER_H
#define _CHATSERVER_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<sys/stat.h>
#include<getopt.h>
#include<sys/types.h>
#include<sys/syscall.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/mman.h>
#include<sys/ioctl.h>
#include<dirent.h>
#include<sys/time.h>
#include<signal.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/msg.h>
#include<sys/shm.h>
#include<pthread.h>
#include<semaphore.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/epoll.h>

#include "cjson.h"
#define gettid() syscall(__NR_gettid)

/*const*/

#define DEFAULT_SERVER          "127.0.0.1"
#define DEFAULT_PORT            8081
#define DEFAULT_CONNUM          100
#define DEFAULT_THREADNUM       100

#define DEFAULT_CFGPATH         "../conf/chatroom.cfg"

enum packtype{
    PACKTYPE_REQUEST = 1,
    PACKTYPE_RESPONE = 2
};

enum event{
    EVENT_REGISTER = 1,
    EVENT_LOGIN = 2,
    EVENT_LOGOUT = 3,
    EVENT_QUERY = 4
};

struct signup{
    char username[64];
    char passwd[128];
};

struct signin{
    char username[64];
    char passwd[128];
};

struct signout{
    char username[64];
};

union packbody{
    struct signup signup;
    struct signin signin;
    struct signout signout;
};

struct didi_packmsg_s{
    int packtype;
    int event;
    char version[8];
    char reqId[37];
    union packbody packbody;
};

typedef struct didi_packmsg_s didi_packmsg_t;

int didi_create_regmsg(cJSON** root,didi_packmsg_t pg);

int didi_release_json(cJSON** root);

char* didi_convert_json(cJSON** root);

char* didi_ufconvert_json(cJSON** root);

cJSON* didi_convert_string(char *string);

cJSON* didi_getjson_node(cJSON** root,const char* node);

cJSON* didi_getitem_node(cJSON** node,const char* item);

char *random_uuid(char *buf);
#endif
