#include "mesg.h"
mesg msg;

int main()
{
    int mq_id;
    int n;
    if((mq_id = msgget(MKEY1,PERMS|IPC_CREAT)) < 0)
    {
        perror("sender:Error creating message\n");
        exit(1);
    }
    msg.mtype = 1111L;
    n = read(0,msg.data,50);
    msg.data[n] = '\0';
    msgsnd(mq_id,&msg,50,0);
}