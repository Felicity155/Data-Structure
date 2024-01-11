
List  *FindKth( int K, List *PtrL )
{
	List  *p = PtrL;
	int  i = 1;

	while (p !=NULL && i < K ) {
		p = p->Next;
		i++;  
	}
	if ( i == K ) return p; /* 找到第K个，返回指针 */
	else  return NULL;     /* 否则返回空 */
}
