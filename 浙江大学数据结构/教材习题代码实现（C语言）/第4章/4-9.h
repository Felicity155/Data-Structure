
void InOrderTraversal( BinTree BT )
{
	BinTree T;
	Stack S = CreatStack( MaxSize ); /*创建并初始化堆栈S*/

	T = BT;
	while( T || !IsEmpty(S) ){
		while(T){ /*一直向左并将沿途结点压入堆栈*/
			Push(S,T); 
			T = T->Left; 
		}
		if( !IsEmpty(S) ){
			T = Pop(S); /*结点弹出堆栈*/
            printf("%5d", T->Data); /*（访问）打印结点*/
			T = T->Right; /*转向右子树*/
		}
	}
}
