
int  Length ( List  *PtrL )
{
	List  *p = PtrL;  /* p指向表的第一个结点*/
	int  j = 0;

	while ( p ) { 
		p = p->Next; 
		j++;         /* 当前p指向的是第 j 个结点*/
	}   

	return  j;
}
