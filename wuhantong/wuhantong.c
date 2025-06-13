//
// Created by Alex on 2019/11/29.
//
#include <stdio.h>
#include <math.h>
#include <Windows.h>

//定义函数指针
typedef int(__stdcall *ExecFunc)(int, const char *, int *, char **);

int main(int argc, char **argv) {
    if (argc != 2) {
        return -1;
    }
    const char *request = argv[1];
    char *outData = 0;
    int outLen = 0;

    //printf("CWD=%s, dllHandle=%d, execProc=%d\n", cwd, (int)dllHandle, (int)fpExecFunc);
    //char* request = "AA1AAC0000000913000000102019040813385290271101123456785FCC";
    //char* request = "AA09AB20190408134328EFCC";
    //printf("Send: %s\n", request);

    HMODULE dllHandle = LoadLibraryA("PosCls.dll");
    ExecFunc fpExecFunc = (ExecFunc) GetProcAddress(dllHandle, "Exec");
    int exitCode = fpExecFunc(24, request, &outLen, &outData);

    if (outData)
        printf("%d,%s", outLen, outData);

    return exitCode;
}
