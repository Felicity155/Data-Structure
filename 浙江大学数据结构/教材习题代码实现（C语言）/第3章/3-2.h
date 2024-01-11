
int Find( ElementType X, List *PtrL )
{
	int i = 0;

	while( i <= PtrL->Last && PtrL->Data[i]!= X )
		i++;
	if ( i > PtrL->Last )  return -1; /* 如果没找到，返回-1 */
	else  return i;  /* 找到后返回的是存储位置 */
}
