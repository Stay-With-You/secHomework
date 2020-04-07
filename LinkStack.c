#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"LinkStack.h"

//初始化栈
Status initLStack(LinkStack** s) {
	
	*s = (LinkStack*)malloc(sizeof(LinkStack));
	(*s)->top = NULL; //栈顶指针指向空
	(*s)->count = 0; //栈中元素个数初始为0
    return SUCCESS;
}


//判断栈是否为空
Status isEmptyLStack(LinkStack* s) {
	if (s->top) {  //栈顶存在
		printf("栈不为空");
		return ERROR;
	}
	else {
		printf("栈为空");
		return SUCCESS;
	}
    return SUCCESS;
}

//得到栈顶元素
Status getTopLStack(LinkStack* S, ElemType* e) {
	if (!S->top)
		return ERROR;
	e = S->top->data;
	printf("%d\n", e);
	return SUCCESS;
}

//清空栈
Status clearLStack(LinkStack s) {
	
	LinkStackPtr p;
	//栈不为空时,进行循环，释放每一个节点的空间
	while (s.top) {
		p = s.top;
		s.top = s.top->next;
		s.count--;
		free(p);
	}
    return SUCCESS;
}

//销毁栈
Status destroyLStack(LinkStack** s) {

	clearLStack(**s); //先清空栈
	free(*s); //释放栈所有空间
    return SUCCESS;
}

//检测栈长度
int LStackLength(LinkStack * s) {
	
    return  s->count;
}

//入栈
Status pushLStack(LinkStack* s, ElemType e) {
    LinkStackPtr S = (LinkStackPtr)malloc(sizeof(StackNode));
    S->data = e;
    S->next = s->top;		//把当前的栈顶赋值给新的元素的后继(指针的指向)
    s->top = S;		//新的节点赋值给栈顶指针（即让新元素成为栈顶元素）
    s->count++;     
    return SUCCESS;
}

//出栈
Status popLStack(LinkStack* s, ElemType e) {

    LinkStackPtr temp;		//临时节点
	if (!s->top) {
		return ERROR;
	}
        
    else
    {
        e = s->top->data;
        temp = s->top;		//将栈顶指针交给temp 
        s->top = s->top->next;	//使得栈顶指针下移一位
        s->count--;			//计数器减一 
        free(temp);		//因为节点被删除，所以要释放临时节点		
        return SUCCESS;
    }
}


void print_help(void) {
	printf("************************************************\n");
	printf("         欢迎来到简易版链栈管理系统\n");
	printf("************************************************\n");
	printf("        输入 1 初始化栈\n");
	printf("        输入 2 判断空栈\n");
	printf("        输入 3 访问栈顶\n");
	printf("        输入 4 检测栈长\n");
	printf("        输入 5 清空栈\n");
	printf("        输入 6 入栈\n");
	printf("        输入 7 出栈\n");
	printf("        输入 8 查看帮助信息\n");
	printf("       输入 9 销毁栈并退出管理系统\n");
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
			printf("请输入要入栈的元素(纯数字)：\n");
			scanf("%d", &value);
			num = pushLStack(s, value);
			printf("%d\n", num);
			break;
		case 7:
			printf("请输入要出栈的元素(纯数字)：\n");
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
