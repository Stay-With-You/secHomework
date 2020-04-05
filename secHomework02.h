#ifndef SECHOMEWORK02_H
#define SECHOMEWORK02_H


// ��ʽջ
typedef int SElemType;

typedef struct stacknode {

	SElemType data;
	struct stacknode* next;
}StackNode;

typedef enum status
{
	ERROR, SUCCESS,
}Status;

// ��ʽջ�������ͷָ�����ջ��
// ����Ҫͷ�ڵ�
// ����û����ջ������ҿ�ջ�൱��ͷָ��ָ���
// �����ɾ��ֻ��ջ��������

// ջ�ĳ�ʼ��
void Init_Stack(StackNode* S);

// �ж���ջ�Ƿ�Ϊ��
Status isEmpty(StackNode* S);

// ��ջ����ջ
Status isEmpty(StackNode* S, SElemType e);

// ��ջ�ĳ�ջ
Status isEmpty(StackNode* S, SElemType e);

// ȡջ��Ԫ��
int GetTop(StackNode* S);


#endif 