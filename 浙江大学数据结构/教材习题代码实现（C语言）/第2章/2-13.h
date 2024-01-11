#include <malloc.h>

ElementType Median( ElementType S[], int N )
{   
	ElementType  *p, m;

	/* 申请临时数组大小所需要的空间*/
	P = (ElementType *)malloc(sizeof(ElementType)*N);
	m = FindKthLargest(S, (N+1)/2, 0, N-1, p);
	free(p);     /* 释放临时数组空间 */
	return m;
}
