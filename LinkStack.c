#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"LinkStack.h"

//��ʼ��ջ
Status initLStack(LinkStack** s) {
	
	*s = (LinkStack*)malloc(sizeof(LinkStack));
	(*s)->top = NULL; //ջ��ָ��ָ���
	(*s)->count = 0; //ջ��Ԫ�ظ�����ʼΪ0
    return SUCCESS;
}


//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack* s) {
	if (s->top) {  //ջ������
		printf("ջ��Ϊ��");
		return ERROR;
	}
	else {
		printf("ջΪ��");
		return SUCCESS;
	}
    return SUCCESS;
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack* S, ElemType* e) {
	if (!S->top)
		return ERROR;
	e = S->top->data;
	printf("%d\n", e);
	return SUCCESS;
}

//���ջ
Status clearLStack(LinkStack s) {
	
	LinkStackPtr p;
	//ջ��Ϊ��ʱ,����ѭ�����ͷ�ÿһ���ڵ�Ŀռ�
	while (s.top) {
		p = s.top;
		s.top = s.top->next;
		s.count--;
		free(p);
	}
    return SUCCESS;
}

//����ջ
Status destroyLStack(LinkStack** s) {

	clearLStack(**s); //�����ջ
	free(*s); //�ͷ�ջ���пռ�
    return SUCCESS;
}

//���ջ����
int LStackLength(LinkStack * s) {
	
    return  s->count;
}

//��ջ
Status pushLStack(LinkStack* s, ElemType e) {
    LinkStackPtr S = (LinkStackPtr)malloc(sizeof(StackNode));
    S->data = e;
    S->next = s->top;		//�ѵ�ǰ��ջ����ֵ���µ�Ԫ�صĺ��(ָ���ָ��)
    s->top = S;		//�µĽڵ㸳ֵ��ջ��ָ�루������Ԫ�س�Ϊջ��Ԫ�أ�
    s->count++;     
    return SUCCESS;
}

//��ջ
Status popLStack(LinkStack* s, ElemType e) {

    LinkStackPtr temp;		//��ʱ�ڵ�
	if (!s->top) {
		return ERROR;
	}
        
    else
    {
        e = s->top->data;
        temp = s->top;		//��ջ��ָ�뽻��temp 
        s->top = s->top->next;	//ʹ��ջ��ָ������һλ
        s->count--;			//��������һ 
        free(temp);		//��Ϊ�ڵ㱻ɾ��������Ҫ�ͷ���ʱ�ڵ�		
        return SUCCESS;
    }
}


void print_help(void) {
	printf("************************************************\n");
	printf("         ��ӭ�������װ���ջ����ϵͳ\n");
	printf("************************************************\n");
	printf("        ���� 1 ��ʼ��ջ\n");
	printf("        ���� 2 �жϿ�ջ\n");
	printf("        ���� 3 ����ջ��\n");
	printf("        ���� 4 ���ջ��\n");
	printf("        ���� 5 ���ջ\n");
	printf("        ���� 6 ��ջ\n");
	printf("        ���� 7 ��ջ\n");
	printf("        ���� 8 �鿴������Ϣ\n");
	printf("       ���� 9 ����ջ���˳�����ϵͳ\n");
	printf("************************************************\n");
}


int main(void) {

	int* value02 = NULL;
	LinkStack* s = NULL;
	LinkStack** s2 = &s;
	int num, ops, value;

	print_help();
	while (1)
	{
		printf("Please input ops:\n");
		scanf("%d", &ops);

		switch (ops)
		{
		case 1:
			num = initLStack(&s);
			printf("%d\n", num);
			break;
		case 2:
			num = isEmptyLStack(s);
			printf("%d\n", num);
			break;
		case 3:
			num = getTopLStack(s, value02);
			printf("%d\n", num);
			break;
		case 4:
			num = LStackLength(s);
			printf("%d\n", num);
			break;
		case 5:
			num = clearLStack(*s);
			printf("%d\n", num);
			break;
		case 6:
			printf("������Ҫ��ջ��Ԫ��(������)��\n");
			scanf("%d", &value);
			num = pushLStack(s, value);
			printf("%d\n", num);
			break;
		case 7:
			printf("������Ҫ��ջ��Ԫ��(������)��\n");
			scanf("%d", &value);
			num = popLStack(s, value);
			printf("%d\n", num);
			break;
		case 8:
			print_help();
			break;
		case 9:
			destroyLStack(s2);
			printf("SUCCESS");
			return;
			break;
		}
	}
}
