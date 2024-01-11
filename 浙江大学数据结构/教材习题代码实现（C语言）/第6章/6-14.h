
void ToplogicalSort ( Graph G, int TopNum[ ] )
{
     Queue queue;
     int Counter = 0;
     int v, w;

     int *InDegree = (int *)malloc( G.n * sizeof(int) );
     GetInDegree(G, InDegree);   /* 计算图G中各顶点的入度 */

     /* 创建空队列 */
     queue = CreateQueue( G.n );
     for( v = 1; v <= G.n; v++ )
          if( InDegree[v]==0 )
              AddQ( queue, v );
      while( ! IsEmptyQ(queue) ) {
           v = DeleteQ( queue );
           TopNum[v] = ++Counter;      /* 赋顶点拓扑排序序号 */
           for( G中关于v 的每个邻接点w )
              if( --InDegree[ w ] == 0 )
                  AddQ( queue, w );

      }
      if( Counter != G.n )
           Error( "图存在环路" );
      DisposeQueue(queue);    /* 释放队列空间*/
	  free(InDgree);
}
