#include <stdio.h>

void PrintN ( int N );

int main ()
{   /* 读入整数N，并调用PrintN函数 */
	int N;

	scanf("%d", &N);
	PrintN( N );
	return 0;
}

/* 运行时可使用下列两个*.h文件之一 */
/* #include "1-1.h" */
/* #include "1-2.h" */
