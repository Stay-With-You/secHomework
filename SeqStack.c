#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "SeqStack.h"

// 初始化栈
SqStack* initStack(void) {

	SqStack* s = NULL;// 初始化为空
	s = (SqStack*)malloc(sizeof(SqStack));//堆中申请一个空间存放表
	//    s = (Seqs*)malloc(-1); //失败，
	//     malloc函数没执行情况，s没有初始化，指向的是野指针
	if (NULL == s) {  //区分malloc的NULL与初始化的NULL
		return ERROR;
	}
	
	s->top = -1;
	return s;
}

// 判断栈是否为空
Status isEmptyStack(SqStack* s) {

	return (s->top == -1 ? SUCCESS : ERROR);
}

// 得到栈顶元素
Status getTopStack(SqStack* s) {

	if (s->top == -1)
		return ERROR;
	else {
		printf("%d\n", s->data[s->top]);
	}
	return SUCCESS;
}

// 清空栈
Status clearStack(SqStack* s) {

	if (isEmptyStack(s)) {
		s->top = -1;
	}
	return SUCCESS;
}

// 销毁栈
Status destroyStack(SqStack** s) {

	if (isEmptyStack(s)) {
		return ERROR;
	}
	free(*s);
	*s = NULL;
	return SUCCESS;
}

// 检测栈长度
Status stackLength(SqStack* s) {

	if (isEmptyStack(s)) {
		return ERROR;
	}
	printf("%d\n", s->top + 1);
	return SUCCESS;
}

// 入栈
Status pushStack(SqStack* s, ElemType pos, ElemType value) {
	
	if ((NULL == s) || (s->top == (MAXSIZE - 1)) || (pos < 0 || pos > s->top + 1)) {
		return ERROR;
	}
	// 把插入的pos位置到末尾这区域的值集体向后移动
	// 就是下标pos至s->top集体后移一位
	for (int i = s->top; i >= pos; i--)
	{
		s->data[i + 1] = s->data[i];
	}

	s->data[pos] = value;
	s->top++;
	return SUCCESS;
}

// 出栈
Status popStack(SqStack* s, ElemType pos, ElemType* value) {
	
	if ((NULL == s) || (isEmptyStack(s) == 1) || (pos < 0 || pos > s->top)) {
		return ERROR;
	}
	*value = s->data[pos];// 取出要删除位置的数据
	// 需要移动的数据下标范围，pos + 1 ～ top
	// 要删除的位置pos，要移动数据的位置pos+1～top
	// pos在最后一个位置时，循环条件不满足，直接不执行移位
	for (int i = pos; i < s->top; i++)
	{
		s->data[i] = s->data[i + 1];
	}
	s->top--;
	return SUCCESS;
}

void print_help(void) {
	printf("************************************************\n");
	printf("         欢迎来到简易版栈管理系统\n");
	printf("************************************************\n");
	printf("        输入 1 初始化栈\n");
	printf("        输入 2 判断空栈\n");
	printf("        输入 3 访问栈顶\n");
	printf("        输入 4 检测栈长\n");
	printf("        输入 5 清空栈\n");
	printf("        输入 6 入栈(从0开始）\n");
	printf("        输入 7 出栈\n");
	printf("        输入 8 查看帮助信息\n");
	printf("       输入 9 销毁栈并退出管理系统\n");
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
			printf("请输入要入栈的位置\n");
			scanf("%d", &pos);
			printf("请输入要入栈的元素(纯数字)：\n");
			scanf("%d", &value01);
			num = pushStack(s, pos, value01);
			printf("%d\n", num);
			break;
		case 7:
			printf("请输入要出栈的位置\n");
			scanf("%d", &pos);
			printf("请输入要出栈的元素(纯数字)：\n");
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
