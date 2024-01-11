
Position  Find( ElementType Key, HashTable H )
{
            Position CurrentPos, NewPos;
            int CNum;        /*   记录冲突次数   */

/* 1*/      CNum = 0;
/* 2*/      NewPos = CurrentPos = Hash( Key, H->TableSize );
/* 3*/      while( H->TheCells[ NewPos ].Info != Empty && H->TheCells[ NewPos ].Element != Key ) {
                                                         /* 字符串类型的关键词需要 strcmp 函数!! */
/* 4*/			if(++CNum % 2){ /*  判断冲突的奇偶次  */
/* 5*/				NewPos = CurrentPos + (CNum+1)/2*(CNum+1)/2;
/* 6*/				while( NewPos >= H->TableSize )
/* 7*/					NewPos -= H->TableSize;
				}
				else {
/* 8*/				NewPos = CurrentPos - CNum/2 * CNum/2;
/* 9*/				while( NewPos < 0 )
/* 10*/					NewPos += H->TableSize;
				}
			}
/* 11*/		return NewPos;
}
