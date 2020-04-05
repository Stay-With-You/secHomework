#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"secHomework02.h"

// 栈的初始化
void Init_Stack(StackNode* S) {

	S->next = NULL;
}

// 判断链栈是否为空
Status isEmpty(StackNode* S) {
	if (S == NULL)
	{
		return SUCCESS;
	}
	else return ERROR;
}

// 链栈的入栈
Status isEmpty(StackNode* S, SElemType e) {

	StackNode* p = malloc(sizeof(StackNode*));
	p->data = e;
	p->next = S;
	S = p;  //  修改指针

	return SUCCESS;
}

// 链栈的出栈
Status isEmpty(StackNode* S, SElemType e) {
	
	StackNode* p;
	if (S == NULL)return ERROR;
	e = S->data;
	p = S;  // 指针下移
	S = S->data;
	free(p);  

	return SUCCESS;
}

// 取栈顶元素
int GetTop(StackNode* S) {
	if (S) {
		return S->data;
	}
}

int main(void) {


}
