
ElementType Average( ElementType S[], int N )
{   /* 求集合元素的平均值。集合元素存放在数组S中，数组大小为N */
	int i;
	ElementType Sum=0;

    for(i=0; i<N; i++)
		Sum += S[i];     /* 将数组元素累加到Sum中 */
    return Sum/N;
}
