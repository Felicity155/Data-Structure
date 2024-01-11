
#define  MaxVertexNum  100   /* 最大顶点数设为100 */
#define  INFINITY  65535     /* ∞设为双字节无符号整数的最大值65535*/
typedef  char  VertexType;   /* 顶点类型设为字符型 */
typedef  int  EdgeType;      /* 边的权值设为整型 */
enum GraphType { DG, UG, DN, UN };  
/* 有向图,无向图,有向网图,无向网图*/

typedef  struct {
	VertexType  Vertices[ MaxVertexNum ];  /* 顶点表 */
	EdgeType  Edges[ MaxVertexNum ][ MaxVertexNum ]; /* 邻接矩阵，即边表  */
	int  n, e;   /* 顶点数n和边数e */
	enum GraphType GType;   /* 图的类型分4种：UG、DG、UN、DN */
} MGraph;    /* MGragh是以邻接矩阵存储的图类型 */
