
int Kruskal( int N, int M )
{   /* 给定结点和边的数目，返回最小生成树总权重 */
	int EdgeN = 0;     /* 生成树边集合计数器 */
	int Cost = 0;      /* 最小生成树权重累计 */
	int NextEdge = M; /* 下一个最小权重边的位置，初始化为总边数 */

	InitializeVSet( N );  /* 初始化结点并查集VSet */
	InitializeESet( M );  /* 根据边的权重建立最小堆ESet */
	while (EdgeN < N-1) { /* 当收集的边不足以构成树时 */
		NextEdge = GetEdge(NextEdge); /* 从边集中得到最小边的位置 */
		if (NextEdge < 0)  break; /* 边集已空 */
		if ( CheckCycle( ESet[NextEdge].V1, ESet[NextEdge].V2 ) ) {
        /* 如果该边的加入不构成回路，即两端结点不属于同一连通集 */
			Cost += ESet[NextEdge].W; /* 收入该边，累计权重 */
			EdgeN++; /* 生成树中边数加1 */
		}
	}
	if (EdgeN < N-1) Cost = -1; /* 若收集的边不足以构成树，设置信号 */
	return Cost;
}
