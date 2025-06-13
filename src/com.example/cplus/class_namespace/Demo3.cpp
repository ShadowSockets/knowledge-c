//
// Created by alex on 2025/3/19.
//

#include <iostream>
#include "Demo3.h"

namespace MyTools {

    /**
     * 在 const std::string& moreText 中，& 符号表示引用（Reference）。这是 C++ 中的一种重要特性，用于传递参数或定义变量时避免复制，提高效率，同时还能控制数据的修改权限。
     * @param initialText
     * C语言，有引用的概念吗?
     * 在 C语言 中，没有直接的引用（Reference）概念，这是 C++ 引入的一个特性。C语言使用的是**指针（Pointer）**来实现类似的功能，但指针和引用的工作方式、语法以及使用场景有明显区别。
     */
    //构造函数实现
    StringHelper::StringHelper(const std::string& initialText) {
        text = initialText;
    }

    //追加字符串的实现
    void StringHelper::append(const std::string& moretext) {
        text+= moretext;
    }

    //获取字符串的实现
    /**
     *  const作用：
     *  用于成员函数时，表示该函数不会修改类的非 mutable 数据成员。
     *  用于数据成员时，表示该成员在对象构造后不可修改。
     * @return
     */
    std::string StringHelper::getText() const {
        return text;
    }

    // 打印字符串的实现
    void StringHelper::print() const {
        std::cout << "Text: " << text << std::endl;
    }
}

int main(){

    // 使用命名空间和类
    // 创建对象，初始值为 "Hello"
    MyTools::StringHelper sh("Hello");  // sh 是你给这个对象起的名字，表示一个具体实例，你可以随便取名。

    sh.append(", World!");  // 追加字符串
    sh.print();             // 打印结果

    std::string result = sh.getText();  // 获取字符串
    std::cout << "Result: " << result << std::endl;

    return 0;
}