
List *Delete( int  i, List *PtrL )
{
	List  *p, *s;

	if ( i == 1 ) {            /* 删除表的第一个结点 */
		s = PtrL;              /*s指向第1个结点*/
		PtrL = PtrL->Next;     /*从链表中删除*/
		free(s);               /*释放被删除结点 */
		return PtrL;
	}
	p = FindKth( i-1, PtrL );  /*查找第i-1个结点*/
    if ( p == NULL ) { 
		printf("第%d个结点不存在", i-1);
		return NULL; 
	}
	else  if ( p->Next == NULL ){ 
		printf("第%d个结点不存在", i);
		return NULL; 
	}
	else  {
		s = p->Next;          /*s指向第i个结点*/
		p->Next = s->Next;    /*从链表中删除*/
		free(s);              /*释放被删除结点 */
		return PtrL;
	}
}
