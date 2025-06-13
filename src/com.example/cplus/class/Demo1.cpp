//
// Created by alex on 2025/3/19.
//

#include "Demo1.h"

#include <iostream>
using namespace std;


//定义类中方法（即成员函数）的具体实现
void Demo1::print() {  //:: 是作用域解析运算符，表示 print 是 MyClass 类的成员。
    cout << "Value:" << value << endl;   //cout 这个单词是: c out，还有cin、cerr、clog
}


int main(){

    Demo1 demo1{}; //创建对象
    demo1.setValue(110); //使用对象
    demo1.print();

    return 0;
}