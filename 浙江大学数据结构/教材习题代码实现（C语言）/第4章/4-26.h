
MaxHeap BuildMaxHeap( MaxHeap H )
{   /* 这里假设所有H->Size个元素已经存在H->Elements[]中     */
    /* 本函数将H->Elements[]中的元素调整，使满足最大堆的有序性 */
	int Parent, Child, i;
	ElementType temp;

	for( i = H->Size/2; i>0; i-- ){ /*从最后一个结点的父结点开始 */
		temp = H->Elements[i];
		for( Parent=i; Parent*2<=H->Size; Parent=Child ) { /* 向下过滤 */
			Child = Parent * 2;
            if( (Child!= H->Size) && (H->Elements[Child] < H->Elements[Child+1]) )
                Child++;  /* Child指向左右子结点的较大者 */
            if( temp >= H->Elements[Child] ) break;
			else  /* 移动temp元素到下一层 */
				H->Elements[Parent] = H->Elements[Child];
		} /* 结束内部for循环对以H->Elements[i]为根的子树的调整 */
		H->Elements[Parent] = temp;
	}

	return H;
}
