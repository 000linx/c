#include <stdio.h>
/*指针

指针就是地址，地址就是指针
我们操作的变量的实质就是操作计算机中的内存
我们通过地址来对内存进行访问

*/

void test1()
{
    // 声明一个指针p,将它的地址以十六进行打印出来
    int *p; // p是一个指针变量，int *表示该变量p只能存储int类型变量的地址
    printf("初始p的值为:%d\n", p);

    // 现在我们这个指针变量p进行赋值
    int temp = 10;
    printf("变量temp的地址为%d\n", &temp);
    p = &temp; // 使用'&'取地址符，将temp的地址赋值给p
    printf("更改前*p的值为:%d 此时p的值为:%d\n", *p, p);
    temp--;
    printf("更改后*p的值为:%d 此时p的值为:%d\n", *p, p);
    /*这个时候p就是指向的temp,注意，如果你修改temp对p是没有任何影响的,但是对*p是有影响的*/
    int i = *p;
    printf("temp = %d i = %d *p = %d\n", temp, i, *p);
}

void test2(int *p)//定义了一个形参p, 它的类型是int *
{
    *p = 100;//在这里完成赋值,因为 *p 就等同于 i
}
/*修改指针的值，就把指针的地址传进去，也就是指针的指针*/
void test3(int **q){
    *q = (int *)0xFFF0000;
}
int main()
{
    test1();

    int i = 10;
    test2(&i);
    printf("%d\n", i);

    int *p = &i;
    printf("修改之前的p = %p\n", p);
    /*无论是什么类型的变量，要想修改它的值就必须传入地址进去*/
    test3(&p);
    printf("修改之后的p = %p\n", p);
    return 0;
}