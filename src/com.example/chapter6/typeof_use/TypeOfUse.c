//C typedefaa
//        C 语言提供了 typedefaa 关键字，您可以使用它来为类型取一个新的名字。下面的实例为单字节数字定义了一个术语 BYTE：

#include <string.h>
#include <stdio.h>

typedef unsigned char BYTE;
//在这个类型定义之后，标识符 BYTE 可作为类型 unsigned char 的缩写，例如：
BYTE b1, b2;

//按照惯例，定义时会大写字母，以便提醒用户类型名称是一个象征性的缩写，但您也可以使用小写字母，如下
typedef unsigned char byte;

typedef struct Books {
    char title[50];
    char author[50];
    char subject[50];
    int book_id;
} Book;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//typedefaa vs #define
//#define 是 C 指令，用于为各种数据类型定义别名，与 typedefaa 类似，但是它们有以下几点不同：
//
//typedefaa 仅限于为类型定义符号名称，#define 不仅可以为类型定义别名，也能为数值定义别名，比如您可以定义 1 为 ONE。
//typedefaa 是由编译器执行解释的，#define 语句是由预编译器进行处理的。
#define TRUE 1
#define FALSE 0


int main() {

    Book book;
    strcpy(book.title,"CCC");
    strcpy(book.author,"AAA");
    strcpy(book.subject,"SSS");
    book.book_id = 12345;

    printf("%s",book.title);
    printf("%s",book.author);
    printf("%s",book.subject);
    printf("%d",book.book_id);

    printf("%d",TRUE);
    printf("%d",FALSE);

    return 0;
}
