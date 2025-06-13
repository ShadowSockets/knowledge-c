//
// Created by alex on 2025/3/19.
//

#ifndef KNOWLEDGE_C_DEMO2_H
#define KNOWLEDGE_C_DEMO2_H


// 在 C++ 中，命名空间（namespace） 不一定非要定义在头文件中，但确实经常在头文件中定义，
// 尤其是在需要跨多个文件共享代码的场景下。这是一种常见的编程实践，而不是语法上的强制要求。

#include <iostream>

namespace Demo2{
    int value = 5;
    void print(){
        std::cout << "Value:" << value << std::endl;
    }
};


#endif //KNOWLEDGE_C_DEMO2_H
