
void Insert( MaxHeap H, ElementType item )
{ /* 将元素item 插入最大堆H，其中H->Elements[0]已经定义为哨兵 */
    int i;
 
	if ( IsFull(H) ) { 
        printf("最大堆已满");
        return;
    }

	i = ++H->Size; /* i指向插入后堆中的最后一个元素的位置 */
	for ( ; H->Elements[i/2] < item; i/=2 )
        H->Elements[i] = H->Elements[i/2]; /* 向下过滤结点 */
	H->Elements[i] = item; /* 将item 插入 */
}
