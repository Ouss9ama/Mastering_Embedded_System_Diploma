#include<stdio.h>

#define debug 1
#ifdef debug
#define fun(state,...)\
   if(state==1){ printf("Function: %s, File name: %s, Line: %d\n",__func__,__FILE__,__LINE__);}\
                                   printf(__VA_ARGS__);
#else 
#define fun(state,...)
#endif
int uart_send()
{

fun(1,"Sending data ...\n");

}

int uart_recieve()
{

fun(1,"Receiving data ...\n");

}

int main()
{
fun(0,"main entry\n");
uart_send();
uart_recieve();
fun(0,"main exist\n");

}