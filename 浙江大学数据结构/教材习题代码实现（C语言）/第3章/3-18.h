
void Path( )
{ 
	int i, Row, Col, NextRow, NextCol, Dir, Found = FALSE;
	int Mark[MAXMATRIXSIZE][MAXMATRIXSIZE]; /* 标记位置是否走过 */
	ElementType Position;
	Stack S;
	S.Top = -1;  /* 堆栈初始化为空 */

	Mark[1][1] = 1;      /* 从入口位置开始，标记为走过 */
	/* 将入口位置及下一个方向放入堆栈 */
	S.Top++;
	S.Data[S.Top].Row = 1;
	S.Data[S.Top].Col = 1;
	S.Data[S.Top].Dir = 2; 
	/* 注意：不可能从入口向北走，所以方向序号从2开始，即从向东开始 */
    
	while ( S.Top > -1 && !Found ) { /* 当栈非空且没找到出口时 */
		Position = Pop(&S); /* 取出栈顶元素为当前位置 */
		Row = Position.Row; Col = Position.Col; Dir = Position.Dir;
		while ( Dir < 8 && !Found ) {/* 当还有方向可探且没找到出口时 */
			/*尝试往下一个方向Dir移动 */
			NextRow = Row + Move[Dir].Vert;
			NextCol = Col + Move[Dir].Horiz;
			if ( NextRow == EXITROW && NextCol == EXITCOL )  
				/* 如果到出口 */
				Found = TRUE;
			else  /* 下一个位置不是出口 */
				if ( !Maze[NextRow][NextCol] && !Mark[NextRow][NextCol] ){
					/* 若下一个位置可通，且没走过 */
					Mark[NextRow][NextCol] = 1; /* 标记为走过 */
					Position.Row = Row;
					Position.Col = Col;
					Position.Dir = Dir + 1;
					Push(&S, Position);  /* 当前位置和下一个方向存入栈 */
					/* 更新当前位置，从方向0开始 */
					Row = NextRow; Col = NextCol; Dir = 0;
				} /* 结束if */
				else ++Dir; /* 若此路不通，则在当前位置尝试下一个方向 */
		} /* 结束8方向探测 */
	} /* 结束搜索 */
	if ( Found ) {    /* 找到一个路径，并输出该路径 */
		printf ("The path is:\n");
		printf ("row  col\n");
		for ( i = 0; i <= S.Top; i++ )
			printf ("%d %d\n", S.Data[i].Row, S.Data[i].Col);
		printf ("%d %d\n", Row, Col); /* 不要忘记最后一步未入堆栈 */
		printf ("%d %d\n", EXITROW, EXITCOL); /* 打印出口 */
	}
	else /* 若没找到路径 */
		printf ("The maze does not have a path\n");
}
