
void LevelOrderTraversal ( BinTree BT )
{ 
	Queue Q; 
	BinTree T;

	if ( !BT ) return; /* 若是空树则直接返回 */
	
	Q = CreatQueue( MaxSize ); /*创建并初始化队列Q*/
	AddQ( Q, BT );
	while ( !IsEmptyQ( Q ) ) {
		T = DeleteQ( Q );
		printf("%d\n", T->Data); /*访问取出队列的结点*/
		if ( T->Left )   AddQ( Q, T->Left );
		if ( T->Right )  AddQ( Q, T->Right );
	}
}
