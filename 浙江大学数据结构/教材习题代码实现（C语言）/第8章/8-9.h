
struct People DeleteQ( Queue Q )
{   /* 令Q队首的顾客出列 */
	struct People X;

    /* 将位于队列前端的被懒惰删除的顾客真正删除 */
	while ( Q->Customer[Q->front].VIP == -1 ) {
		Q->front++;
		Q->size--;
	}
	if ( IsEmpty(Q) ) { /* 如果清除后发现队列已空，返回空信号 */
		X.T = -1;
		return X;
	}
	if ( Q->Customer[Q->front].VIP == 1 )
		X = DeleteVIP(Q); /* 令队首的VIP客户出列 */
	else {  /* 普通顾客出列 */
		X.T = Q->Customer[Q->front].T;
		X.P = Q->Customer[Q->front].P;
	}
    /* 删除队首的顾客 */
	Q->front++;
	Q->size--;
	return X;
}
