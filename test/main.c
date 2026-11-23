#include <stdio.h>
#include<stdlib.h>
// 实际上就是一个类，两个变量，data存需处理数组，*next就是单链表的下一节点
struct Node{
    int data;
    struct Node *link;
};

// 写一个去重方法，传原链表进来，传头结点就是整个链表进来，以及初始化一个n+1数组
void quchong(struct Node *head,int n){
    // 创建n+1长度的标记数组(6)
    int *mark= calloc((size_t)n+1,sizeof(int));
    // 上一结点
    struct Node *prev = head -> link;
    // 遍历单链表
    // 其实算法里只要前一个和当前结点
    while(prev->link != NULL){
        // 前一个结点
        // 从真实第一结点开始，就是a开始，把每个结点的指针赋值给方法里的临时指针变量
        struct Node *cur = prev -> link;
        // 拿到结点的具体数值绝对值
        int temp = abs(cur->data);
        // 如果数组值已经是1
        if(mark[temp] == 1){
            // 就把当前链表位置结点删掉，然后把上一结点的指针改为下一节点
            // 相当于删除当前结点
            prev->link = cur->link;
        }else{
            // 然后把所有的标记数组对应下标对应的数组值都改为1
            mark[temp] = 1;
            // 下一轮前驱
            prev = cur; 
        }
    }
    printf("mark[0..%d]: ", n);
    for (int i = 0; i <= n; i++) {
        printf("%d ", mark[i]);
    }
    printf("\n");
    free(mark);
    // printf("%d\n",mark[0]);
}
void main(){
    // 这就是题目的原链表
    struct Node e = {15,NULL};
    struct Node d = {-7,&e};
    struct Node c = {-15,&d};
    struct Node b = {-15,&c};
    struct Node a = {21,&b};
    struct Node head = {0,&a};
    quchong(&head,6);
    printf("去重后的链表: ");
    for (struct Node *p = head.link; p != NULL; p = p->link) {
        printf("%d ", p->data);
    }
    printf("\n");
}