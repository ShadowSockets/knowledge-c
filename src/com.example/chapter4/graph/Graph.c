//
// Created by Alex on 2020/1/6.
//

//C 语言提供了 typedefaa 关键字，您可以使用它来为类型取一个新的名字。

//用 #define 定义标识符的一般形式为：
//#define  标识符  常量   //注意, 最后没有分号
//#define 和 #include 一样，也是以“#”开头的。凡是以“#”开头的均为预处理指令，#define也不例外。
//#define又称宏定义，标识符为所定义的宏名，简称宏。标识符的命名规则与前面讲的变量的命名规则是一样的。#define 的功能是将标识符定义为其后的常量。一经定义，程序中就可以直接用标识符来表示这个常量。是不是与定义变量类似？但是要区分开！变量名表示的是一个变量，但宏名表示的是一个常量。可以给变量赋值，但绝不能给常量赋值。
//宏所表示的常量可以是数字、字符、字符串、表达式。其中最常用的是数字。
//那么，程序中什么时候会使用宏定义呢？用宏定义有什么好处呢？我们直接写数字不行吗？为什么要用一个标识符表示数字呢？
//宏定义最大的好处是“方便程序的修改”。使用宏定义可以用宏代替一个在程序中经常使用的常量。注意，是“经常”使用的。这样，当需要改变这个常量的值时，就不需要对整个程序一个一个进行修改，只需修改宏定义中的常量即可。且当常量比较长时，使用宏就可以用较短的有意义的标识符来代替它，这样编程的时候就会更方便，不容易出错。因此，宏定义的优点就是方便和易于维护

//上面代码中，在C/C++中，每个变量都有其相应的地址，通过在变量标识符前加&符号即可获得变量的地址。

#include <stdio.h>

#define MAX_VERtEX_NUM 20 //定点最大个数
#define VRType int        //表示定点之间的关系的变量类型
#define InfoType char     //存储弧或者边额外信息的指针变量类型
#define VertexType int    //图中顶点的数据类型
typedef enum {
    DG, DN, UDG, UDN
} GraphKind; //枚举图的四种类型
typedef struct {
    VRType adj;      //对于无权图，用0或1表示是否相邻，对于带权图，直接为权值
    InfoType *info;  //弧或者边额外含有的信息指针
} AreCell, AdjMatrix[MAX_VERtEX_NUM][MAX_VERtEX_NUM];  //结构变量，定义在结构的末尾，最后一个分号之前，您可以指定一个或多个结构变量。

// AdjMatrix[MAX_VERtEX_NUM][MAX_VERtEX_NUM] 结构体变量的初始化  初始化一个二维数组

typedef struct {
    VertexType vexs[MAX_VERtEX_NUM];    //存储图中顶点数据
    AdjMatrix arcs;                     //二维数组，记录顶点之间的关系
    int vexnum, arcnum;                 //记录图的顶点数和弧(边)数
    GraphKind kind;                     //记录图的种类
} MGraph;


//结构体指针变量在引用成员变量时，使用箭头（->）来操作，如：
//
//strcpy( pstu->name, "zhangsan" );
//pstu->age=20;
//pstu->score=100;
//　以上符号的使用是C语言的规定！

//根据顶点本身数据，判断顶点在二维数组中的位置
int LocateVex(MGraph *G, VertexType v) {
    int i = 0;
    //遍历一维数组，找到变量
    for (; i < G->vexnum; i++) {
        if (G->vexnum) {
            break;
        }
    }

    //如果找不到，输出提示语句，返回-1
    if (i > G->vexnum) {
        printf("no such vertex \n");
        return -1;
    }

    return i;
}


//构造有向图
void CreateDG(MGraph *G) {
    //输入图中含有的顶点数和弧的个数
    scanf("%d %d", &(G->vexnum), &(G->arcnum));
    //依次输入顶点本身的数据
    for (int i = 0; i < G->vexnum; i++) {
        scanf("%d", &(G->vexs[i]));
    }

    //初始化二维矩阵，全部归0，指针指向NULL
    for (int i = 0; i < G->vexnum; i++) {
        for (int j = 0; j < G->vexnum; j++) {
            G->arcs[i][j].adj = 0;
            G->arcs[i][j].info = NULL;
        }
    }

    //在二维数组中添加弧的数据
    for (int i = 0; i < G->arcnum; i++) {
        int v1, v2;
        //输入弧头和弧尾
        scanf("%d %d", &v1, &v2);
        //确定顶点位置
        int n = LocateVex(G, v1);
        int m = LocateVex(G, v2);
        //排除错误数据
        if (m == -1 || n == -1) {
            printf("no this vertex\n");
            return;
        }
        //将正确的弧的数据加入二维数组
        G->arcs[n][m].adj = 1;
    }
}

