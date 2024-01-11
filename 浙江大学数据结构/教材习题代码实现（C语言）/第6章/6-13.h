
void ToplogicalSort ( Graph G, int TopNum[ ] )
{
    int Counter;    /* 拓扑序号 */
    int v, w;

    int *InDegree = (int *)malloc( G.n * sizeof(int) );
    GetInDegree(G, InDegree);   /* 计算图G中各顶点的入度 */
    for( Counter = 0; Counter < G.n; Counter++ ) {
        v = FindNewVertexOfDegreeZero( );   
        /* 查找入度为0的顶点。若找不到入度为0的顶点，返回NotAVertex */
        if ( v == NotAVertex ) {
             Error( "图存在环路");
             break;
        }
        TopNum[v] = Counter;
        for( G中关于v 的每个邻接点w )
           Indegree[w]--;  /* 与顶点v相连的各顶点的入度减1 */
    }
}
