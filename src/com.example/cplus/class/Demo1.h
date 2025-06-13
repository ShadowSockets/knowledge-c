//
// Created by alex on 2025/3/19.
//

#ifndef KNOWLEDGE_C_DEMO1_H
#define KNOWLEDGE_C_DEMO1_H


//如果类只在一个源文件中使用，可以直接把类定义和实现都写在 .cpp 文件中，不需要头文件。

class Demo1{
public:
    int value; //成员变量
    void setValue(int v){value = v;} //成员函数声明，以及定义
    void print() const; //成员函数声明
    void print();
};



#endif //KNOWLEDGE_C_DEMO1_H
