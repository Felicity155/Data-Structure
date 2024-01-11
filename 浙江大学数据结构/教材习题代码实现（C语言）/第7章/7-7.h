
void Merge( ElementType A[], ElementType TmpA[], int Left, int Mid, int Right )
{	/* 将有序的A[Left]~A[Mid-1]和A[Mid]~A[Right]归并成一个有序序列 */
	int Tp, LeftEnd, i;

	Tp = Left; /* 有序序列的起始位置 */
	LeftEnd = Mid - 1; /* 左边序列终止的位置 */
	while ( ( Left<LeftEnd ) && ( Mid<Right ) )
		if ( A[Left] <= A[Mid] )
			TmpA[Tp++] = A[Left++]; /* 将左边元素复制到TmpA */
		else
			TmpA[Tp++] = A[Mid++]; /* 将右边元素复制到TmpA */
		while ( Left <= LeftEnd ) /* 如果左边有元素剩下而右边已经结束 */
			TmpA[Tp++] = A[Left++]; /* 将左边剩余元素复制到TmpA */
		while ( Mid <= Right ) /* 如果右边有元素剩下而左边已经结束 */
			TmpA[Tp++] = A[Mid++]; /* 将右边剩余元素复制到TmpA */
		for ( i=Right-Left; i>=0; i--, Right-- ) 
			A[Right] = TmpA[Right]; /* 将有序的TmpA[]复制回A[]*/
}

void MSort( ElementType A[], ElementType TmpA[], int Left, int Right )
{	/* 递归地将A[Left]~A[Right]排序 */
	if ( Left < Right ) {
		MSort(A, TmpA, Left, (Left+Right)/2);     /*递归排左半边*/
		MSort(A, TmpA, (Left+Right)/2+1, Right); /*递归排右半边*/
		Merge(A, TmpA, Left, (Left+Right)/2+1, Right); /*归并*/
	}
}

void MergeSort( ElementType A[], int N )
{   /* 归并排序 */
	ElementType *TmpA;

	TmpA = malloc( N * sizeof(ElementType) ); /*开辟临时空间*/
	MSort( A, TmpA, 0, N-1);
	free( TmpA );
}
