
void  Dijkstra ( MGraph G，int v0,  int *P,  int *D )
{   /*求有向网G的v0顶点到其余顶点的最短路径P[]及其路径长度D[]*/
    /*若P[v]==w，则w是从v0到 v当前求得最短路径上的顶点*/
    /*Final[v] 为TRUE当且仅当v∈S，即已经求得从v0到v的最短路径*/
    /*常量INFINITY为边上权值可能的最大值*/

	int  Final[MaxVertexNum], v, w, i, j, min;

	for ( v = 0; v < G.n; ++v ) { /* 初始化 */
		Final[v] = FALSE;  D[v] = G.Edges[v0][v];
		for ( w = 0; w < G.n; ++w ) 
			if ( D[w] < INFINITY )  P[w] = v0;  /* 设父顶点v0  */
	}
	D[v0] = 0;  Final[v0] = TRUE;  /* 初始状态：v0顶点属于S集 */

	/*开始主循环，每次求得v0到某个v 顶点的最短路径，并加v到集 */
	for( i = 1; i < G.n; ++i ) {
		min = INFINITY;   /* min为当前所知离v0顶点的最近距离 */
		for ( w = 0; w < G.n; ++w)
			if ( !Final[w] )  /* w顶点在V－S中 */
				if (D[w] < min) {
					v = w;  min = D[w];
				} /* 寻找最短路径顶点v */
			if( min < INFINITY )
				Final[v] = TRUE; /* 离v0顶点最近的v加入S集合 */
			else  break; /* 否则是非连通图，结束。  */
		for( w = 0; w < G.n; ++w ) /* 更新当前最短路径*/
			if ( !Final[w] && (min+G.Edges[v][w] < D[w]) ) {
				D[w] = min+G.Edges[v][w]; 
				P[w] = v; 
			}
	} /* 结束主循环 */
}
