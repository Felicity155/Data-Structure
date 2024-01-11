
void  DestroyTable( HashTable H )
{
	int i;
	Position P, Tmp;

	for( i = 0; i < H->TableSize; i++ ) {
		P = H->TheLists[ i ].Next;
		while( P != NULL ) {
			Tmp = P->Next;
			free( P );
			P = Tmp;
		}
	}

	free( H->TheLists );
	free( H );
}
