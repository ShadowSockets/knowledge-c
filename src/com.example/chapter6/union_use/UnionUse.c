/// C 共用体
/// 共用体是一种特殊的数据类型，允许您在相同的内存位置存储不同的数据类型。您可以定义一个带有多成员的共用体，
/// 但是任何时候只能有一个成员带有值。共用体提供了一种使用相同的内存位置的有效方式。

#include <stdio.h>
#include <string.h>

union Data {
    int i;
    float f;
    char str[20];
};

//现在，Data 类型的变量可以存储一个整数、一个浮点数，或者一个字符串。这意味着一个变量（相同的内存位置）可以存储多个多种类型的数据。
//您可以根据需要在一个共用体内使用任何内置的或者用户自定义的数据类型。
//
//共用体占用的内存应足够存储共用体中最大的成员。例如，在上面的实例中，Data 将占用 20 个字节的内存空间，
//因为在各个成员中，字符串所占用的空间是最大的。下面的实例将显示上面的共用体占用的总内存大小：



int main() {

    //共用体占用内存，是成员变量占用最大的那个
    union Data data;
    printf("%d byte \n", sizeof(data)); // 20

    ///////////////////////////////////////////////////////////////////////////////////////////////////////
    data.i = 10;
    data.f = 220.5f;
    strcpy(data.str, "c programming");

    printf("[1]data.i : %d \n", data.i);
    printf("[1]data.f : %f \n", data.f);
    printf("[1]data.str : %s \n", data.str);
//    [1]data.i : 1919950947
//    [1]data.f : 4756195551848466478234509246464.000000
//    [1]data.str : c programming

    // 在这里，我们可以看到共用体的 i 和 f 成员的值有损坏，因为最后赋给变量的值占用了内存位置，
    // 这也是 str 成员能够完好输出的原因。现在让我们再来看一个相同的实例，这次我们在同一时间只使用一个变量，这也演示了使用共用体的主要目的：

    data.i = 10;
    printf("[2]data.i : %d \n", data.i);
    data.f = 220.5f;
    printf("[2]data.f : %f \n", data.f);
    strcpy(data.str, "c programming");
    printf("[2]data.str : %s \n", data.str);
//    [2]data.i : 10
//    [2]data.f : 220.500000
//    [2]data.str : c programming
//    在这里，所有的成员都能完好输出，因为同一时间只用到一个成员。

    return 0;
}

