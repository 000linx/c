#include <stdio.h>
/*指针和数组

一维数组名是一个指针常量，它存放的是一维数组第一个元素的地址，它的值不能改变
一维数组名指向的是数组的第一个元素

*/ 

void Show_Array(int *p,int len){
    for (int i = 0; i < 5; i++)
        printf("%d ", *(p + i));
}

int main(){
    // 定义一个数组在我们看来它是存放的数字1到5，但是实际上它存放的是arr[0]到arr[4];
    int arr[5] = {1, 2, 3, 4, 5};
    /*根据上面的规定我们知道 a是指向的a[0] */
    // a[i] == *(a + i) == i[a];
    printf("arr[3] = %d  *(a + 3) = %d  3[arr] = %d\n", arr[3], *(arr + 3), 3[arr]);

    //通过数组的首地址和数组的长度既可确定一个数组
    Show_Array(arr,5);//arr就等价于 &arr[0],是一个int *类型的值
    return 0; 
}          