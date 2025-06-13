//C 强制类型转换
//强制类型转换是把变量从一种类型转换为另一种数据类型。例如，如果您想存储一个 long 类型的值到一个简单的整型中，
//您需要把 long 类型强制转换为 int 类型。您可以使用强制类型转换运算符来把值显式地从一种类型转换为另一种类型，如下所示：

#include <stdio.h>

int main() {

    void typeCast1();
    void typeCast2();
    void typeCast3();

    typeCast1();
    typeCast2();
    typeCast3();

    return 0;
}


void typeCast1() {
    int sum = 17, count = 5;
    double mean;

    //强制类型转换、、要注意的是强制类型转换运算符的优先级大于除法，因此 sum 的值首先被转换为 double 型，然后除以 count，得到一个类型为 double 的值。
    mean = (double) sum / count;
    printf("value of mean: %lf \n", mean);
}

void typeCast2() {
    int i = 17;
    char c = 'c'; //ascii值是99
    int ss;
    ss = i + c; //因为编译器进行了整数提升，在执行实际加法运算时，把 'c' 的值转换为对应的 ascii 值。
    printf("value of ss : %d", ss);
}

void typeCast3() {
    int i = 17;
    char c = 'c'; //ascii值是99
    float sum;

    sum = i + c; //在这里，c 首先被转换为整数，但是由于最后的值是 float 型的，所以会应用常用的算术转换，编译器会把 i 和 c 转换为浮点型，并把它们相加得到一个浮点数。
    printf("value of sum : %f", sum);
}