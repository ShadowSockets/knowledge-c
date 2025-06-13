//C 标准库的 ctype.h 头文件提供了一些函数，可用于测试和映射字符。
//这些函数接受 int 作为参数，它的值必须是 EOF 或表示为一个无符号字符。
//如果参数 c 满足描述的条件，则这些函数返回非零（true）。如果参数 c 不满足描述的条件，则这些函数返回零。


/// 1   int isalnum(int c)
/// 该函数检查所传的字符是否是字母和数字。

/// 2	int isalpha(int c)
/// 该函数检查所传的字符是否是字母。

/// 3	int iscntrl(int c)
/// 该函数检查所传的字符是否是控制字符。

/// 4	int isdigit(int c)
/// 该函数检查所传的字符是否是十进制数字。

/// 5	int isgraph(int c)
/// 该函数检查所传的字符是否有图形表示法。

/// 6	int islower(int c)
/// 该函数检查所传的字符是否是小写字母。

/// 7	int isprint(int c)
/// 该函数检查所传的字符是否是可打印的。

/// 8	int ispunct(int c)
/// 该函数检查所传的字符是否是标点符号字符。

/// 9	int isspace(int c)
/// 该函数检查所传的字符是否是空白字符。

/// 10	int isupper(int c)
/// 该函数检查所传的字符是否是大写字母。

/// 11	int isxdigit(int c)
///该函数检查所传的字符是否是十六进制数字。

/// 12  int tolower(int c)
///该函数把大写字母转换为小写字母。

/// 13	int toupper(int c)
///该函数把小写字母转换为大写字母。


#include <ctype.h>
#include <stdio.h>

int main() {

    char s = tolower('C');
    printf("%c ", s);

    char a = toupper('a');
    printf("%c ", a);

    return 0;
}
