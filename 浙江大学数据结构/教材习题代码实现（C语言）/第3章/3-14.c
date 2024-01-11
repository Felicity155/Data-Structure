#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MAXOP 100    /* 操作数序列可能的最大长度 */
#define MaxSize 100  /* 堆栈元素最大个数 */
#define NUMBER 0      /* 操作数的标识 */
typedef double ElementType; /* 将堆栈的元素类型具体化 */

/* 关于堆栈的代码请参见堆栈的定义和代码3.10、3.11 */
typedef struct {
		ElementType Data[MaxSize];
		int Top;
} Stack;
#define ERROR -1 /* 当堆栈为空时返回错误，这里默认正确返回值全是正的 */

#include "3-10.h"
#include "3-11.h"

int GetOp( char s[] )
{   /* 从输入中获得下一个对象（操作数或运算符），并保存在字符数组s中*/
    /* 返回值为NUMBER或运算符本身 */
	int i, c;

    /* 跳过表达式前空格等字符 */
	while ( (s[0] = c = getchar()) == ' ' || c == '\t' ); 

	s[1]= '\0';
	if ( !isdigit(c) && c!= '.' ) /* 如果c是运算符 */
		return c;  /* 直接返回运算符 */
	i = 0;
	if( isdigit(c) ) /* 如果c是数字，则一直读完连续的数字并存入s */
		while ( isdigit(s[++i] = c = getchar()) );
	if( c == '.' ) /* 如果有小数点，则继续读完小数点后的连续数字 */
		while ( isdigit(s[++i]=getchar()) );
	s[i] = '\0'; /* 完成对实数字符串的存储 */
	return NUMBER;  /* 表示此时s中存的是一个数字 */
}

int main()
{	
	int Type;
	double Op2;
	char s[MAXOP];
    Stack *PtrS;

	/* 申请一个新堆栈，PtrS指向该堆栈 */
	PtrS = (Stack *)malloc(sizeof(Stack)); 
	PtrS->Top = -1;

    while( (Type = GetOp(s))!=EOF ) { /* 当未读到输入结束时 */
		switch (Type) {
			case NUMBER: Push(PtrS, atof(s)); break;
			case '+': Push(PtrS, Pop(PtrS) + Pop(PtrS));  break;
			case '*': Push(PtrS, Pop(PtrS) * Pop(PtrS));  break;
			case '-': 
				Op2 = Pop(PtrS); 
				Push( PtrS, Pop(PtrS) - Op2);
				break;
			case '/': 
				Op2 = Pop(PtrS);
				if( Op2 != 0.0 ) /* 检查除法的分母是否为0 */
					Push(PtrS, Pop(PtrS)/Op2);
				else
					printf("error: zero divisor\n");
				break;
			case '\n': printf("%.8g\n", Pop(PtrS)); break;
		    default: printf("error: unknown command %s \n", s); break;
		}
	}

	free(PtrS);    /* 释放堆栈 */
	return 0;
}
