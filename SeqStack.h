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


//���������˳��ջ
SqStack* initStack(void);//��ʼ��ջ
Status isEmptyStack(SqStack* s);//�ж�ջ�Ƿ�Ϊ��
Status getTopStack(SqStack* s); //�õ�ջ��Ԫ��
Status clearStack(SqStack* s);//���ջ
Status destroyStack(SqStack* s);//����ջ
Status stackLength(SqStack* s);//���ջ����
Status pushStack(SqStack* s, ElemType pos, ElemType value);//��ջ
Status popStack(SqStack* s, ElemType pos, ElemType* value);//��ջ



#endif 


/*
base == top�ǿ�ջ�ı�־
topָ�����ڶ���Ԫ��
top-base==stacksize��Ϊջ���ı�־
overflow:ջ�Ѿ����ˣ�����Ҫѹ��Ԫ�أ����һ���Ǹ�����
underflow��ջ�Ѿ����ˣ�����Ҫ����Ԫ�أ����ͨ����Ϊ��һ�������ı�־
*/



// ��ʽջ�������ͷָ�����ջ��
// ����Ҫͷ�ڵ�
// ����û����ջ������ҿ�ջ�൱��ͷָ��ָ���
// �����ɾ��ֻ��ջ��������