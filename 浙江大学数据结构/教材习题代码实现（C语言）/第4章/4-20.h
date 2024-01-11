
typedef struct AVLTreeNode *AVLTree;
typedef struct AVLTreeNode{
	ElementType Data;
	AVLTree Left;
	AVLTree Right;
	int Height;
}

AVLTree AVL_Insertion ( ElementType X, AVLTree T )
{ /* 将X插入AVL树T中，并且返回调整后的AVL树 */
	if ( !T ) { /* 若插入空树，则新建包含一个结点的树 */
		T = malloc(sizeof(struct AVLTreeNode));
		T->Data = X;
		T->Height = 0;
		T->Left = T->Right = NULL;
	} /* if (插入空树) 结束 */

	else if (X < T->Element) { /* 插入T的左子树 */
		T->Left = AVL_Insertion(X, T->Left);
        if (GetHeight(T->Left) - GetHeight(T->Right) == 2 )
			/* 需要左旋 */
            if (X < T->Left->Data) 
               T = SingleLeftRotation(T);      /* 左单旋 */
            else 
               T = DoubleLeftRightRotation(T); /* 左-右双旋 */
	} /* else if (插入左子树) 结束 */
    
	else if (X > T->Element) { /* 插入T的右子树 */
		T->Right = AVL_Insertion(X, T->Right);
        if (GetHeight(T->Left) - GetHeight(T->Right) == -2 )
			/* 需要右旋 */
            if (X > T->Right->Data) 
               T = SingleRightRotation(T);     /* 右单旋 */
            else 
               T = DoubleRightLeftRotation(T); /* 右-左双旋 */
	} /* else if (插入右子树) 结束 */

    /* else X == T->Data，无须插入 */

	T->Height = Max(GetHeight(T->Left),GetHeight(T->Right))+1;
	/*更新树高*/
	
	return T;
}
