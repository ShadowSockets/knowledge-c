int Add(int x, int y) {
    int z = x + y;
    return z;
}

//static int Add(int x, int y) {
//    int z = x + y;
//    return z;
//}

//原本Add函数不用static修饰，其它C文件可以用extern使用该函数符号；
//但是使用static修饰了Add函数之后，其它C文件引用该函数符号的就会报错啦；
//错误：无法解析外部符号_Add,函数_main中引用了该符号