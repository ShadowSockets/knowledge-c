#include <stdio.h>
#include <string.h>

//在 C 语言中，字符串实际上是使用 null 字符 \0 终止的一维字符数组。因此，一个以 null 结尾的字符串，包含了组成字符串的字符。
//
//下面的声明和初始化创建了一个 RUNOOB 字符串。由于在数组的末尾存储了空字符，所以字符数组的大小比单词 RUNOOB 的字符数多一个。
char site[7] = {'R', 'U', 'N', 'O', 'O', 'B', '\0'};


//依据数组初始化规则，您可以把上面的语句写成以下语句：
char site1[] = "RUNOOB";


int main() {

    printf("%s \n", site);
    printf("%s \n", site1);

    void stringOperation();
    stringOperation();


    return 0;
}


//strcpy(s1, s2);
//复制字符串 s2 到字符串 s1。
//
//strcat(s1, s2);
//连接字符串 s2 到字符串 s1 的末尾。
//
//strlen(s1);
//返回字符串 s1 的长度。
//
//strcmp(s1, s2);
//如果 s1 和 s2 是相同的，则返回 0；如果 s1<s2 则返回小于 0；如果 s1>s2 则返回大于 0。
//
//strchr(s1, ch);
//返回一个指针，指向字符串 s1 中字符 ch 的第一次出现的位置。
//
//strstr(s1, s2);
//返回一个指针，指向字符串 s1 中字符串 s2 的第一次出现的位置。
void stringOperation() {
    char str1[14] = "baidu";
    char str2[14] = "google";
    char str3[14];
    int len;

    //复制str1 到 str3
    strcpy(str3, str1);
    printf("str3 = %s \n", str3);

    //连接str1 和 str2
    strcat(str1, str2);
    printf("str1 = %s \n", str1);

    //连接后，str1的总长度
    len = strlen(str1);
    printf("str len = %d \n", len);
}
