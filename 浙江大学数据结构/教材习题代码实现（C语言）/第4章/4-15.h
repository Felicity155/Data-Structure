
Position IterFind( ElementType X, BinTree BST )
{
    while( BST ) {
        if( X > BST->Data )
			BST = BST->Right;    /*向右子树中移动，继续查找*/
        else
            if( X < BST->Data )
				BST = BST->Left; /*向左子树中移动，继续查找*/
            else /* X == BST->Data */
                return BST; /*查找成功，返回结点的找到结点的地址*/
    }
    return NULL; /*查找失败*/
}
