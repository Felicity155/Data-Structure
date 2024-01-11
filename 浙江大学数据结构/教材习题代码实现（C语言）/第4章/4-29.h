
void Union( SetType S[ ], ElementType X1, ElementType X2 )
{
    int Root1, Root2;

	Root1 = Find(S, X1);
	Root2 = Find(S, X2);
	if( Root1 != Root2 )
		S[Root2].Parent = Root1;
}
