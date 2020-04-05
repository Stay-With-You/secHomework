#ifndef SECHOMEWORK02_H
#define SECHOMEWORK02_H


// 链式栈
typedef int SElemType;

typedef struct stacknode {

	SElemType data;
	struct stacknode* next;
}StackNode;

typedef enum status
{
	ERROR, SUCCESS,
}Status;

// 链式栈其链表的头指针就是栈顶
// 不需要头节点
// 基本没有满栈的情况且空栈相当于头指针指向空
// 插入和删除只在栈顶处进行

// 栈的初始化
void Init_Stack(StackNode* S);

// 判断链栈是否为空
Status isEmpty(StackNode* S);

// 链栈的入栈
Status isEmpty(StackNode* S, SElemType e);

// 链栈的出栈
Status isEmpty(StackNode* S, SElemType e);

// 取栈顶元素
int GetTop(StackNode* S);


#endif 