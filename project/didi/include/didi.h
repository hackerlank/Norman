/*########################################################
##File Name: didi.h
##Created Time:2015年12月29日 星期二 20时49分13秒
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

#ifndef _didi_H
#define _didi_H
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

#include<zlog.h>
#include<mysql/mysql.h>

//prompt
#define CUSTOM_PROMPT_IP        "ip not found!"
#define CUSTOM_PROMPT_DB        "host not found!"
#define CUSTOM_PROMPT_DBNAME    "dbname not found!"
#define CUSTOM_PROMPT_DBUSER    "db username not found!"
#define CUSTOM_PROMPT_DBPASSWD  "db passwd not found!"
#define CUSTOM_PROMPT_LOG       "log path not found!"
//server
#define CONF_SERVER_IP          "server:hostname"
#define CONF_SERVER_PORT        "server:port"
#define CONF_SERVER_CONNUM      "server:connect"
#define CONF_SERVER_THREADNUM   "server:threadnum"
//db
#define CONF_DB_HOSTNAME        "mysql:hostname"
#define CONF_DB_NAME            "mysql:dbname"
#define CONF_DB_USERNAME        "mysql:username"
#define CONF_DB_PASSWD          "mysql:passwd"
//log
#define CONF_LOG_PATH           "log:logconf"

#define DEFAULT_SERVER          "0.0.0.0"
#define DEFAULT_PORT            8080
#define DEFAULT_CONNUM          100
#define DEFAULT_THREADNUM       100

#define DEFAULT_CFGPATH         "../conf/didi.conf"

struct didi_server_s{
    const char *hostip;
    int  port;
    int  connect;
    int  threadnum;
};

struct didi_mysql_s{
    const char* hostname;
    const char* dbname;
    const char* username;
    const char* passwd;
};

struct didi_log_s{
    const char* logconf;
};

struct didi_conf_s{
    struct didi_server_s server;
    struct didi_mysql_s didimysql;
    struct didi_log_s log;
};

//////////////////////////////////////////////////

struct didi_user_s{

};

struct didi_driver_s{

};

typedef void*(*DIDI_FUNC_POINT)(void* argv);
struct didi_tasklist_s{
    DIDI_FUNC_POINT didi_func;
    void* argv;
    struct didi_tasklist_s *next;
};

struct didi_thread_s{
    int eh;
    struct epoll_event ev,evs[10];
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int max_thread_num;
    pthread_t pthread_id[DEFAULT_THREADNUM];
    struct didi_tasklist_s *qhead;
    struct didi_tasklist_s *qtail;
};

/* types */
typedef struct didi_server_s didi_server_t;
typedef struct didi_mysql_s didi_mysql_t;
typedef struct didi_log_s didi_log_t;
typedef struct didi_conf_s didi_conf_t;

typedef struct didi_user_s didi_user_t;
typedef struct didi_driver_s didi_driver_t;
typedef struct didi_tasklist_s didi_tasklist_t;
typedef struct didi_thread_s didi_thread_t;

//Global Var
didi_thread_t didi_td;
didi_user_t *didi_user_head;
didi_driver_t *didi_driver_head;


//function
int didi_conf_init(didi_conf_t *cf,const char* cpath);

int didi_log_init(zlog_category_t **c,const char* logpath);
int didi_log_release();

//db
int didi_db_init(MYSQL *db,didi_mysql_t didimysql,zlog_category_t **c);
int didi_db_release(MYSQL *db,zlog_category_t **c);
void query_online_user();
void query_online_driver();


int didi_cache_init(MYSQL *db,zlog_category_t **c);
int init_user_linklist();
int init_driver_linklist();
int didi_cache_release(zlog_category_t **c);

//loop
int didi_iniit_pool(didi_thread_t* didi_td);
int didi_init_cond(pthread_cond_t* cond);
int didi_init_mutex(pthread_mutex_t* mutex);
int didi_init_loop(zlog_category_t **c);

void* didi_thread_wakeup(void* argv);
#endif
