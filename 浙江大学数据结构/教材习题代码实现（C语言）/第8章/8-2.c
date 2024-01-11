#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100
#define MaxProc 60
#define MaxWindow 10
#include "8-1.h"

typedef struct People ElementType;

int IsEmpty( Queue Q )
{
	if ( Q->front == Q->rear ) 
		return 1;
	else  
		return  0;
}

void AddQ( Queue Q, ElementType item )
{         
     if ( (Q->rear+1) % MaxSize == Q->front ) {
		 printf("队列满");
		 return;
	 }
	 Q->rear =(Q->rear+1)% MaxSize;
	 Q->Customer[Q->rear] = item;
	 Q->size++;
}

ElementType DeleteQ ( Queue Q )
{       
	ElementType ERROR;

	if ( IsEmpty(Q) ) { 
		printf("队列空");
		ERROR.T = -1; /* 错误标志 */
		return ERROR;
	}
	else  {
		Q->front =(Q->front+1)% MaxSize;
		return  Q->Customer[Q->front];
	}
} 

#include "8-3.h"
#include "8-5.h"
#include "8-4.h"

int main()
{	int N;    /* 顾客总数 */
	Queue Q;  /* 顾客队列 */

	scanf("%d", &N);  /* 读入顾客人数 */
	Q = CreateQueue( N ); /* 建立顾客队列 */

	/* 打印出N位顾客平均等待时间 */
	printf("Average waiting time = %.1lf minute(s).\n", QueueingAtBank( Q, N ));
	
	return 0;
}
