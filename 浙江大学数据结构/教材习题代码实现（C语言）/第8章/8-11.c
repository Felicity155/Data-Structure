#include <stdio.h>

#define MaxSize 100

typedef int Vertex;
typedef Vertex ElementType;

typedef struct {
    ElementType Data;
    int Parent;
} SetType;

void Initialization( SetType S[], int N )
{
	int i;

	for (i=0; i<N; i++) {
		S[i].Data = i;
		S[i].Parent = -1;
	}
}

#include "4-28.h"
#include "4-29.h"

void InputConnection( SetType S[], int M )
{   /* 读入M条边，并将有边相连的结点并入同一集合 */
	Vertex U, V;    /* 记录输入的结点 */
	Vertex V1, V2;  /* 记录输入结点所在的集合的根结点 */
	int i;

	for (i=0; i<M; i++) {
		scanf("%d %d", &U, &V);
		V1 = Find( S, U );
		V2 = Find( S, V );
		if ( V1 != V2 )
			Union( S, V1, V2 );
	}
}

int CountConnectedComponents( SetType S[], int N )
{   /*计算集合S中连通集的个数 */
	int i, cnt = 0;

	for (i=1; i<=N; i++) {
		if ( S[i].Parent < 0 )
			cnt ++;
	}
	return cnt;
}

int main()
{
	SetType S[MaxSize];
	int N, M;

	scanf("%d %d", &N, &M);
	Initialization( S, N );
	InputConnection( S, M );
	printf("Number of roads = %d\n", CountConnectedComponents( S, N )-1 );

	return 0;
}
