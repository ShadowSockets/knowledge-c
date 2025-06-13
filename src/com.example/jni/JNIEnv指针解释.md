两种代码风格（C/C++）
JavaVM 和 JNIEnv 在 C 语言环境下和 C++ 环境下调用是有区别的，主要表现在：

C风格：(*env)->NewStringUTF(env, “Hello World!”);
C++风格：env->NewStringUTF(“Hello World!”);

建议使用 C++ 风格，这也是大部分代码使用的形式。
注意：C++ 风格其实只是封装了 C 风格，使得调用更加简介方便。
————————————————




————————————————
JNIEnv
JNIEnv 表示 Java 调用 native 语言的环境，是一个封装了几乎全部 JNI 方法的指针。
JNIEnv 只在创建它的线程生效，不能跨线程传递，不同线程的 JNIEnv 彼此独立。
native 环境中创建的线程，如果需要访问 JNI，必须要调用 AttachCurrentThread 关联，并使用 DetachCurrentThread 解除链接。
————————————————


JNIEXPORT和JNICALL是JNI中定义的两个宏，JNIEXPORT标识了支持在外部程序代码中调用该动态库中的方法，JNICALL定义了函数调用时参数的入栈出栈约定。
