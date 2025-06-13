
#include <stdio.h>
#include <string.h>
#include <malloc.h>

enum bool {
    false, true
};

int main() {

    char s1[] = {"123455"};
    printf("%s", s1);

    char *s2 = "123455";
    printf("%s \n", s2);

    //判断两个字符串是否相等
    int i = strcmp(s1, s2);
    printf("%d", i);


    //字符串拼接
    char src[50], dest[50];
    strcpy(src, "This is source");
    strcpy(dest, "This is destination");
    strcat(dest, src);
    printf("最终的目标字符串： |%s|", dest);

    return 0;
}


////////////////////////////////////////////////////////////////////////
void do_timeconsuming_work() {

}

void ss1(int lotsa) {
    for (int i = 0; i < lotsa; i++) {
        printf("\r%3d%%", (int) (100L * i) / lotsa);
        fflush(stdout);
        do_timeconsuming_work();
    }
    printf("\ndone.\n");
}

void ss2(int lotsa) {
    printf("working:");
    for (int i = 0; i < lotsa; ++i) {
        printf("%c\b", "|/-\\"[i % 4]);
        fflush(stdout);
        do_timeconsuming_work();
    }
    printf("done.\n");
}

////////////////////////////////////////////////////////////////////////


///二级指针
void s() {
    char **p = malloc(4 * sizeof(char *));
    if (p != NULL) {
        p[0] = malloc(5);
        p[1] = malloc(3);
        p[2] = malloc(2);
        p[3] = malloc(5);

        if (p[0] && p[1] && p[2] && p[3]) {
            strcpy(p[0], "this");
            strcpy(p[1], "is");
            strcpy(p[2], "a");
            strcpy(p[3], "test");
        }
    }
}


//这里的代码是正确的
int pstrcmp(const void *p1, const void *p2) {
    //char *point = "123";

    char *const *a = (char *const *) p1;
    char *const *b = (char *const *) p2;

    //*a = point;  编译不通过，因为该指针是const修饰，不能修改，是只读的；
    return strcmp(*a, *b);
}