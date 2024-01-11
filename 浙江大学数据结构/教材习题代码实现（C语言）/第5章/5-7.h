
HashTable  InitializeTable( int TableSize )
{
            HashTable H;
            int i;

/* 1*/      if( TableSize < MinTableSize ) {
/* 2*/          Error( "散列表太小" );
/* 3*/          return NULL;
            }

            /* 以下分配散列表 */
/* 4*/      H = malloc( sizeof( struct HashTbl ) );
/* 5*/      if( H == NULL )
/* 6*/          FatalError( "空间溢出!!!" );
/* 7*/      H->TableSize = NextPrime( TableSize );
            /* NextPrime确定一个 >= TableSize的素数，具体代码见5.6节 */

            /* 以下分配表头数组 */
/* 8*/      H->TheLists = malloc(sizeof(struct ListNode )*H->TableSize );
/* 9*/      if( H->TheLists == NULL )
/*10*/          FatalError( "空间溢出!!!" );

            /* 以下设置表头结点 */
/*11*/      for( i = 0; i < H->TableSize; i++ ) {
/*12*/          H->TheLists[ i ].Element[0] = '\0';
/*13*/			H->TheLists[ i ].Times = 0; /* 单链表中结点数量 */
/*14*/          H->TheLists[ i ].Next = NULL;
            }

/*15*/      return H;
}
