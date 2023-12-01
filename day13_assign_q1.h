#ifndef __DEMO25_H
#define __DEMO25_H

#include <stdio.h>
#include <unistd.h>
#include <sys/msg.h>

#define MQ_KEY  0x00004321

typedef struct msg_op {
    long type;
    int num1;
    int num2;
}msg_op_t;

typedef struct msg_res {
    long type;
    int res;
}msg_res_t;

#define MSG_OP_TYPE     11
#define MSG_RES_TYPE    22

#define MSG_OP_SIZE     (sizeof(msg_op_t) - sizeof(long))
#define MSG_RES_SIZE    (sizeof(msg_res_t) - sizeof(long))

#endif
