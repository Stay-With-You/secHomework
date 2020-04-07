#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "SeqStack.h"

// ��ʼ��ջ
SqStack* initStack(void) {

	SqStack* s = NULL;// ��ʼ��Ϊ��
	s = (SqStack*)malloc(sizeof(SqStack));//��������һ���ռ��ű�
	//    s = (Seqs*)malloc(-1); //ʧ�ܣ�
	//     malloc����ûִ�������sû�г�ʼ����ָ�����Ұָ��
	if (NULL == s) {  //����malloc��NULL���ʼ����NULL
		return ERROR;
	}
	
	s->top = -1;
	return s;
}

// �ж�ջ�Ƿ�Ϊ��
Status isEmptyStack(SqStack* s) {

	return (s->top == -1 ? SUCCESS : ERROR);
}

// �õ�ջ��Ԫ��
Status getTopStack(SqStack* s) {

	if (s->top == -1)
		return ERROR;
	else {
		printf("%d\n", s->data[s->top]);
	}
	return SUCCESS;
}

// ���ջ
Status clearStack(SqStack* s) {

	if (isEmptyStack(s)) {
		s->top = -1;
	}
	return SUCCESS;
}

// ����ջ
Status destroyStack(SqStack** s) {

	if (isEmptyStack(s)) {
		return ERROR;
	}
	free(*s);
	*s = NULL;
	return SUCCESS;
}

// ���ջ����
Status stackLength(SqStack* s) {

	if (isEmptyStack(s)) {
		return ERROR;
	}
	printf("%d\n", s->top + 1);
	return SUCCESS;
}

// ��ջ
Status pushStack(SqStack* s, ElemType pos, ElemType value) {
	
	if ((NULL == s) || (s->top == (MAXSIZE - 1)) || (pos < 0 || pos > s->top + 1)) {
		return ERROR;
	}
	// �Ѳ����posλ�õ�ĩβ�������ֵ��������ƶ�
	// �����±�pos��s->top�������һλ
	for (int i = s->top; i >= pos; i--)
	{
		s->data[i + 1] = s->data[i];
	}

	s->data[pos] = value;
	s->top++;
	return SUCCESS;
}

// ��ջ
Status popStack(SqStack* s, ElemType pos, ElemType* value) {
	
	if ((NULL == s) || (isEmptyStack(s) == 1) || (pos < 0 || pos > s->top)) {
		return ERROR;
	}
	*value = s->data[pos];// ȡ��Ҫɾ��λ�õ�����
	// ��Ҫ�ƶ��������±귶Χ��pos + 1 �� top
	// Ҫɾ����λ��pos��Ҫ�ƶ����ݵ�λ��pos+1��top
	// pos�����һ��λ��ʱ��ѭ�����������㣬ֱ�Ӳ�ִ����λ
	for (int i = pos; i < s->top; i++)
	{
		s->data[i] = s->data[i + 1];
	}
	s->top--;
	return SUCCESS;
}

void print_help(void) {
	printf("************************************************\n");
	printf("         ��ӭ�������װ�ջ����ϵͳ\n");
	printf("************************************************\n");
	printf("        ���� 1 ��ʼ��ջ\n");
	printf("        ���� 2 �жϿ�ջ\n");
	printf("        ���� 3 ����ջ��\n");
	printf("        ���� 4 ���ջ��\n");
	printf("        ���� 5 ���ջ\n");
	printf("        ���� 6 ��ջ(��0��ʼ��\n");
	printf("        ���� 7 ��ջ\n");
	printf("        ���� 8 �鿴������Ϣ\n");
	printf("       ���� 9 ����ջ���˳�����ϵͳ\n");
	printf("************************************************\n");
}


int main(void) {

	SqStack* s = NULL;
	ElemType value01, ops, num, pos;
	ElemType* value02 = NULL;

	print_help();
	while (1)
	{

		printf("Please input ops:\n");
		scanf("%d", &ops);
	
		switch (ops)
		{
		case 1:
			s = initStack();
			break;
		case 2:
			num = isEmptyStack(s);
			printf("%d\n", num);
			break;
		case 3:
			num = getTopStack(s);
			printf("%d\n", num);
			break;
		case 4:
			num = stackLength(s);
			printf("%d\n", num);
			break;
		case 5:
			num = clearStack(s);
			printf("%d\n", num);
			break;
		case 6:
			printf("������Ҫ��ջ��λ��\n");
			scanf("%d", &pos);
			printf("������Ҫ��ջ��Ԫ��(������)��\n");
			scanf("%d", &value01);
			num = pushStack(s, pos, value01);
			printf("%d\n", num);
			break;
		case 7:
			printf("������Ҫ��ջ��λ��\n");
			scanf("%d", &pos);
			printf("������Ҫ��ջ��Ԫ��(������)��\n");
			scanf("%d", value02);
			num = popStack(s, pos, value02);
			printf("%d\n", num);
			break;
		case 8:
			print_help();
			break;
		case 9:
			destroyStack(&s);
			printf("SUCCESS");
			return;
			break;
			
		}

	
	
	}

}
