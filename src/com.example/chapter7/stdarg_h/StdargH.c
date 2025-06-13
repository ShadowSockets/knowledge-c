
///库变量
//va_list 这是一个适用于 va_start()、va_arg() 和 va_end() 这三个宏存储信息的类型。

///库宏
//void va_start(va_list ap, last_arg)
//这个宏初始化 ap 变量，它与 va_arg 和 va_end 宏是一起使用的。last_arg 是最后一个传递给函数的已知的固定参数，即省略号之前的参数。

//type va_arg(va_list ap, type)
//这个宏检索函数参数列表中类型为 type 的下一个参数。

//void va_end(va_list ap)
//这个宏允许使用了 va_start 宏的带有可变参数的函数返回。如果在从函数返回之前没有调用 va_end，则结果为未定义。

int main(){

    return 0;
}