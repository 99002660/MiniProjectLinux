#include<stdio.h>
#include <pthread.h>
#include <mqueue.h>
#include <fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<semaphore.h>
void * queue_reciever(void * args) {
	mqd_t mq;
	char buf[8192];
	struct mq_attr attr;
	attr.mq_msgsize=1028;
	attr.mq_maxmsg=20;
	int ret,prio;
	mq = mq_open("/queue",O_RDONLY|O_CREAT,0666,&attr);
	if(mq < 0) {
		perror("mq_open");
		exit(2);
	}

	ret = mq_receive(mq,buf,sizeof(buf),&prio);
	if(ret<0){
		perror("mq_Rx");
		exit(2);
	}
	buf[ret] = '\0';
	printf("Tkts sold :%s\n",buf);
	mq_close(mq);
	pthread_exit(NULL);
}


int main() {
	pthread_t reciever;
	pthread_create(&reciever, NULL, &queue_reciever, NULL);
	pthread_join(reciever,NULL);
	return 0;
}
