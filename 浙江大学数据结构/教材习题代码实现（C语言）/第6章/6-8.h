
/* #include "6-1.h"  并把顶点类型改为整数型 */

void Prim（ MGraph *G， int  Parent[ ] ）
{   /* 默认从序号为0的顶点出发 */
	/* 表示每个顶点的父节点的最小生成树存于数组Parent中 */
	int LowCost[ MaxVertexNum ];
	int i, j, k;

	for ( i = 1; i < G->n; i++ ){ /* 初始化 */
		LowCost[i] = G->Edges[0][i];
		Parent[i]  = 0;  /*暂且认为所有顶点的父节点是 0（根结点）*/
	}
	LowCost[0] = 0; /* 从序号为0的顶点出发生成最小生成树 */
	Parent[0] = -1;  /* 生成树的根节点 */
	for ( i=1; i<G->n; i++ ){ /* 生长成最小生成树还需要收集n-1个结点 */
		k = FindMin(LowCost, G->n); /* 求V－VT中到VT最小距离的点k*/
		if( k ){ /* 如果找到 */
			LowCost[k] = 0;  /*  生长至顶点k  */
			for ( j = 1 ; j < G->n; j++ ) /* 更新当前最小生成树*/
				if (LowCost[j] && G->Edges[k][j] < LowCost[j] ) {
					/* 如果j是V－VT中的顶点且距离需要更新 */
					LowCost[j] = G->Edges[k][j];    /* 更新最小距离  */
					Parent[j] = k;  /*  暂且认为顶点j的父结点是 k  */
				}/* 结束if需要更新j */
		} /* 结束if找到下一个k */
		else { /* 还没收集完所有结点就不能继续生长，一定为非连通图 */
			printf("图不连通");
			break;
		}
	}/* 结束收集结点的for循环 */
}
