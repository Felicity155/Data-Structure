
Position FindMax( BinTree BST )
{
    if( !BST ) 
        while( BST->Right )
            BST = BST->Right; /*沿右分支继续查找，直到最右叶结点*/
    return BST;
}
