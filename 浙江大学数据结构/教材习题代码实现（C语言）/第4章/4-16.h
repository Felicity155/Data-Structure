
Position FindMin( BinTree BST )
{
    if( !BST ) return NULL; /*空的二叉搜索树，返回NULL*/
    else
        if( !BST->Left ) return BST; /*找到最左叶结点并返回*/
        else
            return FindMin( BST->Left ); /*沿左分支继续查找*/
}
