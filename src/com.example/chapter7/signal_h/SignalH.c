//signal.h 头文件定义了一个变量类型 sig_atomic_t、两个函数调用和一些宏来处理程序执行期间报告的不同信号。

///库变量
//sig_atomic_t  这是int类型，在信号处理程序中作为变量使用。它是一个对象的整数类型，该对象可以作为一个原子实体访问，即使存在异步信号时，该对象可以作为一个原子实体访问。

///库宏
//下面是头文件 signal.h 中定义的宏，这些宏将在下列两个函数中使用。SIG_ 宏与 signal 函数一起使用来定义信号的功能。
//SIG_DFL 默认的信号处理程序。
//SIG_ERR 表示一个信号错误。
//SIG_IGN 忽视信号。

///库函数
//void (*signal(int sig, void (*func)(int)))(int)   该函数设置一个函数来处理信号，即信号处理程序。
//int raise(int sig)    该函数会促使生成信号 sig。sig 参数与 SIG 宏兼容。

int main() {

    return 0;
}