#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*数组*/

//定义了一个数据类型，该数据类型名字是struct Arr，并且该数据类型有三个成员
struct Array{
    int *Head;//代表数组的首地址
    int len;//代表数组的长度
    int cnt;//数组有效元素个数
};

typedef struct Array Arr;


bool append_arr(Arr *arr, int val);//追加
bool insert_arr(Arr *arr, int pos, int val);//插入到指定位置的前面,pos的值从1开始,比如想在3这个位置插入元素，实际上是在数组下标为2处插入元素
bool delete_arr(Arr *arr, int pos);//删除类似于插入
bool is_empty(Arr *arr);//判断是否为空
bool is_full(Arr *arr);//判断是否装满
void init_arr(Arr *arr, int length);//完成初始化
void show_arr(Arr *arr);
void sort_arr(Arr *arr);//排序,默认升序
void inversion_arr(Arr *arr); // 翻转
int get_arr();

int main(){
    Arr arr;
    /*进行初始化，通过调用函数来改变主函数中的变量需要传入地址*/
    init_arr(&arr,10);
    show_arr(&arr);
    append_arr(&arr, 1);
    append_arr(&arr, 2);
    append_arr(&arr, 3);
    append_arr(&arr, 4);
    append_arr(&arr, 5);
    insert_arr(&arr, 3, 50);
    show_arr(&arr);
    delete_arr(&arr, 3);
    show_arr(&arr);
    return 0;
}

void init_arr(Arr *pArray,int length){
    pArray->Head = (int *)malloc(sizeof(int) * length);
    if(pArray->Head == NULL){
        printf("初始化失败,请检查内存\n");
        exit(-1);//终止整个程序
    }
    pArray->len = length;
    pArray->cnt = 0;
    return;
}

bool is_empty(Arr *pArray)
{
    if (pArray->cnt != 0){
        return false;
    }
    return true;
}

bool is_full(Arr *pArray){
    if(pArray->cnt != pArray->len){
        return false;
    }
    return true;
}

bool append_arr(Arr *pArray,int val){
    if(is_full(pArray)){
        printf("数组已经装满,请扩充内存\n");
        return false;
    }
    pArray->Head[pArray->cnt] = val;
    pArray->cnt ++;
    printf("元素追加成功\n");
    return true;
}

bool insert_arr(Arr *pArray, int pos, int val){
    if(is_full(pArray) || pos > pArray ->cnt + 1 || pos < 1){
        printf("插入失败\n");
        return false;
    }
    /*cnt - 1确定最后一个有效数的下标,pos - 1代表要插入位置的下标，通过这两个确定要往后移动的元素个数*/
    for (int i = pArray->cnt - 1; i >= pos - 1; --i){
        pArray->Head[i + 1] = pArray->Head[i];
    }
    pArray->Head[pos - 1] = val;
    pArray->cnt++;
    return true;
}

bool delete_arr(Arr *pArray, int pos){
    if(is_empty(pArray) || pos < 1 || pos > pArray ->cnt){
        printf("删除失败\n");  
    }
    for (int i = pos; i < pArray->cnt; i++){
        pArray->Head[i - 1] = pArray->Head[i];
    }
    pArray->cnt--;
    return true;
}

void show_arr(Arr *pArray){
    if(is_empty(pArray)){
        printf("数组内容为空,请添加内容\n");
    }
    for (int i = 0; i < pArray->cnt; ++i){
        printf("%d ", pArray->Head[i]);
    }
    printf("\n");
}

void sort_arr(Arr *pArray){
    for (int i = 0; i < pArray->cnt; ++i){
        for (int j = i + 1; j < pArray->cnt; j++){
            if (pArray->Head[i] > pArray->Head[j])
            {
                int temp = pArray->Head[i];
                pArray->Head[i] = pArray->Head[j];
                pArray->Head[j] = temp;
            }
        }
    }
}

void inversion_arr(Arr *pArray){
    if(is_empty(pArray)){
        printf("数组为空\n");
    }
    int i = 0, j = pArray->cnt - 1;
    int temp;
    while(i < j){
        temp = pArray->Head[i];
        pArray->Head[i] = pArray->Head[j];
        pArray->Head[j] = temp;
        i++;
        j--;
    }
}