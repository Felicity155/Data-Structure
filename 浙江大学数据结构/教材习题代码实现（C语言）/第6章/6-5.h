
void  DFS( Graph G,  int V )
{   /* 从第V个顶点出发递归地深度优先遍历图G */
	Visited[V] = TRUE;
	VisitFunc(V);  /* 访问第V个顶点 */
	for( W = FirstAdjV(G, V);  W;  W = NextAdjV (G, V, W) )
		if ( !Visited[W] )
			DFS(G, W);   /* 对V的尚未访问的邻接顶点W递归调用DFS */
}
