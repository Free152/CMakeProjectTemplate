#include "linked_stack.h"
#include <iostream>

// 1. 初始化
void InitStack(LinkStack &top)
{
    top = NULL;
}

// 2. 销毁
void DestroyStack(LinkStack &top)
{
    if(top != NULL){
        free(top); // 释放栈空间
        top = NULL; // 将栈指针置空  
    }
}

// 3. 判空
bool isEmpty(LinkStack top)
{
	if(top == NULL)
		return true;
	else
		return false;
}

// 3. 进栈
bool Push(LinkStack &top, ElemType x)
{
    LinkNode *newNode = (LinkNode *)malloc(sizeof(LinkNode)); // 创建新节点
    newNode->data = x; // 设置数据域
    newNode->next = top; // 将新节点的指针域指向当前栈顶
    top = newNode; // 更新栈顶指针
    return true;
}

// 4. 出栈
bool Pop(LinkStack &top, ElemType &x)
{
    if(top == NULL)
        return false; // 栈为空，无法出栈
    x = top->data; // 获取栈顶元素
    LinkNode *temp = top; // 保存当前栈顶节点
    top = top->next; // 更新栈顶指针
    free(temp); // 释放原栈顶节点
    temp = NULL;
    return true;
}

// 5. 读取栈顶元素
bool GetTop(LinkStack top, ElemType &x)
{
	if(top == NULL)
        return false; // 栈为空，无法出栈
    x = top->data; // 获取栈顶元素
    return true;
}