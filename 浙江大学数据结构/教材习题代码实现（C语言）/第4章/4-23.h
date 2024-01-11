
MaxHeap Create( int MaxSize )
{   /* 创建容量为MaxSize的空的最大堆 */
	MaxHeap H = malloc( sizeof( struct HeapStruct ) );
	H->Elements = malloc( (MaxSize+1) * sizeof( ElementType ) );
	H->Size = 0;
	H->Capacity = MaxSize;
	H->Elements[0] = MaxData; /* 定义"哨兵"为大于堆中所有可能元素的值*/

	return H;
}
