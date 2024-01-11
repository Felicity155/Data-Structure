
BinTree CreatBinTree( )
{
	int Data;
	BinTree BT, T;
	Queue Q = CreatQueue( MaxSize ); /*生成一个队列*/
	
	scanf("%d", &Data); /* 建立第1个结点，即根结点 */
	if( Data ){ /*分配根结点单元，并将结点地址入队*/
		BT =(BinTree) malloc(sizeof(BinTree));
		BT->Data = Data;
		AddQ( Q, BT );
	}
	else return NULL; /* 若第1个数据就是0，返回空树 */

	while( !IsEmptyQ( Q ) ){
		T = DeleteQ( Q ); /*从队列中取出一结点地址*/
		scanf("%d", &Data); /* 读入T的左孩子 */
		if( !Data ) T->Left = NULL;
		else {  /*分配新结点，作为出队结点左孩子；新结点入队*/
			T->Left = (BinTree) malloc(sizeof(BinTree));
			T->Left->Data = Data;
			AddQ( Q, T->Left );
		}
		scanf("%d", &Data); /* 读入T的右孩子 */
		if( !Data ) T->Right = NULL;
		else {  /*分配新结点，作为出队结点右孩子；新结点入队*/
			T->Right = (BinTree) malloc(sizeof(BinTree));
			T->Right->Data = Data;
			AddQ( Q, T->Right );
		}
	} /* 结束while */
	return BT;
}
