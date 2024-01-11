
void Insert( ElementType X, int i, List *PtrL )
{
	int j;

	if ( PtrL->Last == MAXSIZE－1) {
		/* 表空间已满，不能插入*/
		printf("表满"); 
		return; 
	}  
	if ( i < 1 || i > PtrL->Last+2) { /*检查插入位置的合法性*/
		printf("位置不合法");
		return; 
	} 
	for( j = PtrL->Last; j >= i-1; j-- )
		PtrL->Data[j+1] = PtrL->Data[j]; /*将 ～ 顺序向后移动*/
	PtrL->Data[i-1] = X;  /*新元素插入*/
	PtrL->Last++;          /*Last仍指向最后元素*/
	return; 
} 
