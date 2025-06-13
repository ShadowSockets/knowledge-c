/// 计算机中检测文件结尾方法的一种方法：在文件的末尾放特殊的字符标记结尾。
///
/// 在C语言中，使用getchar()读取文件，检测到末尾时会返回一个特殊值，即返回EOF。使用
///
/// scanf()函数时同样返回EOF。
///
/// 我们不需要定义EOF，EOF在头文件stdio.h中定义，通常EOF被定义为-1。
///
/// 在进行键盘输入时，同样可以使用EOF作为输入的结尾条件，在Windows中就使用快捷键Ctrl+z，作为文件结尾信号。如下边的示例：

#include <stdio.h>


int main(void) {

    char ch;

    while (ch = getchar() != EOF) {
        putchar(ch);
    }

    return 0;
}

/// 上述示例中，在while循环中使用getchar()函数，不断读取字符，将读取到的字符赋值给ch变量，
/// 直到输入EOF字符结束，这里的EOF不能输入EOF三个字符，在Windows中，当我们输入Ctrl+z时，就会识别为EOF，就会结束输入。