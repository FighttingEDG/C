#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// 告诉编译器 dedup 怎么调用，函数体在 Answer.c 里。
void dedup(struct Node *head, int n);

int main(void) {
    struct Node head = {0, NULL};
    struct Node *tail = &head;  // &head 取头结点的地址
    int values[] = {-15, 15, 7};

    for (int i = 0; i < 3; ++i) {
        // 用 malloc 创建数据结点，dedup 删除时才能用 free。
        struct Node *node = malloc(sizeof(struct Node));
        if (node == NULL) return 1;
        node->data = values[i];
        node->next = NULL;
        tail->next = node;
        tail = node;
    }

    dedup(&head, 15);  // 15 是示例中绝对值的上限

    // 打印留下的结点，并逐个释放。
    while (head.next != NULL) {
        struct Node *node = head.next;
        printf("%d\n", node->data);
        head.next = node->next;
        free(node);
    }
    return 0;
}