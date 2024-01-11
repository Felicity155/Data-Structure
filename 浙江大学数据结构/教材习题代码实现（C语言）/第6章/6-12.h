
void Floyd ( MGraph G,  PathMatrix *P[],  DistanceMatrix *D )
{   /*求有向网G中各对顶点v和w之间的最短路径P[v][w]及其带权长度D[v][w] */
    /*若P[v][w]=u，代表u是从v到w的最短路径必经的顶点。*/
	int u, v, w, i;

	for( v = 0; v < G.n; ++v ) /* 各对顶点之间初始已知路径及距离 */
		for( w = 0; w < G.n; ++w ) {
			D[v][w] = G.Edges [v][w];
	        P[v][w] = v;  /* 假设从v到w有直接路径*/
		}/*如果不存在直接的边，D[v][w] = ∞，P[v][w] = v也不会混淆*/
		for( u = 0; u < G.n; ++u )
			for( v = 0; v < G.n; ++v )
				for( w = 0; w < G.n; ++w )
					if ( D[v][u] + D[u][w] < D[v][w] ) {
						/*从v经u到w的一条路径更短*/
						D[v][w] = D[v][u] + D[u][w];
						P[v][w] = u;
					}
}
