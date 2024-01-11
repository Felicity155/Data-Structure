
struct People { 
	int T; 
	int P; 
    int VIP; /* VIP标志：1=VIP；0=普通；-1=删除 */
};

struct QueueRecord {
	int front; 
	int rear;
	int size;
	struct People *Customer;
    /*--下面是VIP子列的相应元素--*/
	int VIPfront;
	int VIPrear;
	int VIPsize;
	int *VIPCustomer;
	/*------------------------*/
};
typedef struct QueueRecord *Queue;

Queue CreateQueue( int MaxElements );
void AddQ( Queue Q, struct People X );
struct People DeleteQ( Queue Q );
int IsEmpty( Queue Q );
void AddVIP( Queue Q, int Position );   /* 对VIP客户的入列操作 */
struct People DeleteVIP( Queue Q );     /* 对VIP客户的出列操作 */
