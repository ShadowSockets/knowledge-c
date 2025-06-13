#include <stdio.h>
#include <string.h>
#include <ctype.h>


void switchCharacter() {
    //将数字转换为字符
    int i = 500;
    char str[20];
    int ret = sprintf(str, "%d", i);
    printf("%s \n length=%d \n", str, ret);
}

void split1() {
    char string[] = "this\thas\t\tmissing\tfield";
    char *p = string;
    while (1) {
        //strchr函数功能为在一个串中查找给定字符的第一个匹配之处。
        char *p2 = strchr(p, '\t');
        if (p2 != NULL)
            *p2 = '\0';
        printf("\"%s\" \n", p);
        if (p2 == NULL)
            break;
        p = p2 + 1;
    }
}


void split2() {
    char string[] = "this  is a \t\n test";
    char *p;

    //分解字符串为一组字符串。s为要分解的字符,delim为分割符号
    //strtok方法用了静态成员，所以第二次传NULL可以的；
    for (p = strtok(string, "\t\n"); p != NULL; p = strtok(NULL, " \t\n")) {
        printf(" \"%s\" \n", p);
    }
}


void split3() {
    char string[] = "hello";
    printf("%c", string[4]);

    printf("%d", string[5]); //打印编译器自动为字符串添加的结尾00000000

    //可以用单引号 斜杠1~127表示 127个ASCII字符
    char c1 = '\0';
    char c2 = '\1';
    char c3 = '\2';
    char c4 = '\3';
    char c5 = '\127';
    printf("%c", c5);
}



//获取当前日期或者时间
#include <time.h>

void time0() {
    time_t now;
    time(&now);
    printf("it`s %s", ctime(&now));

    //localtime和strftime的调用如下
    struct tm *tmp = localtime(&now);
    char fmtbuf[30];
    printf("it is %d:%02d:%02d\n",
           tmp->tm_hour, tmp->tm_min, tmp->tm_sec);

    strftime(fmtbuf, sizeof fmtbuf, "%A , %B %d %Y", tmp);
    printf("on %s\n", fmtbuf);
}


//这是一段计算1994年10月24日后90天的日期的代码片段
void time1() {
    struct tm tm1;
    tm1.tm_mon = 10 - 1;
    tm1.tm_mday = 24;
    tm1.tm_year = 1994 - 1990;
    tm1.tm_hour = tm1.tm_min = tm1.tm_sec = 0;
    tm1.tm_isdst = -1;

    //设置tm_isdst为-1有助于防止夏令时引起的转换问题。设置tm_hours为12也起同样作用。

    tm1.tm_mday += 90;

    if (mktime(&tm1) == -1)
        fprintf(stderr, "mktime failed\n");
    else
        printf("%d/%d/%d\n",
               tm1.tm_mon + 1, tm1.tm_mday, tm1.tm_year + 1990);
}


//下面是一段计算从2000年2月28日到3月1日的日值差的程序
void time3() {
    struct tm tm1, tm2;
    time_t t1, t2;

    tm1.tm_mon = 2 - 1;
    tm1.tm_mday = 28;
    tm1.tm_year = 2000 - 1900;
    tm1.tm_hour = tm1.tm_min = tm1.tm_sec = 0;
    tm1.tm_isdst = -1;

    tm2.tm_mon = 3 - 1;
    tm2.tm_mday = 1;
    tm2.tm_year = 2000 - 1900;
    tm2.tm_hour = tm2.tm_min = tm2.tm_sec = 0;
    tm2.tm_isdst = -1;

    t1 = mktime(&tm1);
    t2 = mktime(&tm2);

    if (t1 == -1 || t2 == -1) {
        fprintf(stderr, "mktime failed\n");
    } else {
        long d = (difftime(t2, t1) + 86400L / 2) / 86400L;
        printf("%ld\n", d);
    }
}


int main(int argc, char *argv[]) {
    switchCharacter();

    //split1();
    //split2();
    split3();

    time0();
    time1();

    return 0;
}