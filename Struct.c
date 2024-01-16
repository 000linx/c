#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
/*
结构体三个问题
1.为什么会使用结构体
为了方便实现复合的数据类型，比如一个学生类，他有姓名，学号，班级等信息
需要用不同的数据类型来定义，我们用结构体将它复合为一个数据类型
2.什么叫结构体
使用者根据实际的需要自己定义的复合数据类型
3.怎么使用结构体
两种方式:
    Student stu = {"linx", 10, 'm', 10011};
    Student *pstu =  &stu;
    1.stu.id;
    2.pstu -> id;这句话表示pstu指向结构体变量中id这个成员

*/
typedef struct Student
{
    char name[10];
    int age;
    char sex;
    int id;
}Student;

void Change(Student *b){
    b->id = 11000;
}

int main(){
    Student stu = {"linx", 10, 'm', 10011};
    printf("%s\n", stu.name);
    //C语言中修改字符串需要用到string.h中的strcpy函数
    strcpy(stu.name, "zhangsan");
    printf("%s\n", stu.name);

    //通过指针的方式来修改值
    Student *pstu = &stu;
    pstu->age = 18;//pstu->id等价于（*pstu).id ,而(*pstu).id又等价于stu.id
    Change(pstu);
    printf("%s %d %c %d", pstu->name, pstu->age, pstu->sex, pstu->id);
    return 0;
}