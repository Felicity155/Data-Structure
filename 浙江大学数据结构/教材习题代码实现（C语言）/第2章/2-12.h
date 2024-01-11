void Swap ( ElementType *a, ElementType *b )
{   /*交换a和b两个元素*/
	ElementType temp = *a ;
	*a = *b ; 
	*b = temp ;
}

ElementType FindKthLargest ( ElementType S[ ], int K, int Low, int High )
{  /* 在S[Low]..S[High]中找第K大整数  */
	ElementType Pivot = S[Low]; /* 简单取首元素为基准 */
	int Left = Low, Right = High;

	if ( Low >= High ) return Pivot;
	Swap ( &S[Low], &S[Right] ) ; /*将基准与最后一个元素交换*/
	while (1) {/*将序列中比基准大的移到基准左边，小的移到右边*/
		while ( (Low<High)&&(Pivot <= S[Low]) ) Low++ ;
		while ( (Low<High)&&(Pivot >= S[High]) ) High-- ;
        if ( Low < High )
		    Swap ( &S[Low], &S[High] ) ;
		else  break;
	}
    Swap ( &S[Low], &S[Right] ) ; /* 将最后的基准换到正确的位置 */
	if ( K <= High-Left ) /* High-Left代表了集合S1的大小*/
		return FindKthLargest(S, K, Left, High-1); /*在集合S1中继续找 */
	else if ( K == High-Left+1 ) /* 找到，返回 */
		return Pivot;
	else /*在集合S2中找 */
		return FindKthLargest(S, K-High+Left-1, High+1, Right);
}
