#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
typedef
一般用于结构体,相当于为一个数据类型再多取一个名字
例如：typedef int Int;  此时 int i = 10等价于 Int i = 10
*/
typedef int Int;
typedef struct Student{
    int id;
    char name[100];
}student;

typedef struct teacher{
    int id;
    char name[100];
} *PTeacher,Teacher;// PTeacher 等价于 struct teacher *, Teacher 等价与 strcut teacher
int main(){
    Int i = 10;
    student stu;
    printf("%d\n", i);

    Teacher t;
    PTeacher t1 = &t;//此时的t1是一个指针变量
    t1->id = 100;
    printf("%d", t.id);

    return 0;
}