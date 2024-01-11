
void Push( Stack *PtrS, ElementType item )
{
    if ( PtrS->Top == MaxSize-1 ) {
		printf("¶ÑÕ»Âú");
		return;
	}
	else {
		PtrS->Data[++(PtrS->Top)] = item;
        return;
    }
}
