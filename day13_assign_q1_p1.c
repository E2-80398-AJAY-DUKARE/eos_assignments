#include "demo25.h"

int main() {
    int mqid, ret;
    msg_op_t mop;
    msg_res_t mres;

    mqid = msgget(MQ_KEY, IPC_CREAT|0600);
    if(mqid < 0) {
        perror("msgget() failed");
        _exit(0);
    }

    printf("enter two numbers: ");
    scanf("%d%d", &mop.num1, &mop.num2);
    mop.type = MSG_OP_TYPE;

    ret = msgsnd(mqid, &mop, MSG_OP_SIZE, 0);
    if(ret == 0)
        printf("operands sent: %d, %d\n", mop.num1, mop.num2);

    ret = msgrcv(mqid, &mres, MSG_RES_SIZE, MSG_RES_TYPE, 0);
    if(ret > 0)
        printf("result received: %d\n", mres.res);

    msgctl(mqid, IPC_RMID, NULL);
    return 0;
}








