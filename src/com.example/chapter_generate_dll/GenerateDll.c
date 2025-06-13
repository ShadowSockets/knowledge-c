#include <stdio.h>

#include "MyDll.h"

void hello(void) {
    printf("hello dll!");
}


//如果要生成dll文件，那么不能写main方法，只能写非main方法。
