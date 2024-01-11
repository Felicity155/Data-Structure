
void  CreateMGraph ( MGraph *G )
{  
		int  i, j, k, w;

		G-> GType = UN;    /* Undirected Network  无向网图  */
		printf( "请输入顶点数和边数(输入格式为:顶点数, 边数):\n" );
		scanf( "%d, %d",&(G->n), &(G->e) ); /* 输入顶点数和边数 */
		printf("请输入顶点信息(输入格式为:顶点号<CR>):\n");
		for ( i = 0; i < G->n; i++ ) 
			scanf( "%c",&(G-> Vertices[i]) );
			/*  输入顶点信息，建立顶点表  */

/*1*/	for ( i = 0; i < G->n; i++ )
/*2*/      for ( j = 0; j < G->n; j++ )  
/*3*/          G->Edges[i][j] = INFINITY; /* 初始化邻接矩阵 */
        printf( "请输入每条边对应的两个顶点的序号和权值，输入格式为:i, j, w:\n" );
/*4*/	for ( k = 0; k < G->e; k++ ) {
			scanf("%d,%d,%d ",&i, &j, &w);
			/* 输入e条边上的权，建立邻接矩阵 */
/*5*/		G->Edges[i][j] = w; 
/*6*/		G->Edges[j][i] = w; /* 因为无向网图的邻接矩阵是对称的 */
        }
}
