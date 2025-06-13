//#pragma用于指示编译器完成一些特定的动作
//如果一个头文件被引用两次，编译器会处理两次头文件的内容，这将产生错误。
//#pragma once这个宏有什么作用？为了避免同一个头文件被包含（include）多次，C/C++中有两种宏实现方式：一种是#ifndef方式；另一种是#pragma once方式。
#pragma once

//declspec(dllexport) 表示将一个函数声名为导出函数，就是说这个函数要被包含她的程序之外的程序调用。
#define DLL_EXPORT __declspec(dllexport)

//暴露此函数，可供GetProcAddress方法获取。
DLL_EXPORT void hello(void);


/**
dllexport
        字面意思暴露dll中的变量或方法
编译dll文件的时候,在dll头文件声明的变量名称前添加dllexport。表明这些东西可以被其他工程使用，即是把 dll中的相关代码(类，函数，全局变量)暴露出来为以后其他应用程序使用。

dllimport
        字面意思插入dll中的变量或方法
是在其他工程需要使用dll内相关内容时使用的关键字。当其他工程要使用dll 内部代码(类，函数，全局变量)时，只需要在dll头文件中声明的变量名称前添加dllimport关键字即可,作用是把dll中的相关代码插入到应用程序中。

_declspec(dllexport)与_declspec(dllimport)是相互呼应，只有在dll内部用dllexport作了声明，才能在外部函数中用dllimport导入相关代码。

 */


/**
  作为动态库，在需要导出的类或函数前必须使用关键字__declspec(dllexport)声明，因此动态库需要定义宏DLL_EXPORTS(使用VisualStudio建立动态库工程时，此宏已经定义好)。

 可以省略dllimport???
 但MSDN文档里面，对于 __declspec(dllimport)的说明让人感觉有点奇怪，先来看看MSDN里面是怎么说的：
 不使用 __declspec(dllimport)也能正确编译代码，但使用 __declspec(dllimport) 使编译器可以生成更好的代码。
 编译器之所以能够生成更好的代码，是因为它可以确定函数是否存在于 DLL 中，这使得编译器可以生成跳过间接寻址级别的代码，
 而这些代码通常会出现在跨DLL 边界的函数调用中。但是，必须使用 __declspec(dllimport) 才能导入 DLL 中使用的变量。


 总结如下：
 对于动态库本身必须使用关键字__declspec(dllexport)，对于应用程序，如果不使用动态库导出的变量，
 不使用关键字__declspec(dllimport)也可以保证动态库的正常使用，但实际使用中，
 还是建议应用程序使用关键字__declspec(dllimport)，具体原因，还是上面MSDN的那段话。

 */




























//#ifdef DLL_EXPORT
//
//extern "C" {
//
//#endif
//
//DLL_EXPORT void hello();
//
//#ifdef DLL_EXPORT
//
//}
//
//#endif



