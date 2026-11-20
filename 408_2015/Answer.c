#include <stdlib.h>  // 这个头文件声明了 calloc、abs、free。

struct Node {
    int data;
    struct Node *next;
};

// void 表示函数没有返回值。dedup 是自己起的函数名，意思是去重。
// 参数里的 *head 表示 head 是指向 struct Node 的指针。
// 本题约定 head 指向头结点，n 是数据绝对值的上限。
void dedup(struct Node *head, int n) {
    // int *seen 声明一个指向 int 的指针。
    // (size_t)n 把 n 转成表示大小的类型，再 +1 得到格子数。
    // sizeof(int) 算一个 int 占多少字节，作为每格的大小。
    // calloc 负责分配并清零。等号 = 把它返回的地址存进 seen。
    int *seen = calloc((size_t)n + 1, sizeof(int));

    // calloc 失败会返回 NULL。== 是比较，if 条件为真才执行 return。
    // return; 在这里结束整个 dedup 函数。
    if (seen == NULL) return;

    // = 把 head 里存的地址复制给 prev，两个指针起初指向同一个头结点。
    struct Node *prev = head;

    // -> 访问指针所指结点的字段。prev->next 就是 prev 后面那个结点的地址。
    // != 表示不等于。while 每轮开始都检查，只要这个地址非空就继续。
    while (prev->next != NULL) {
        // 右边取出 prev 的 next 字段。= 把这个地址存进 cur。
        struct Node *cur = prev->next;

        // cur->data 读取当前结点的整数。abs 返回绝对值，= 将结果存进 k。
        int k = abs(cur->data);

        // [k] 找到标记数组第 k 格。== 0 检查这格是不是初始状态。
        if (seen[k] == 0) {
            // = 1 把第 k 格改成 1。本算法约定 1 表示「见过」。
            seen[k] = 1;

            // 左边是指针变量 prev。= cur 让 prev 指向当前保留的结点。
            prev = cur;
        } else {
            // else 在上面的条件为假时执行。标记格只有 0 和 1，此时它是 1。
            // 右边 cur->next 读出下一结点的地址。
            // 左边 prev->next 是前一结点的字段。= 把这个地址写进去，跳过 cur。
            prev->next = cur->next;

            // free 接收 cur 所存的地址，释放这个动态分配的结点。
            // 这个分支给 prev->next 赋值，所以下一轮 prev 仍指着前一结点。
            free(cur);
        }
    }

    // seen 还存着 calloc 返回的地址。free(seen) 释放整块标记空间。
    free(seen);
}