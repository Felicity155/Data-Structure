
void InsertAndCount( ElementType Key, HashTable H )
{
            Position Pos, NewCell;
            List L;

/* 1*/      Pos = Find( Key, H );
/* 2*/      if( Pos ) /* 关键词找到 */
			     Pos->Times++;
			else { /* 关键词未找到 */
/* 3*/          NewCell = malloc( sizeof( struct ListNode ) );
/* 4*/          if( NewCell == NULL )
/* 5*/              FatalError( "空间溢出!!!" );
                 else{
/* 6*/              L = &(H->TheLists[ Hash( Key, H->TableSize ) ]);
/* 7*/              NewCell->Next = L->Next;      /* 插入第一个结点  */
/* 8*/              L->Next = NewCell; 
/* 9*/              strcpy(NewCell->Element, Key);  
/* 10*/				NewCell->Times = 1; 
/* 11*/             L->Times++; /* 头结点的Times表示该链表的长度，增1 */ 
                }
            }
}
