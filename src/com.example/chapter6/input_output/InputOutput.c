//C 输入 & 输出
//    当我们提到输入时，这意味着要向程序填充一些数据。输入可以是以文件的形式或从命令行中进行。
//    C 语言提供了一系列内置的函数来读取给定的输入，并根据需要填充到程序中。
//
//当我们提到输出时，这意味着要在屏幕上、打印机上或任意文件中显示一些数据。C 语言提供了一系列内置的函数来输出数据到计算机屏幕上和保存数据到文本文件或二进制文件中。


//标准输入	    stdin	    键盘
//标准输出	    stdout	    屏幕
//标准错误	    stderr	    您的屏幕

//stdio.h 是一个头文件 (标准输入输出头文件) and #include 是一个预处理命令，用来引入头文件。 当编译器遇到 printf() 函数时，如果没有找到 stdio.h 头文件，会发生编译错误。

#include <stdio.h>

int main() {
    void getCharAndPutChar();
    getCharAndPutChar();

    void getsAndPuts();
    getsAndPuts();

    void scanfAndPrintf();
    scanfAndPrintf();

    return 0;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//getchar() & putchar() 函数
//int getchar(void) 函数从屏幕读取下一个可用的字符，并把它返回为一个整数。这个函数在同一个时间内只会读取一个单一的字符。
//您可以在循环内使用这个方法，以便从屏幕上读取多个字符。
//
//int putchar(int c) 函数把字符输出到屏幕上，并返回相同的字符。这个函数在同一个时间内只会输出一个单一的字符。
//您可以在循环内使用这个方法，以便在屏幕上输出多个字符。
void getCharAndPutChar() {
    int c;
    printf("Enter a value :");
    c = getchar();
    printf("\nYou entered :");
    putchar(c);
    printf("\n");
}
//当上面的代码被编译和执行时，它会等待您输入一些文本，当您输入一个文本并按下回车键时，程序会继续并只会读取一个单一的字符

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//gets() & puts() 函数
//char *gets(char *s) 函数从 stdin 读取一行到 s 所指向的缓冲区，直到一个终止符或 EOF。
//
//int puts(const char *s) 函数把字符串 s 和一个尾随的换行符写入到 stdout。
void getsAndPuts() {
    char str[100];
    printf("Enter a value:");
    gets_s(str, 100);
    printf("\nYou entered:");
    puts(str);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void scanfAndPrintf() {
    char str[100];
    int i;
    printf("Enter a value :");
    scanf_s("%s %d", str, i);
    printf("You entered: %s %d", str, i);
    printf("\n");
//    在这里，应当指出的是，scanf() 期待输入的格式与您给出的 %s 和 %d 相同，这意味着您必须提供有效的输入，
//    比如 "paramspec integer"，如果您提供的是 "paramspec paramspec" 或 "integer integer"，它会被认为是错误的输入。
//    另外，在读取字符串时，只要遇到一个空格，scanf() 就会停止读取，所以 "this is test" 对 scanf() 来说是三个字符串。
}
