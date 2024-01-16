#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*链表*/
/*
定义：1.n个节点离散分配 2.彼此之间通过指针相连 3.每个节点只有一个前驱节点和一个后续节点 4.首节点没有前驱节点,尾节点没有后续节点
专业术语：
    首节点：第一个有效节点
    尾节点：最后一个有效节点
    头节点：第一个有效节点的前一个节点
    头指针：指向头节点的指针变量
    尾指针：指向尾节点的指针变量
注意：头节点里没有存放有效数据，它是指向的首节点，它的作用是方便后续的链表操作
确定链表至少需要一个参数：头指针

分类：
    单链表：每个节点只有一个指针域
    双链表：每个节点有两个指针域

    循环链表：能通过任意一个节点找到其他节点
    非循环链表：
*/

/*非循环单链表*/
typedef struct Node{
    int val;
    struct Node *next;
}Node;

Node *Creat_list(){
    int len;
    int val;
    Node *head = (Node *)malloc(sizeof(Node));//先分配一个不存放有效数据的头节点
    if(head == NULL)
    {
        printf("分配内存失败\n");
        exit(-1);
    }
    printf("请输入要分配的节点个数：");
    scanf("%d", &len);

    Node *tail = head;//构建一个尾节点
    tail->next = NULL;
    for (int i = 0; i < len; i++){
        printf("请输入要赋给节点的值：");
        scanf("%d", &val);
        Node *pNew = (Node *)malloc(sizeof(Node));
        pNew->val = val;
        tail->next = pNew;//将生成的节点new挂在尾节点tail后面,从而成为新的尾节点
        pNew->next = NULL;//将尾节点清空
        tail = pNew;//让tail指向尾节点
    }

    return head;
}

void traverse_list(Node *head){
    Node *node = head->next;
    while(node){
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");

    return;
}

bool is_empty(Node *head){
    if(head->next == NULL)
        return true;
    else
        return false;
}

int length_list(Node *head){
    int cnt = 0;
    if(head->next == NULL)
        return cnt;
    while(head->next){
        cnt++;
        head = head->next;
    }
    return cnt;
}

//pos从1开始,表示插入到pos这个位置的前面
bool insert_list(Node *head, int pos, int val){
    int i = 0;
    Node *p = head;
    //找到要插入节点的前一个节点
    while(p != NULL && i < pos - 1){
        p = p->next;
        i++;
    }
    if(i > pos - 1 || p == NULL){
        return false;
    }
    Node *pNew = (Node *)malloc(sizeof(Node));
    if(pNew == NULL){
        printf("动态分配内存失败\n");
        exit(-1);
    }
    pNew->val = val;
    Node *q = p->next;
    p->next = pNew;
    pNew->next = q;
    return true;
}

//删除指定位置的元素
bool delete_list(Node *head, int pos, int *val){
    int i = 0;
    Node *p = head;
    while(p->next != NULL && i < pos - 1){
        p = p->next;
        i++;
    }
    if(p->next == NULL || i > pos - 1){
        return false;
    }
    *val = p->next->val;
    Node *q = p->next;
    p->next = p->next->next;
    free(q);
    q = NULL;

    return true;
}

int search_list(Node *head, int pos){

}

void sort_list(Node *head){
    //与数组中的类似
    for (Node *p = head->next; p != NULL ;p = p->next){
        for (Node *q = p->next; q != NULL ;q = q->next){
            if(p->val > q->val){
                int temp = p->val;
                p->val = q->val;
                q->val = temp;
            }
        }
    }
}

int main(){
    Node *head = NULL;

    head = Creat_list();
    traverse_list(head);

    if( is_empty(head) ){
        printf("链表为空\n");
    }else {
        printf("链表不为空\n");
    }

    int length = length_list(head);
    printf("链表的长度为：%d\n",length);
    sort_list(head);
    insert_list(head, 3, 10);
    traverse_list(head);
    return 0;
}