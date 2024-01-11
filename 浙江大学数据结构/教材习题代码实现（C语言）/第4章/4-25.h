
ElementType DeleteMax( MaxHeap H )
{   /* 从最大堆H中取出键值为最大的元素，并删除一个结点 */
    int Parent, Child;
    ElementType MaxItem, temp;

    if ( IsEmpty(H) ) {
        printf("最大堆已为空");
        return;
    }

    MaxItem = H->Elements[1]; /* 取出根结点最大值 */
    /* 用最大堆中最后一个元素从根结点开始向上过滤下层结点 */
    temp = H->Elements[H->Size--];
	for( Parent=1; Parent*2<=H->Size; Parent=Child ) {
		Child = Parent * 2;
        if( (Child!= H->Size) && (H->Elements[Child] < H->Elements[Child+1]) )
            Child++;  /* Child指向左右子结点的较大者 */
        if( temp >= H->Elements[Child] ) break;
		else  /* 移动temp元素到下一层 */
			H->Elements[Parent] = H->Elements[Child];
    }
    H->Elements[Parent] = temp;

    return MaxItem;
} 
