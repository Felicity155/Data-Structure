
ElementType Median( ElementType A[], int N )
{
	int i, j, max;
	ElementType t;

	for(i=0; i<N-1; i++) {
		max=i;
		for(j=i+1; j<N; j++)     /*内循环，找出最大值的下标max */
			if (A[j]>A[max]) max=j;
            /* 下面将最大值与待排序序列的第一个元素A[i]交换 */
			t=A[i];  A[i]=A[max];  A[max]=t;
	} /* 排序结束  */

	return A[(N-1)/2];  
    /* 数组中下标为（N-1）/2位置的元素就是序列中第 N/2 个元素*/
}
