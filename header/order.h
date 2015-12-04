#ifndef __ORDER_H__
#define __ORDER_H__

//excute signal function
void sig_fun(int signo);

//excute the order
int run_order(const char* order);

//reboot
void reboot(void);

//poweroff
void poweroff(void);
#endif
