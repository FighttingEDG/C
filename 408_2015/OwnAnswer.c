#include <stdlib.h>

// 实际上就是一个类，两个变量，data存需处理数组，*next就是单链表的下一节点
struct Node{
    int data;
    struct Node *next;
};

// 写一个去重方法，传一个单链表以及标记数组的长度n
void quchong(struct Node *head,int n){
    int *mark= calloc((size_t)n+1,sizeof(int));
    
}