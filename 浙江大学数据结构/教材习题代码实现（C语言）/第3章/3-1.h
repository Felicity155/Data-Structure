
List *MakeEmpty()
{
	List *PtrL;
	PtrL = (List *)malloc(sizeof(List));
	PtrL->Last= -1; 
	return PtrL;
}
