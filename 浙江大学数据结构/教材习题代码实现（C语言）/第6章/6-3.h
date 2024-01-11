
#define  MaxVertexNum  100     /* 最大顶点数为100 */
enum GraphType { DG, UG, DN, UN }; 
/* 有向图,无向图,有向网图,无向网图*/

typedef  struct  node{          /* 边表结点 */
  int AdjV;                   /* 邻接点域 */
  struct  node  *Next;       /* 指向下一个邻接点的指针域 */
  /* 若要表示边上的权值信息，则应增加一个数据域Weight */
} EdgeNode;        

typedef  char  VertexType;       /* 顶点用字符表示 */
typedef  struct  Vnode{           /* 顶点表结点 */
  VertexType  Vertex;         /* 顶点域 */
  EdgeNode  *FirstEdge;       /* 边表头指针 */
} VertexNode;   
    
typedef  VertexNode  AdjList[ MaxVertexNum ];
/* AdjList是邻接表类型 */

typedef  struct{  
	AdjList  adjlist;       /* 邻接表 */
	int  n, e;              /* 顶点数和边数 */
	enum GraphType GType;   /* 图的类型分4种：UG、DG、UN、DN */
} ALGraph;  /*ALGraph是以邻接表方式存储的图类型 */
