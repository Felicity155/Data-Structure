
struct People DeleteVIP( Queue Q )
{   /* 令VIP子列队首的客户出列 */
	struct People X;
	int Position;

	if ( Q->VIPsize ) { /* 如果存在VIP客户 */
		/* 获得队首客户在顾客队列中的位置 */
		Position = Q->VIPCustomer[Q->VIPfront]; 
		/* 将该位置从VIP子列中删除 */
		Q->VIPfront++;
		Q->VIPsize--;
		Q->Customer[Position].VIP = -1; /* 懒惰删除顾客队列中的VIP */
		X.T = Q->Customer[Position].T;
		X.P = Q->Customer[Position].P;
	}
	else  /* 如果没有VIP客户，则做普通出列 */
		X = DeleteQ(Q);
	
	return X;
}
