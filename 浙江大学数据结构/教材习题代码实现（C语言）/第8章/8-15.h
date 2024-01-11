
int CheckCycle( Vertex V1, Vertex V2 )
{   /* 检查连接V1和V2的边是否在现有的最小生成树子集中构成回路 */
	Vertex Root1 = Find(V1); /* 得到V1所属的连通集名称 */
	Vertex Root2 = Find(V2); /* 得到V2所属的连通集名称 */

	if(Root1==Root2) /* 若V1和V2已经连通，则该边不能要，返回0 */
		return 0;
	else {  /* 否则该边可以被收集，同时将V1和V2并入同一连通集 */
		SetUnion(Root1, Root2);
		return 1;
	}
}
