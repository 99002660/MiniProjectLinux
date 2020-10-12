#include<stdio.h>
#include <pthread.h>
#include <mqueue.h>
#include <fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<semaphore.h>
void* queue_sender(void* args) {
	mqd_t mq;
	int ret,len,tickets;
	char str[4];
	mq = mq_open("/queue",O_WRONLY|O_CREAT,0666,NULL);
	if(mq < 0) {
		perror("mq_open");
		exit(2);
	}
	printf("Number of tkts sold:");
	//scanf("%d",&tickets);
	tickets = 12;
	sprintf(str, "%d",tickets);
	len= strlen(str);
	ret = mq_send(mq,str,len,5);
	if(ret<0){
		perror("mq_Tx");
		exit(2);
	}
	mq_close(mq);
	pthread_exit(NULL);
}

int main() {
	pthread_t sender;
	pthread_create(&sender,NULL,&queue_sender,NULL);
	pthread_join(sender,NULL);
	return 0;
}
