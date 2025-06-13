/**
break
	1.break如果用于循环是用来终止循环
	2.break如果用于switch,则是用来终止switch
	3.break不能直接用于if
	4.在多层循环中,break只能终止距离它最近的那个循环

continue 
	1.continue用于跳过本次循环余下语句，转去判断是否需要执行下次循环
	2.continue不能用于if

for(1; 2; 3){
   A;
   B;
   continue; //如果执行该语句，则执行完该语句后，会执行语句3，C和D都会被跳过
   C;
   D;
}
**/

#include <stdio.h>

int main() {
    int i = 2;

    switch (i) {
        case 2:
            printf("数据为2\n");
            break;
        case 3:
            printf("数据为3\n");
            break;
        default:
            printf("默认值\n");
            break;
    }

    int j, k;
    for (j = 0; j < 3; ++j) {
        for (k = 1; k < 4; k++) {
            break;
        }
    }
    return 0;
}

