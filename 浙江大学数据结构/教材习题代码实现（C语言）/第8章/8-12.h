
#define MaxVertices 1000
typedef int DisjSet[ MaxVertices + 1 ];
typedef int Vertex;

struct EdgeType {
	Vertex V1, V2;
	int W;
};
DisjSet VSet;
struct EdgeType *ESet;
