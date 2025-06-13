[值传递包括实实在在的值传递和指针传递，指针传递参数本质上也是值传递的方式，只不过它所传递的是一个地址值，传递的都是实参的一个拷贝。]

# 1.1 实实在在的值传递
```c++
#include <iostream>
#include <vector>
using namespace std;

void function(int num){
    //改变num的值
    num = 100;
}

int main() {
    int number;
    number = 1;
    function(number);
    cout << number << endl;
    return 0;
}
```
这样的值传递只能把一个函数中的值传递给另一个函数，当该值在被调函数中发生改变时，在原来的函数中并不会发生改变。 
因为被调函数的型参只有函数被调用的时候才会临时分配内存单元，一旦调用结束，占用的内存便会释放，
所以调用的函数中存储number的地址跟被调函数中number的地址不一样。


### 如果想让number通过被调函数改变该怎么做？使用指针形式的值传递。

# 1.2 指针形式的值传递(本质上也是值传递，只不过这个值是指针而已) [指针传递是通过地址间接的改变了实参的值。]
```c++
#include <iostream>
#include <vector>
using namespace std;

void function(int* num){
    //通过改变num对应地址的值来实现值的改变：
    //形参num是一个指针，传递过来的是一个地址值，解引用即可访问到这个地址值映射的值
    *num = 100;
}

int main() {
    int number;
    number = 1;
    function(&number);
    cout << number << endl;
    return 0;
}
```
