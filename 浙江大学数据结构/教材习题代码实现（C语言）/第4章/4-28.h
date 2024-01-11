
int Find( SetType S[ ], ElementType X )
{  /* 在数组S中查找值为X的元素所属的集合 */
   /* MaxSize是全局变量，为数组S的最大长度 */
	int i;
	
	for ( i=0; i < MaxSize && S[i].Data != X; i++) ;
	if( i >= MaxSize ) return -1; /* 未找到X，返回-1 */
	for( ; S[i].Parent > 0; i = S[i].Parent ) ;

	return i; /* 找到X所属集合，返回树根结点在数组S中的下标 */
}
