
HashTable  InitializeTable( int TableSize )
{
            HashTable H;
            int i;

/* 1*/      if( TableSize < MinTableSize ){
/* 2*/          Error( "散列表太小" );
/* 3*/          return NULL;
            }

            /* 分配散列表 */
/* 4*/      H = malloc( sizeof( struct HashTbl ) );
/* 5*/      if( H == NULL )
/* 6*/          FatalError( "空间溢出!!!" );

/* 7*/      H->TableSize = NextPrime( TableSize );

/* 8*/      H->TheCells = malloc( sizeof( Cell ) * H->TableSize );
/* 9*/      if( H->TheCells == NULL )
/*10*/          FatalError( "空间溢出!!!" );

/*11*/      for( i = 0; i < H->TableSize; i++ )
/*12*/          H->TheCells[ i ].Info = Empty;

/*13*/      return H;
}
