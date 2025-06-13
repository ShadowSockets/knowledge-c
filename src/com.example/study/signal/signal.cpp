#include <signal.h>

void func(int i){
    //do something
}

int main(){

    //使程序收到中断信号时，调用函数func
    signal(SIGINT,func);

    return 0;
}