
int CountConnectedComponents( Graph G )
{
	/* 计算图G中连通集的个数 */
	Vertex V;

	InitializeVisited( G->NumOfVertices );
	cnt = 0;
	for ( V=0; V<G->NumOfVertices; V++ ) {
		if ( !Visited[V] ) {
			Dfs( V, G );
			cnt ++;
		}
	}
	return cnt;
}
