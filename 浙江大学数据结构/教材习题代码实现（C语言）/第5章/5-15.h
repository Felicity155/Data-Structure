
void Show( HashTable H, double percent )
{
	        int diffwordcount = 0;    /* 不同的单词数量 */
            int maxf = 0;               /* 最大的词频 */
			int *diffwords;            /* 每个词频有的不同单词数量 */
			int maxCollision = 0;     /* 最大冲突次数，初始化为0 */
			int minCollision = 100;   /* 最小冲突次数，初始化为100 */
			Position L;
			int i, j, k, count = 0;

/* 1 */     for( i = 0; i < H->TableSize; i++ ) {
			    /* 先求不同的单词数量 */
/* 2 */			diffwordcount += H->TheLists[ i ].Times;
				if( maxCollision < H->TheLists[ i ].Times )
					maxCollision = H->TheLists[ i ].Times;
				if( minCollision > H->TheLists[ i ].Times )
					minCollision = H->TheLists[ i ].Times;
				/* 再求最大的词频 */
/* 3 */			L = H->TheLists[ i ].Next; 
/* 4 */			while( L ){
/* 5 */				if( maxf < L->Times) maxf = L->Times;
/* 6 */				L = L->Next;
				}
			}
 
/* 7 */    printf(" 共有 %d 个不同的单词，词频最大是 %d：\n", diffwordcount, maxf);
/* 8 */    printf(" 最大冲突次数是 %d, 最小冲突次数是 %d.\n", maxCollision, minCollision);
			
            /* 再求每个词频等级拥有的不同单词数量 */
            /* 根据最大的词频，分配一个整数数组 */
/* 9 */		diffwords = malloc( sizeof( int ) * ( maxf+1 ) );
/* 10 */	if(diffwords == NULL )
/* 11 */       FatalError( "空间溢出!!!" );

            /* 统计词频分别从1到maxf的单词数量 */
			for( i = 0; i <= maxf; i++ ) 
			    diffwords[ i ] = 0;   
/* 12 */	for( i = 0; i < H->TableSize; i++ ) {
/* 13 */		L = H->TheLists[ i ].Next; 
/* 14 */		while( L ){
/* 15 */			diffwords[ L->Times ]++; /* 该词频增加一个单词 */
/* 16 */			L = L->Next;
				}
			}

            /* 求特定的词频，使得大于等于该词频的单词总和超过给定的比例 */
/* 17 */   count = diffwords[ maxf ];
/* 18 */   i = maxf;
/* 19 */   while( i > 1 && count <  diffwordcount * percent)
/* 20 */		count += diffwords[ --i ]; /* 增加下一个词频的单词数量 */
            
/* 21 */   for( j = maxf; j >= i; j-- ) /* 按词频从大到小输出单词 */
/* 22 */   for( k = 0; k < H->TableSize; k++ ) {
/* 23 */		L = H->TheLists[ k ].Next; 
/* 24 */		while( L ){
/* 25 */			if( j == L->Times) /* 输出该单词及词频 */
/* 26 */				printf(" %-15s : %d \n", L->Element ,L->Times);
/* 27 */			L = L->Next;
				}
			}
            
/* 28 */    free( diffwords );
}

