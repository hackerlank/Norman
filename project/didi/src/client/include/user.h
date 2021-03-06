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
enum usertype{
    PERSONAL_USER = 1,
    DRIVERS_USERS = 2
};

enum responcode{
    REQUER_SUCCESS = 200,       //服务器已处理请求
    PASSWD_SUCCESS = 201,       //密码验证正确
    ORDER_SUCCESS = 202,
    TAKETOKEN_SUCCESS = 203,
    ORDHISTORY_SUCCESS = 210,

    SERVER_REFUSE = 403,        //
    USER_NOTEXIST = 404,        //用户不存在
    USER_EXIST = 405,           //用户已存在
    PASSWD_ERROR = 406,         //用户密码错误
    ORDER_ERROR= 407,
    TAKETOKEN_ERROR= 408,
    ORDHISTORY_ERROR= 410,
};

enum packtype{
    PACKTYPE_REQUEST = 1,
    PACKTYPE_RESPONE = 2
};

enum event{
    EVENT_REGISTER = 1,
    EVENT_LOGIN = 2,
    EVENT_LOGOUT = 3,
    EVENT_QUERY = 4,
    EVENT_MPASSWD = 5,
    EVENT_ORDER = 6,
    EVENT_TAKETOKEN = 7
};

struct signup{
    int usertype;
    char telphone[12];
    char nickname[64];
    char username[64];
    char passwd[128];
};

struct signin{
    int usertype;
    char telphone[12];
    char passwd[128];
};

struct signout{
    int usertype;
    char telphone[12];
};

struct mpasswd{
    int usertype;
    char telphone[12];
    char newpasswd[128];
};

struct order{
    int usertype;
    char starting[1024];
    char destination[1024];
    char userphone[12];
    char driverphone[12];
    char starttime[32];
    char arrivaltime[32];
    char payment[128];
};

struct query{
    int usertype;
    char telphone[12];
};


union packbody{
    struct signup signup;
    struct signin signin;
    struct signout signout;
    struct mpasswd mpasswd;
    struct order order;
    struct query query;
};

struct didi_packmsg_s{
    int packtype;
    int event;
    char version[8];
    char reqId[37];
    union packbody packbody;
};

int sfd;
char loginuser[12];
typedef struct didi_packmsg_s didi_packmsg_t;

int didi_create_regmsg(cJSON** root,didi_packmsg_t pg);

int didi_release_json(cJSON** root);

char* didi_convert_json(cJSON** root);

char* didi_ufconvert_json(cJSON** root);

cJSON* didi_convert_string(char *string);

cJSON* didi_getjson_node(cJSON** root,const char* node);

cJSON* didi_getitem_node(cJSON** node,const char* item);
//////////////////////////////////////////////////////
char *random_uuid(char *buf);
void handle_message();
int init_socket();
void print_message_body(cJSON* root);
void generate_curtime(char* s);
/////////////////////////////////////
void register_user();
void login();
void logout();
////////////////////////////////////////
void* thread_read(void* argv);
void* take_order(void* argv);
void* thread_write(void* argv);
#endif

