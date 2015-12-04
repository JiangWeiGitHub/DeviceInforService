#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../header/order.h"
#include"../header/DeviceInforService.h"

typedef void(*porder)(void);
typedef struct _p_order{
	char *order_name;
	porder order_fun;
}p_order;

p_order order_table[] = { 
	{ "reboot",reboot },
	{ "poweroff",poweroff },
	{ NULL,NULL }
};

//execute signal function
void sig_fun(int signo){
	printf("receive signal %d\n",signo);
	close(sockfd);
	exit(1);
}

//找到相应函数指针并执行函数
int run_order(const char* order){
	int i = 0;

	for(i=0;order_table[i].order_name != NULL;i++){
		if(!strcmp(order_table[i].order_name,order)){
			order_table[i].order_fun();
			break;
		}
	}

	return 0;
}

void reboot(void){
	printf("reboot\n");
}

void poweroff(void){
	printf("poweroff\n");
}
