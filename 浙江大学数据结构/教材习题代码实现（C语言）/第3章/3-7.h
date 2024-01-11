
List *Find( ElementType X, List *PtrL )
{
	List  *p = PtrL;

	while ( p!=NULL && p->Data != X )
		p = p->Next;  

	return p;
}
