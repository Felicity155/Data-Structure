
void PreOrderTraversal( BinTree BT )
{
    if( BT ) {
        printf("%d", BT->Data );
        PreOrderTraversal( BT->Left );
        PreOrderTraversal( BT->Right );
    }
}
