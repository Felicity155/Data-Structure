
ElementType KthLargest( ElementType S[], int K)
{   /* 此为伪代码 */
	
	/* 选取S中的第一个元素e; */
	/* 根据e将集合S分解为大于等于e 的元素集合S1和小于e的元素集合S2;*/
	if (|S1|>K) return KthLargest(S1，K);
	else if (|S1|<K) return KthLargest(S2，K-|S1|);
	else return e;      
}
