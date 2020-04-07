#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#define MAXSIZE 100

typedef enum Status 
{
	ERROR = 0, SUCCESS = 1
} Status;

typedef int ElemType;

typedef struct sqstack
{
	ElemType data[MAXSIZE];
	int top;
}SqStack;


//基于数组的顺序栈
SqStack* initStack(void);//初始化栈
Status isEmptyStack(SqStack* s);//判断栈是否为空
Status getTopStack(SqStack* s); //得到栈顶元素
Status clearStack(SqStack* s);//清空栈
Status destroyStack(SqStack* s);//销毁栈
Status stackLength(SqStack* s);//检测栈长度
Status pushStack(SqStack* s, ElemType pos, ElemType value);//入栈
Status popStack(SqStack* s, ElemType pos, ElemType* value);//出栈



#endif 


/*
base == top是空栈的标志
top指向倒数第二个元素
top-base==stacksize即为栈满的标志
overflow:栈已经满了，但还要压入元素，这个一般是个报错
underflow：栈已经空了，但还要弹出元素，这个通常认为是一个结束的标志
*/



// 链式栈其链表的头指针就是栈顶
// 不需要头节点
// 基本没有满栈的情况且空栈相当于头指针指向空
// 插入和删除只在栈顶处进行