#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"secHomework02.h"

// ջ�ĳ�ʼ��
void Init_Stack(StackNode* S) {

	S->next = NULL;
}

// �ж���ջ�Ƿ�Ϊ��
Status isEmpty(StackNode* S) {
	if (S == NULL)
	{
		return SUCCESS;
	}
	else return ERROR;
}

// ��ջ����ջ
Status isEmpty(StackNode* S, SElemType e) {

	StackNode* p = malloc(sizeof(StackNode*));
	p->data = e;
	p->next = S;
	S = p;  //  �޸�ָ��

	return SUCCESS;
}

// ��ջ�ĳ�ջ
Status isEmpty(StackNode* S, SElemType e) {
	
	StackNode* p;
	if (S == NULL)return ERROR;
	e = S->data;
	p = S;  // ָ������
	S = S->data;
	free(p);  

	return SUCCESS;
}

// ȡջ��Ԫ��
int GetTop(StackNode* S) {
	if (S) {
		return S->data;
	}
}

int main(void) {


}
