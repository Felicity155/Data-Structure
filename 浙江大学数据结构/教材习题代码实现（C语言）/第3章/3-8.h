
List *Insert( ElementType X, int i, List *PtrL )
{
	List  *p, *s;

	if ( i == 1 ) {     /* 新结点插入在表头 */
		s = (List *)malloc(sizeof(List)); /*申请、填装结点*/
		s->Data = X; 
		s->Next = PtrL;
		return s;      /*返回新表头指针*/
    }
    p = FindKth( i-1, PtrL );   /* 查找第i-1个结点 */
    if ( p == NULL ) {  /* 第i-1个不存在，不能插入 */
		printf("参数i错");
		return NULL; 
	}
	else {
		s = (List *)malloc(sizeof(List)); /*申请、填装结点*/
		s->Data = X; 
		s->Next = p->Next;     /*新结点插入在第i-1个结点的后面*/
		p->Next = s; 
		return PtrL;
	}
}
