#ifndef C_COLLEGE_DEMO_H
#define C_COLLEGE_DEMO_H


#define DLL_EXPORT __declspec(dllexport)
//C函数导出库的两种方式
//1、在需要导出的类名或函数名前面加__declspec(dllexport);
//2、declspec(dllexport) 表示将一个函数声名为导出函数，就是说这个函数要被包含它的程序之外的程序调用。
//3、或者在使用的地方用__declspec(dllimport);



DLL_EXPORT void hello();
DLL_EXPORT int add();

#endif
