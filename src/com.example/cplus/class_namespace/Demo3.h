//
// Created by alex on 2025/3/19.
//

#ifndef KNOWLEDGE_C_DEMO3_H
#define KNOWLEDGE_C_DEMO3_H

#include <string>


//定义一个命令空间 MyTools
namespace MyTools {
    //在命名空间中定义一个类 StringHelper
    class StringHelper {
    private:
        std::string text; //成员变量
    public:
        StringHelper(const std::string& initialText); //构造函数声明
        void append(const std::string& moreText); //追加字符串的声明
        std::string getText() const;  //获取字符串的声明
        void print() const; //打印字符串的声明
    };
}

class Demo3 {

};


#endif //KNOWLEDGE_C_DEMO3_H
