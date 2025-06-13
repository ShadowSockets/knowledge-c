struct Student {
    int age;
    float score;
    char sex;
};

int main(void)
{
    //方式1
    struct Student st = {80,66.6f,'F'};

    //方式2
    struct Student st2;
    st2.age = 10;
    st2.score = 88;
    st2.sex = 'F';

    //指针类型变量指向的是 ：Student类型数据
    struct Student * pst = &st;

    pst->age = 88;  // pat->age 在计算机内部会被转化成  (*pst).age  没有为什么，这就是->的含义，这也是一种硬性规定
    // 所以 pat->age 等价于 (*pst).age 也等价于 st.age
    // 我们之所以知道	pst->age 等价于 st.age 是因为pst->age 是被转换成了 (*pat).age来执行
    return 0;
}

/**
	如何取出结构体变量中的每一个成员
		1.结构体变量名.成员名
		2.指针变量名->成员名
**/


