#include <stdio.h>
#include <Windows.h>

//使用动态库.dll的用法示例
typedef void(_stdcall* ExecFunc)(void);

int main(){

    //1.获取dll句柄。(公司环境和家用环境不一样)
    HMODULE dllHandle = LoadLibraryA("C:\\Users\\sxh\\CLionProjects\\c-college\\src\\com.example\\chapter_use_dll\\GenerateDll.dll");
    //HMODULE dllHandle = LoadLibraryA("D:\\Development\\cWorkSpace\\c-college\\src\\com.example\\chapter_use_dll\\GenerateDll.dll");
    if (dllHandle == NULL) return -1;

    //2.获取dll句柄中的函数。
    ExecFunc execFunc = (ExecFunc)GetProcAddress(dllHandle, "hello");
    if (execFunc == NULL) return -2;

    //3.执行函数
    execFunc();

    return 0;
}