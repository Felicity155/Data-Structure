
struct Node *Reverse( struct Node *L )
{
	struct Node *p, *q, *t;
	
	p=L£¬q=NULL;
	while (p!=NULL) {
		t=p->Next;
		p->Next=q;
		q=p;
		p=t;
	}
	
	return q;
}
