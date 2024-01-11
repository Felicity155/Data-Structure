
void  DFS_ALG( ALGraph  *G )
{   
	int i;
         
	for ( i = 0; i < G->n; i++ )
		Visited[ i ] = FALSE;  /* 标志向量初始化 */
	for ( i = 0; i < G->n; i++ )
		if ( !Visited[i] ) /* 若vi未被访问过 */
			DFS( G, i ); /* 从Vi开始DFS搜索一个连通分量 */
}

void  DFS( ALGraph *G,  int i )
{   /* 以Vi为出发点对邻接表存储的图G进行DFS搜索 */
	EdgeNode *W;

	printf( "visit vertex:V%c\n", G->adjlist[i].Vertex );
	/* 相当于VisitFunc(Vi)，即访问顶点Vi */
	Visited[i] = TRUE;   /* 标记Vi已访问 */
	for(W = G->adjlist[i].FirstEdge;  W;  W = W->Next ) 
		if ( !Visited[ W->AdjV ] )
			DFS( G, W->AdjV );
}
