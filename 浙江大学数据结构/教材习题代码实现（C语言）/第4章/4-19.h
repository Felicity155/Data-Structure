
BinTree Delete( ElementType X, BinTree BST ) 
{ 
    Position Tmp; 

    if( !BST ) 
        printf("要删除的元素未找到"); 
    else 
        if( X < BST->Data ) 
            BST->Left=Delete( X, BST->Left);       /* 左子树递归删除 */
        else
            if( X > BST->Data ) 
                BST->Right=Delete( X, BST->Right); /* 右子树递归删除 */
            else /*找到要删除的结点 */ 
                if( BST->Left && BST->Right ) {
                    /*被删除结点有左右两个子结点 */ 

                    Tmp = FindMin( BST->Right ); 
                    /*在右子树中找最小的元素填充删除结点*/

                    BST->Data = Tmp->Data; 

                    BST->Right = Delete( BST->Data, BST->Right);
					/*在删除结点的右子树中删除最小元素*/
                } 
                else { /*被删除结点有一个或无子结点*/
                    Tmp = BST; 
                    if( !BST->Left )       /* 有右孩子或无子结点 */
                        BST = BST->Right; 
                    else if( !BST->Right ) /* 有左孩子或无子结点 */
                        BST = BST->Left;
                    free( Tmp );
                }
    return BST;
}
