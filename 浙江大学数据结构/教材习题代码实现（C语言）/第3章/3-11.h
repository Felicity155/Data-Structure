
ElementType Pop( Stack *PtrS )
{
    if ( PtrS->Top == -1 ) {
		printf("堆栈空");
		return ERROR; /* ERROR是ElementType的特殊值，标志错误 */
	}
	else 
		return ( PtrS->Data[(PtrS->Top)--] );
}
