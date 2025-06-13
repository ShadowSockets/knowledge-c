//
// Created by alex on 2025/3/20.
//

#include "X.h"
#include <windows.h>

int main(){
    // 隐藏控制台窗口
    FreeConsole();
    // MessageBox 函数：显示弹窗
    MessageBoxW(NULL, L"KFC，疯狂星期4？", L"提示", MB_OK | MB_ICONQUESTION);
    return 0;
}