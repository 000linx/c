#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*动态内存的分配和释放
malloc函数返回的是第一个字节的地址

*/
int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    int len = 5;

    /*这句话的含义是malloc向cpu请求为这个程序分配sizeof(int) * len这么大的空间
    C语言中不要求进行强制类型转换，但是c++需要
    malloc是按照需要的字节数进行分配内存的，而不是数据类型，它的返回值是类型是void *
    因此我们在这里对其进行强制类型转换是为了告诉编译器我们这个类型是int *，方便我们后续的操作
    */
    int *Parr = (int *)malloc(sizeof(int) * len);//逻辑上的含义是让parr指向前四个字节
    /*此时它就可以当做数组进行操作，Parr就相当于数组名*/
    *Parr = 5; // 类型与arr[0] = 5,因为malloc返回的是第一个字节的地址，那么就可以像数组一样对其进行赋值
    Parr[1] = 10;

    int *pArr = (int *)malloc(sizeof(int) * len);
    for (int i = 0; i < len;i++){
        pArr[i] = i + 1;
        printf("%d ", (*pArr + i)); //(*pArr + i) 等价于 pArr[i];
    }

        free(pArr);
    free(Parr);//把parr所代表的动态分配的20个字节的内存释放
    return 0;
}