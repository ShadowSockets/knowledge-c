//为什么需要结构体?   因为普通的基本类型变量，无法表达复杂的事物
//什么叫做结构体?     用户根据自己需要，定义的复合数据类型

//C 结构体
//C 数组允许定义可存储相同类型数据项的变量，结构是 C 编程中另一种用户自定义的可用的数据类型，它允许您存储不同类型的数据项。


/// 定义结构
///         为了定义结构，您必须使用 struct 语句。struct 语句定义了一个包含多个成员的新的数据类型，struct 语句的格式如下：
///
/// struct tag {
///     member-list
///     member-list
///     member-list
///     ...
/// } variable-list ;
///
/// tag 是结构体标签。
/// member-list 是标准的变量定义，比如 int i; 或者 float f，或者其他有效的变量定义。
/// variable-list 结构变量，定义在结构的末尾，最后一个分号之前，您可以指定一个或多个结构变量。

///========结构体变量的作用,请看以下例子就知道了=========
/// 结构体变量的初始化 【和其它类型变量一样，对结构体变量可以在定义时指定初始值。】
/// struct Books {
///     char title[50];
/// } book = {"C 语言"} , *bk;
///
/// int main() {
///     printf("title : %s", book.title);
///     printf("%p ", bk);
/// }




#include <stdio.h>
#include <string.h>

struct Books {
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
} book;

//////////////////////////////////////////////////////////////////////////////////////////////////

//此声明声明了拥有3个成员的结构体，分别为整型的a，字符型的b和双精度的c
//同时又声明了结构体变量s1
//这个结构体并没有标明其标签
struct {
    int a;
    char b;
    double c;
} s1;


//此声明声明了拥有3个成员的结构体，分别为整型的a，字符型的b和双精度的c
//结构体的标签被命名为SIMPLE,没有声明变量
struct SIMPLE {
    int a;
    char b;
    double c;
};

//用SIMPLE标签的结构体，另外声明了变量t1、t2、t3
struct SIMPLE t1, t2[20], *t3;


//也可以用typedef创建新类型
typedef struct {
    int a;
    char b;
    double c;
} Simple2;

//现在可以用Simple2作为类型声明新的结构体变量
Simple2 u1, u2[20], *u3;

//////////////////////////////////////////////////////////////////////////////////////////////////

//此结构体的声明包含了其他的结构体
struct COMPLEX {
    char string[100];
    struct SIMPLE a;
};

//此结构体的声明包含了指向自己类型的指针
struct NODE {
    char string[100];
    struct NODE *next_node;
};

//////////////////////////////////////////////////////////////////////////////////////////////////
//如果两个结构体互相包含，则需要对其中一个结构体进行不完整声明，如下所示

struct B; //对结构体B进行不完整声明

//结构体A中包含指向结构体B的指针
struct A {
    struct B *partner;
};

//结构体B中包含指向结构体A的指针，在A声明完后，B也随之进行声明
struct B {
    struct A *partner;
};

//////////////////////////////////////////////////////////////////////////////////////////////////
//结构体变量的初始化
struct Beans {
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
} bean = {"nothing", "alex", "english", 123};


//////////////////////////////////////////////////////////////////////////////////////////////////

int main() {

    //访问结构体
    printf("%s %d", bean.author, bean.book_id);

    //通过结构体变量访问结构体
    printf("%s", book.subject);

    printf("\n %p ", u3);

    void accessStruct();
    accessStruct();

    return 0;
}


void accessStruct() {
    struct Beans bean1;
    struct Beans bean2;

    //bean1
    strcpy(bean1.title, "c programming");
    strcpy(bean1.author, "Nuh Ali");
    strcpy(bean1.subject, "tutorial");
    bean1.book_id = 53443213;

    //bean2
    strcpy(bean2.title, "c programming");
    strcpy(bean2.author, "Nuh Ali");
    strcpy(bean2.subject, "tutorial");
    bean2.book_id = 53443214;

    printf("%s ", bean1.author);

    void printBook(struct Beans bean);
    printBook(bean2);

    void printBook2(struct Beans *beans);
    printBook2(&bean2);
}

//结构体作为函数参数
void printBook(struct Beans bean) {
    printf("%s", bean.author);
    printf("%s", bean.subject);
}

//结构体指针作为函数参数
void printBook2(struct Beans *beans) {

    //为了使用指向该结构的指针访问结构的成员，您必须使用 -> 运算符，如下所示：
    //struct_pointer->title;

    printf("%s", beans->author);
    printf("%s", beans->subject);
}