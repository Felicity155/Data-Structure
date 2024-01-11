
ElementType DeleteQ ( LinkQueue  *PtrQ )
{
	Qnode  *FrontCell; 
	ElementType FrontElem;
	
	if  ( PtrQ->front == NULL) {
		printf("队列空");
		return ERROR;
	} 
	FrontCell = PtrQ->fornt;
	if ( PtrQ->front == PtrQ->rear) /* 若队列只有一个元素 */
		PtrQ->front = PtrQ->rear = NULL; /* 删除后队列置为空 */
	else                     
		PtrQ->front = PtrQ->front->Next;
	FrontElem = FrontCell->Data;

	free( FrontCell );  /* 释放被删除结点空间  */
	return  FrontElem;
}
