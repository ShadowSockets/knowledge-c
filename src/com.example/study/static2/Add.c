int g_val = 2000;

//static int g_val = 2000;


//原本g_val不用static修饰，其它C文件可以用extern使用该成员；
//但是使用static修饰了g_val之后，其它C文件引用该成员的就会报错啦；
//错误：无法解析外部符号