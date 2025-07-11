#ifndef LINKED_STACK_H
#define LINKED_STACK_H    

typedef int ElemType;

typedef struct LinkNode {
    ElemType data;               // 数据域
    struct LinkNode *next;      // 指针域
} LinkNode, *LinkStack;

// 1. 初始化
void InitStack(LinkStack &top);
// 2. 销毁
void DestroyStack(LinkStack &top);
// 3. 判空
bool isEmpty(LinkStack top);
// 4. 进栈
bool Push(LinkStack &top, ElemType x);
// 5. 出栈
bool Pop(LinkStack &top, ElemType &x);
// 6. 读取栈顶元素
bool GetTop(LinkStack top, ElemType &x);

#endif