// 构造无向图
void CreateDN(MGraph *G) {
    scanf("%d,%d", &(G->vexnum), &(G->arcnum));
    for (int i = 0; i < G->vexnum; i++) {
        scanf("%d", &(G->vexs[i]));
    }
    for (int i = 0; i < G->vexnum; i++) {
        for (int j = 0; j < G->vexnum; j++) {
            G->arcs[i][j].adj = 0;
            G->arcs[i][j].info = NULL;
        }
    }

    for (int i = 0; i < G->arcnum; i++) {
        int v1, v2;
        scanf("%d,%d", &v1, &v2);
        int n = LocateVex(G, v1);
        int m = LocateVex(G, v2);
        if (m == -1 || n == -1) {
            printf("no this vertex\n");
            return;
        }
        G->arcs[n][m].adj = 1;
        G->arcs[m][n].adj = 1; //无向图的二阶矩阵沿主角线对称
    }
}

//构造有向网，和有向图不同的是二阶矩阵中存储的是权值
void CreateUDG(MGraph *G) {
    scanf("%d,%d", &(G->vexnum), &(G->arcnum));
    for (int i = 0; i < G->vexnum; i++) {
        scanf("%d", &(G->vexs[i]));
    }
    for (int i = 0; i < G->vexnum; i++) {
        for (int j = 0; j < G->vexnum; j++) {
            G->arcs[i][j].adj = 0;
            G->arcs[i][j].info = NULL;
        }
    }
    for (int i = 0; i < G->arcnum; i++) {
        int v1, v2, w;
        scanf("%d,%d,%d", &v1, &v2, &w);
        int n = LocateVex(G, v1);
        int m = LocateVex(G, v2);
        if (m == -1 || n == -1) {
            printf("no this vertex\n");
            return;
        }
        G->arcs[n][m].adj = w;
    }
}


//构造无向网和无向图唯一的区别就是二阶矩阵中存储的是权值
void CreateUDN(MGraph *G) {
    scanf("%d,%d", &(G->vexnum), &(G->arcnum));
    for (int i = 0; i < G->vexnum; i++) {
        scanf("%d", &(G->vexs[i]));
    }
    for (int i = 0; i < G->vexnum; i++) {
        for (int j = 0; j < G->vexnum; j++) {
            G->arcs[i][j].adj = 0;
            G->arcs[i][j].info = NULL;
        }
    }

    for (int i = 0; i < G->arcnum; i++) {
        int v1, v2, w;
        scanf("%d,%d,%d", &v1, &v2, &w);
        int m = LocateVex(G, v1);
        int n = LocateVex(G, v2);
        if (m == -1 || n == -1) {
            printf("no this vertex\n");
            return;
        }
        G->arcs[n][m].adj = w;
        G->arcs[m][n].adj = w;//矩阵对称
    }
}

void CreteGraph(MGraph *G) {
    //选择图的类型
    scanf("%d", &(G->kind));
    switch (G->kind) {
        case DG:
            return CreateDG(G);
            break;
        case DN:
            return CreateDN(G);
            break;
        case UDG:
            return CreateUDG(G);
            break;
        case UDN:
            return CreateUDN(G);
            break;
        default:
            break;
    }
}

//输出函数
void PrintGraph(MGraph G) {
    for (int i = 0; i < G.vexnum; i++) {
        for (int j = 0; j < G.vexnum; j++) {
            printf("%d", G.arcs[i][j].adj);
        }
        printf("\n");
    }
}


int main() {
    MGraph G;       //建立一个图的变量
    CreteGraph(&G); //调用创建函数，传入地址参数
    PrintGraph(G);  //输出图的二阶矩阵
    return 0;
}