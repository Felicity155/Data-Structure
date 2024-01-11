
void  Insert( ElementType Key, HashTable H )
{
			Position Pos;

/* 1*/		Pos = Find( Key, H );
/* 2*/		if( H->TheCells[ Pos ].Info != Legitimate ) {
                /* 确认在此插入 */
/* 3*/         H->TheCells[ Pos ].Info = Legitimate;
/* 4*/         H->TheCells[ Pos ].Element = Key;
               /*字符串类型的关键词需要 strcpy 函数!! */
            }
}
