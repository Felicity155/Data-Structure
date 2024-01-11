
void  SixDegree_BFS( MGraph  G , VertexType  Start )
{   /* 计算距离不超过SIX的结点百分比， 存于G->adjlist[Start].percent  */
    struct QElementType {
		VertexType v;
		int layer
	} qe; 
    VertexType  v;
	EdgeNode *edge;
	LinkQueue Q; 
	long int VisitCount = 1;   /* 记录路径长度<=SIX的顶点数 */
     
	Initialize( &Q ); /* 置空的队列Q */
	G->adjlist[Start].Visited = 1;
	qe.v = Start; qe.layer = 0; /* 起点算0层 */
	AddQ( &Q, qe ); /* qe入队列 */
	while ( !IsEmptyQ(&Q) ) { /* 队列非空循环 */
		qe = DeleteQ(&Q);
		v = qe.v;
		for( edge=G->adjlist[v].FirstEdge; edge; edge=edge->Next )
			if ( !G->adjlist[edge->AdjV].Visited ) {/* 若是v的尚未访问的邻接顶点 */
				G->adjlist[edge->AdjV].Visited = 1;  /* 将其记为六度以内的顶点 */
				VisitCount++ ;        /* 增加路径长度<=SIX的顶点数 */
				if( ++qe.layer < SIX ) {/* 仅将六度以内的顶点再进队 */
					qe.v = edge->AdjV;
					AddQ(&Q, qe);
				}
				qe.layer--;   /* 恢复qe的层数 */
			} /* 结束if，for */
     } /* 结束while循环 */
     DestroyQueue( Q );
     G->adjlist[Start].percent = (float) 100.0 * VisitCount / G->n;
}
