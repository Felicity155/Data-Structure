
void SimpleSelectionSort( ElementType A[], int N )
{   /* 简单选择排序 */
	int i, j, min, temp;

	for (i = 0; i < N - 1; i++) { /*寻找最小元素*/
		min = i;
		for (j = i+1; j < N; j++)
			if (A[j] < A[min])
				min = j;
			/* 将第i个元素与最小元素交换 */
			temp = A[i];
			A[i] = A[min];
			A[min] = temp;
	}
}
