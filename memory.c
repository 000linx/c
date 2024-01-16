#include <stdio.h>
#include <stdlib.h>

/*跨函数调用的内存问题

C语言中malloc动态分配的内存一定要手动释放掉

*/
int useMalloc(int **q){
    *q = (int *)malloc(sizeof(int) * 1);
    **q = 10;
    return 0;
}

int useCommon(int *q){
    int s = 10;
    q = &s;
    return 0;
}

typedef struct Student{
    int age;
    int id;
}Student;

Student *CreateStudent(){
    /*使用malloc分配内存*/
    Student *p = (Student *)malloc(sizeof(Student));
    if(p == NULL){
        printf("分配内存失败");
        return NULL;
    }else {
        /*为测试样例赋值*/
        p->age = 18;
        p->id = 1000110;
        return p;
    }
}

void ShowStudent(Student *stu){
    /*通过指针对其进行输出*/
    if(stu == NULL)
        return;
    printf("年龄 = %d 学号 = %d\n", stu->age,stu->id);

}
int main(){
    int *p;
    /*这种写法实际上不能使得p指向一个合法的整型变量，因为在该函数调用完之后内存就被释放掉了*/
    useCommon(p);
    //printf("%d", *p);如果运行程序会报错

    /*这种写法是可以让p指向一个合法的整型变量，因为我们用malloc分配给了p四个字节的的空间，并且没有用free释放掉
    即使是在函数调用完结束后，内存仍旧存在*/
    useMalloc(&p);
    printf("%d\n", *p);//这样就可以正常的赋值运行

    Student *stu = NULL;
    stu = CreateStudent();
    ShowStudent(stu);
    return 0;
}