
struct People { /* 顾客类型 */
	int T;		/* 顾客到达时间 */
	int P;		/* 顾客事务被处理的时间 */
};

struct QueueRecord { /* 队列结点 */
	int front;	/* 头指针 */
	int rear;   /* 尾指针 */
	int size;   /* 当前队列中的元素个数 */
	struct People *Customer; /* 顾客数组 */
};

typedef struct QueueRecord *Queue;

Queue CreateQueue( int MaxElements );
void AddQ( Queue Q, struct People X );
struct People DeleteQ( Queue Q );
int IsEmpty( Queue Q );
