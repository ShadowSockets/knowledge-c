///库变量
//1	size_t
//        是无符号整数类型，它是 sizeof 关键字的结果。
//2	clock_t
//        这是一个适合存储处理器时间的类型。
//3	time_t is
//        这是一个适合存储日历时间类型。
//4	struct tm
//        这是一个用来保存时间和日期的结构。

///库宏
//1	NULL
//        这个宏是一个空指针常量的值。
//2	CLOCKS_PER_SEC
//        这个宏表示每秒的处理器时钟个数。

///库函数
//1	char *asctime(const struct tm *timeptr)
//返回一个指向字符串的指针，它代表了结构 timeptr 的日期和时间。

//2	clock_t clock(void)
//返回程序执行起（一般为程序的开头），处理器时钟所使用的时间。

//3	char *ctime(const time_t *timer)
//返回一个表示当地时间的字符串，当地时间是基于参数 timer。

//4	double difftime(time_t time1, time_t time2)
//返回 time1 和 time2 之间相差的秒数 (time1-time2)。

//5	struct tm *gmtime(const time_t *timer)
//timer 的值被分解为 tm 结构，并用协调世界时（UTC）也被称为格林尼治标准时间（GMT）表示。

//6	struct tm *localtime(const time_t *timer)
//timer 的值被分解为 tm 结构，并用本地时区表示。

//7	time_t mktime(struct tm *timeptr)
//把 timeptr 所指向的结构转换为一个依据本地时区的 time_t 值。

//8	size_t strftime(char *str, size_t maxsize, const char *format, const struct tm *timeptr)
//根据 format 中定义的格式化规则，格式化结构 timeptr 表示的时间，并把它存储在 str 中。

//9	time_t time(time_t *timer)
//计算当前日历时间，并把它编码成 time_t 格式。


#include <stdio.h>

int main(int argc, char **argv) {

    printf("char byte = %d \n", sizeof(char)); // 1
    printf("int byte = %d \n", sizeof(int)); // 4
    printf("long byte = %d \n", sizeof(long)); // 4
    printf("long long byte = %d \n", sizeof(long long)); // 8
    struct test {
        char a;
        char b;
        int c;
    } x;
    x.a = 'a';
    x.b = 'b';
    x.c = 1;
    printf("%p \n", &x);
    printf("%p \n", &x.a); //点的优先级最高，所以表示取(x中a)的地址
    printf("%p \n", &x.b); //点的优先级最高，所以表示取(x中b)的地址
    printf("%p \n", &x.c); //点的优先级最高，所以表示取(x中c)的地址

//    0136FBD8
//    0136FBD8
//    0136FBD9
//    0136FBDC

/// 从上面例子可以看出，计算机内存是1字节，分配一个地址

    return 0;
}