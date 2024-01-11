
Position Find( ElementType X, BinTree BST )
{
	if( !BST ) return NULL; /*查找失败*/
	
	if( X > BST->Data ) 
		return Find( X, BST->Right );    /*在右子树中继续查找*/
	else
		if( X < BST->Data ) 
			return Find( X, BST->Left ); /*在左子树中继续查找*/
		else /* X == BST->Data */
			return BST;  /*查找成功，返回结点的找到结点的地址*/
}
