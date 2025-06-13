//使用宏定义方式定义
#include <stdio.h>

#define MONDAY 1
#define TUESDAY 2
#define WEDNESDAY 3
#define THURSDAY 4
#define FRIDAY 5
#define SATURDAY 6
#define SUNDAY 7

//##############################################################################################################################################

//使用枚举方式定义
enum DAY {
    MON = 1, TUE, WED, THU, FRI, SAT, SUN
};
//这样看起来是不是更简洁了。
//注意：第一个枚举成员的默认值为整型的 0，后续枚举成员的值在前一个成员上加 1。我们在这个实例中把第一个枚举成员的值定义为 1，第二个就为 2，以此类推。


//##############################################################################################################################################
//可以在定义枚举类型时改变枚举元素的值：
enum SEASON {
    spring, summer = 3, autumn, winter
};
//没有指定值的枚举元素，其值为前一元素加 1。也就说 spring 的值为 0，summer 的值为 3，autumn 的值为 4，winter 的值为 5

//##############################################################################################################################################


/// 枚举变量的定义
///         前面我们只是声明了枚举类型，接下来我们看看如何定义枚举变量。
///
/// 我们可以通过以下三种方式来定义枚举变量

///1、先定义枚举类型，再定义枚举变量
enum X {
    A = 1, B, C, D, E
};
enum X x;

///2、定义枚举类型的同时定义枚举变量
enum Y {
    A1 = 1, A2, A3, A4, A5
} y;

///3、省略枚举名称，直接定义枚举变量
enum {
    Z1 = 1, Z2, Z3, Z4, Z5
} z;

int main() {

    //枚举的使用
    enum DAY day;
    day = WED;
    printf(" %d \n", day);

    //遍历枚举
    for (x = A; x <= E; x++) {
        printf("enum %d ", x);
    }
    //以下枚举类型不连续，这种枚举无法遍历。
    //enum
    //{
    //    ENUM_0,
    //    ENUM_10 = 10,
    //    ENUM_11
    //};


    void switchFun(); //声明函数
    switchFun(); //调用函数

    void castFun();
    castFun();

    return 0;
}


void switchFun() {
    enum color {
        red = 1, green, blue
    };

    enum color favorite_color;
    printf("please input color: \n");
    //c语言中的%u是输入输出格式说明符,表示按unsigned int格式输入或输出数据。
    scanf_s("%u", &favorite_color);

    switch (favorite_color) {
        case red:
            printf("red");
            break;
        case green:
            printf("green");
            break;
        case blue:
            printf("blue");
            break;
        default:
            printf("default");
    }
}


//将整数转换为枚举
void castFun() {

    //定义枚举类型的同时定义枚举变量
    enum day {
        d1, d2, d3, d4, d5
    } workday;

    int a = 1;
    enum day c;
    c = (enum day) a; //类型转换
    printf("[[ %d ]]", c);
}

