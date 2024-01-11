
void CreateALGraph( ALGraph *G )
{
	int i,j,k;
	EdgeNode *edge;

	G-> GType = DG;  /* Directed Graph  有向图  */
	printf( "请输入顶点数和边数(输入格式为:顶点数,边数)：\n" );
	scanf( "%d,%d", &(G->n), &(G->e) );      /* 读入顶点数和边数 */ 
	printf( "请输入顶点信息(输入格式为:顶点号<CR>)：\n" );
	for ( i=0; i < G->n; i++ ) {   /* 建立有n个顶点的顶点表 */
		scanf( " %c", &(G->adjlist[i].vertex) );  /* 读入顶点信息 */
		G->adjlist[i].firstedge = NULL; /* 顶点的边表头指针设为空 */
	}
	printf( "请输入边的信息(输入格式为: i, j <CR>)：\n" );
	for ( k=0; k < G->e; k++ ){   /* 建立边表 */
		scanf( "\n%d,%d", &i, &j); /* 读入边<vi,vj>的顶点对应序号*/
		edge = (EdgeNode*) malloc( sizeof( EdgeNode ) );
		/* 生成新边表结点edge */
		edge->AdjV = j; /* 邻接点序号为j */
		edge->Next = G->adjlist[i].FirstEdge;
		/* 将新边表结点edge插入到顶点vi的边表头部 */
		G->adjlist[i].FirstEdge = edge;
		/* 若是无向图，还要生成一个结点，用来表示边< vj, vi>  */
	}
}
