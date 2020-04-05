#ifndef SECHOMEWORK_H
#define SECHOMEWORK_H

// 以数组去模拟栈的顺序存储
#define MAX_SIZE 100
#define OVERFLOW 1
#define SEQSTACK_TRUE 1
#define SEQSTACK_FALSE 0

/*
typedef struct SEQSTACK {

	void* data[MAX_SIZE];  // 创建栈区的大小
	// 以数组的右边为栈顶:数据不需要频繁移动
	int size;
}SeqStack;

typedef struct person {

	char name[64];
	int age;
}Person;

// 栈的初始化
SeqStack* Init_SeqStack() {

	SeqStack* stack = (SeqStack*)malloc(sizeof(SeqStack));
	for (int i = 0; i < MAX_SIZE; i++) {
		stack->data[i] = NULL;
	}
	stack->size = 0;

	return NULL;
}

// 入栈
void Push_SeqStack(SeqStack* stack, void* data02) {

	// 判断是否到栈顶 和 栈以及传入数据是否为空
	if (stack->size == MAX_SIZE) {
		return NULL;
	}
	if (stack == NULL)
	{
		return NULL;
	}
	if (data02 == NULL)
	{
		return NULL;
	}
	if (stack->size < MAX_SIZE) {
		stack->data[stack->size] = data02;// 进栈
		stack->size++;
	}
}


// 返回栈顶元素
void* Top_SeqStack(SeqStack* stack) {

	if (stack == NULL || stack->size == 0) {
		return NULL;
	}
	else {
		return stack->data[stack->size - 1];
	}
}

// 出栈
void Pop_SeqStack(SeqStack* stack) {

	if (stack == NULL || stack->size == 0) {
		return NULL;
	}

	stack->data[stack->size - 1] == NULL;  // 开始清栈顶
	stack->size--;  // 往栈底移动
}

// 判断是否为空栈 
int isEmpty(SeqStack* stack) {

	if (stack == NULL) {
		return -1;
	}
	if (stack->size == 0) {
		return SEQSTACK_TRUE;
	}

	return SEQSTACK_FALSE;
}

// 返回栈中元素个数
int Size_SeqStack(SeqStack* stack) {
	return stack->size;
}

// 清空栈
void Clear_SeqStack(SeqStack* stack) {
	if (stack == NULL) {
		return;
	}
	for (int i = 0; i < stack->size; i++) {
		stack->data[i] = NULL;
	}
	stack->size = 0;
}

// 栈的销毁
void destorySeqStack(SeqStack* stack) {

	if (stack != NULL) {
		return;
	}

	free(stack);
}
*/

/*
base == top是空栈的标志
top指向倒数第二个元素
top-base==stacksize即为栈满的标志
overflow:栈已经满了，但还要压入元素，这个一般是个报错
underflow：栈已经空了，但还要弹出元素，这个通常认为是一个结束的标志
*/


// 顺式栈
typedef struct SEQSTACK {

	int* top;  // 栈顶指针
	int* base;  // 栈底指针
	int stackSize;  

}SeqStack;

typedef enum status
{
	ERROR, SUCCESS,
}Status;


// 栈的初始化
Status Init_SeqStack(SeqStack* S);

// 判断栈是否为空
Status isEmpty(SeqStack* S);

// 入栈
Status Push_Stack(SeqStack* S, int e);

// 出栈
Status PopStack(SeqStack* S);

// 求栈中元素个数
int StackLen(SeqStack* S);

// 清空栈
Status ClearStack(SeqStack* S);

// 销毁栈
Status DestoryStack(SeqStack* S);


#endif // !SEQSTACK_H