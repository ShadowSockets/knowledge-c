#include <stdio.h>
#include <string.h>

int main() {

    char str[80] = "This is - www.runoob.com - website";
    const char s[2] = "-";

    char *token;

    //获取第一个字符串
    token = strtok(str, s);

    //继续获取其他的字符串
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, s);
    }

    return 0;
}