#include "demo25.h"

int main() {
    int mqid, ret;
    msg_op_t mop;
    msg_res_t mres;

    mqid = msgget(MQ_KEY, 0);
    if(mqid < 0) {
        perror("msgget() failed");
        _exit(0);
    }

    ret = msgrcv(mqid, &mop, MSG_OP_SIZE, MSG_OP_TYPE, 0);
    if(ret == 0)
        printf("operands received: %d, %d\n", mop.num1, mop.num2);

    mres.res = mop.num1 + mop.num2;
    mres.type = MSG_RES_TYPE;

    ret = msgsnd(mqid, &mres, MSG_RES_SIZE, 0);
    if(ret == 0)
        printf("result sent: %d\n", mres.res);

    return 0;
}
