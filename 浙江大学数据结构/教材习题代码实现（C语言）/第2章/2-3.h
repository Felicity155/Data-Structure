
float Max(float A[], int N)    
{  /*  求N个元素数组中的最大值  */
	float CurMax = A[0];
	int i;

	for(i=1; i<N; i++)
		if (A[i]>CurMax)
			CurMax=A[i];

	return CurMax;
}
