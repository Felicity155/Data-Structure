
void BubbleSort ( ElementType A[ ], int N )
{   /*冒泡排序*/
	int i, j ;
	bool flag;
	ElementType temp;

	for ( i = N - 1; i >= 0; i--) {
		flag = 0 ; /*标记该次循环中是否发生交换，若无，则说明整个序列有序*/
		for ( j = 0; j < i; j++ ) {
			/*每次循环找出一个最大元素，被交换到最右端*/
			if ( A[ j ] > A[ j + 1 ] ) {
				temp = A[ j ] ;
				A[ j ] = A[ j + 1 ] ;
				A[ j + 1 ] = temp ;
				flag = 1 ;		/*若发生交换，则标记*/
			}
		}
		if ( !flag ) break ;		/*若没有发生交换，则跳出循环*/
	}
}
