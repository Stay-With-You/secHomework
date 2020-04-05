#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "secHomework.h"

/*
// ջ�ĳ�ʼ��
SeqStack* Init_SeqStack() {

	SeqStack* stack = (SeqStack*)malloc(sizeof(SeqStack));
	for (int i = 0; i < MAX_SIZE; i++) {
		stack->data[i] = NULL;
	}
	stack->size = 0;

	return NULL;
}

// ��ջ
void Push_SeqStack(SeqStack* stack, SeqStack* data02) {

	// �ж��Ƿ�ջ�� �� ջ�Լ����������Ƿ�Ϊ��
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
	stack->data[stack->size] = data02;// ��ջ
	stack->size++;
}

// ����ջ��Ԫ��
int* Top_SeqStack(SeqStack* stack) {

	if (stack == NULL || stack->size == 0) {
		return NULL;
	}

	return stack->data[stack->size - 1];
}

// ��ջ
void Pop_SeqStack(SeqStack* stack) {

	if (stack == NULL || stack->size == 0) {
		return NULL;
	}

	stack->data[stack->size - 1] == NULL;  // ��ʼ��ջ��
	stack->size--;  // ��ջ���ƶ�
}

// �ж��Ƿ�Ϊ��ջ 
int isEmpty(SeqStack* stack) {

	if (stack == NULL) {
		return -1;
	}
	if (stack->size == 0) {
		return SEQSTACK_TRUE;
	}

	return SEQSTACK_FALSE;
}

// ����ջ��Ԫ�ظ���
int Size_SeqStack(SeqStack* stack) {
	return stack->size;
}

// ���ջ
void Clear_SeqStack(SeqStack* stack) {
	if (stack == NULL) {
		return;
	}
	for (int i = 0; i < stack->size; i++) {
		stack->data[i] = NULL;
	}
	stack->size = 0;
}

// ջ������
void destorySeqStack(SeqStack* stack) {

	if (stack != NULL) {
		return;
	}

	free(stack);
}
*/

//////////////////////////////////////////////////////////

// ջ�ĳ�ʼ��
Status Init_SeqStack(SeqStack* S) {

	S->base = (int*)malloc(sizeof(int) * MAX_SIZE);
	if (!S->base)
	{
		return ERROR;  // ����ʧ��
	}
	S->base = S->top;
	S->stackSize = MAX_SIZE;

	return SUCCESS;

}

// �ж�ջ�Ƿ�Ϊ��
Status isEmpty(SeqStack* S) {
	// ���򷵻�ERROR,�ǿ��򷵻�SUCCESS
	if (S->top == S->base)
	{
		return ERROR;
	}
	else return SUCCESS;
}

// ��ջ
Status Push_Stack(SeqStack* S, int e) {
	if (S->top - S->base == S->stackSize) { // ��ջ
		return ERROR;
	}
	else S->top++ = e;  // Ԫ��eѹ��ջ

	return SUCCESS;
}

// ��ջ
Status PopStack(SeqStack* S) {
	if (isEmpty(S)) {
		return ERROR;
	}
	S->top = NULL;
	S->top--;  // ��ջ���ƶ�
	return SUCCESS;
}

//	��ջ��Ԫ�ظ���
int StackLen(SeqStack* S) {
	return S->top - S->base;
}

// ���ջ
Status ClearStack(SeqStack* S) {
	if (S->base) {
		S->top = S->base;
	}
	return SUCCESS;
}

// ����ջ
Status DestoryStack(SeqStack* S) {
	if (S->base)
	{
		free(S->base);
		S->base = S->top = NULL;
		S->stackSize = 0;
	}
	return SUCCESS;
}