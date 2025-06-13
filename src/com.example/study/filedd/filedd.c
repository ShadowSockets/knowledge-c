#include <stdio.h>

int main()
{
    FILE *fp = NULL;

    //fp = fopen("/tmp/test.txt", "w+");  //linux系统
    fp = fopen("D:\\tmp", "w+");
    fprintf(fp, "This is testing for fprintf...\n");
    fputs("This is testing for fputs...\n", fp);
    fclose(fp);
}