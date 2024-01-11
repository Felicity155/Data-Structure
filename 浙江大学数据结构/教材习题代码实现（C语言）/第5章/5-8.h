
Position  Find( ElementType Key, HashTable H )
{
            Position P;
            List L;

/* 1*/      L = &( H->TheLists[ Hash( Key, H->TableSize ) ] );
/* 2*/      P = L->Next;
/* 3*/      while( P != NULL && strcmp(P->Element, Key) )
/* 4*/          P = P->Next;

/* 5*/      return P;
}
