#ifndef SECHOMEWORK_H
#define SECHOMEWORK_H

// ������ȥģ��ջ��˳��洢
#define MAX_SIZE 100
#define OVERFLOW 1
#define SEQSTACK_TRUE 1
#define SEQSTACK_FALSE 0

/*
typedef struct SEQSTACK {

	void* data[MAX_SIZE];  // ����ջ���Ĵ�С
	// ��������ұ�Ϊջ��:���ݲ���ҪƵ���ƶ�
	int size;
}SeqStack;

typedef struct person {

	char name[64];
	int age;
}Person;

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
void Push_SeqStack(SeqStack* stack, void* data02) {

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
	if (stack->size < MAX_SIZE) {
		stack->data[stack->size] = data02;// ��ջ
		stack->size++;
	}
}


// ����ջ��Ԫ��
void* Top_SeqStack(SeqStack* stack) {

	if (stack == NULL || stack->size == 0) {
		return NULL;
	}
	else {
		return stack->data[stack->size - 1];
	}
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

/*
base == top�ǿ�ջ�ı�־
topָ�����ڶ���Ԫ��
top-base==stacksize��Ϊջ���ı�־
overflow:ջ�Ѿ����ˣ�����Ҫѹ��Ԫ�أ����һ���Ǹ�����
underflow��ջ�Ѿ����ˣ�����Ҫ����Ԫ�أ����ͨ����Ϊ��һ�������ı�־
*/


// ˳ʽջ
typedef struct SEQSTACK {

	int* top;  // ջ��ָ��
	int* base;  // ջ��ָ��
	int stackSize;  

}SeqStack;

typedef enum status
{
	ERROR, SUCCESS,
}Status;


// ջ�ĳ�ʼ��
Status Init_SeqStack(SeqStack* S);

// �ж�ջ�Ƿ�Ϊ��
Status isEmpty(SeqStack* S);

// ��ջ
Status Push_Stack(SeqStack* S, int e);

// ��ջ
Status PopStack(SeqStack* S);

// ��ջ��Ԫ�ظ���
int StackLen(SeqStack* S);

// ���ջ
Status ClearStack(SeqStack* S);

// ����ջ
Status DestoryStack(SeqStack* S);


#endif // !SEQSTACK_H