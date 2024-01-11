
void ShellSort( ElementType A[ ], int N, int Incre[ ], int M )
{	/* 希尔排序*/
	/* 其中Incre[]为包含M个增量的序列，递减有序，且最后一个元素为1 */
	int i, j, k, Increment;
	ElementType temp;

	for ( i = 0; i<M; i++ ) {
		Increment = Incre[ i ];	/* 选择该趟排序需要的增量 */
		for ( j = Increment; j < N; j++ ) { 
			temp = A[ j ];
			for ( k = j; k-Increment >= 0; k -= Increment ) {
				if ( temp >= A[ k - Increment ]) break;
                else
				    A[ k ] = A[ k - Increment ];
				A[k] = temp;
			} 
		} /* 结束一趟插入排序 */
	}
}
