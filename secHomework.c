#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "secHomework.h"

/*
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
void Push_SeqStack(SeqStack* stack, SeqStack* data02) {

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
	stack->data[stack->size] = data02;// 进栈
	stack->size++;
}

// 返回栈顶元素
int* Top_SeqStack(SeqStack* stack) {

	if (stack == NULL || stack->size == 0) {
		return NULL;
	}

	return stack->data[stack->size - 1];
}

// 出栈
void Pop_SeqStack(SeqStack* stack) {

	if (stack == NULL || stack->size == 0) {
		return NULL;
	}

	stack->data[stack->size - 1] == NULL;  // 开始清栈底
	stack->size--;  // 往栈顶移动
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

//////////////////////////////////////////////////////////

// 栈的初始化
Status Init_SeqStack(SeqStack* S) {

	S->base = (int*)malloc(sizeof(int) * MAX_SIZE);
	if (!S->base)
	{
		return ERROR;  // 分配失败
	}
	S->base = S->top;
	S->stackSize = MAX_SIZE;

	return SUCCESS;

}

// 判断栈是否为空
Status isEmpty(SeqStack* S) {
	// 空则返回ERROR,非空则返回SUCCESS
	if (S->top == S->base)
	{
		return ERROR;
	}
	else return SUCCESS;
}

// 入栈
Status Push_Stack(SeqStack* S, int e) {
	if (S->top - S->base == S->stackSize) { // 满栈
		return ERROR;
	}
	else S->top++ = e;  // 元素e压入栈

	return SUCCESS;
}

// 出栈
Status PopStack(SeqStack* S) {
	if (isEmpty(S)) {
		return ERROR;
	}
	S->top = NULL;
	S->top--;  // 往栈底移动
	return SUCCESS;
}

//	求栈中元素个数
int StackLen(SeqStack* S) {
	return S->top - S->base;
}

// 清空栈
Status ClearStack(SeqStack* S) {
	if (S->base) {
		S->top = S->base;
	}
	return SUCCESS;
}

// 销毁栈
Status DestoryStack(SeqStack* S) {
	if (S->base)
	{
		free(S->base);
		S->base = S->top = NULL;
		S->stackSize = 0;
	}
	return SUCCESS;
}