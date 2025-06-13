//#pragma once这个宏有什么作用？为了避免同一个头文件被包含（include）多次，C/C++中有两种宏实现方式：一种是#ifndef方式；另一种是#pragma once方式。
#pragma once

//declspec(dllexport) 表示将一个函数声名为导出函数，就是说这个函数要被包含她的程序之外的程序调用。
#define DLL_EXPORT __declspec(dllexport)

//暴露此函数
DLL_EXPORT void hello();


//#ifdef __declspec
//
//extern "C" {
//
//#endif
//
//DLL_EXPORT void hello();
//
//#ifdef __declspec
//
//}
//
//#endif



