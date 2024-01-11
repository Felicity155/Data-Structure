
void Delete( int  i, List *PtrL )
{
	int  j;

	if( i < 1 || i > PtrL->Last+1 ) { /*检查空表及删除位置的合法性*/
		printf ("不存在第%d个元素", i ); 
		return ; 
	}
	for( j = i; j <= PtrL->Last; j++ )
		PtrL->Data[j-1]= PtrL->Data[j]; /*将a[i+1]～a[n]顺序向前移动*/
	PtrL->Last--;    /*Last仍指向最后元素*/
	return;   
}
