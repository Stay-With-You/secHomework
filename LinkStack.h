#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status 
{
    ERROR = 0, 
	SUCCESS = 1
} Status;

typedef int ElemType;

typedef struct StackNode {
	
	ElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef struct LinkStack {
	
	LinkStackPtr top;
	ElemType count;
}LinkStack;




//��ջ
Status initLStack(LinkStack** s);//��ʼ��ջ
Status isEmptyLStack(LinkStack *s);//�ж�ջ�Ƿ�Ϊ��
Status getTopLStack(LinkStack *s,ElemType e);//�õ�ջ��Ԫ��
Status clearLStack(LinkStack s);//���ջ
Status destroyLStack(LinkStack **s);//����ջ
int LStackLength(LinkStack *s);//���ջ����
Status pushLStack(LinkStack *s,ElemType e);//��ջ
Status popLStack(LinkStack *s,ElemType e);//��ջ


#endif 
