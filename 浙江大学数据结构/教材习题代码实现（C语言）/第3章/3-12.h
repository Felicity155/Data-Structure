
void Push( struct DStack *PtrS, ElementType item, int Tag )
{   /* Tag作为区分两个堆栈的标志，取值为1和2 */
	if ( PtrS->Top2 - PtrS->Top1 == 1) {  /*堆栈满*/
		printf("堆栈满");
		return ;
	}
	if ( Tag == 1 ) /* 对第一个堆栈操作 */
		PtrS->Data[++(PtrS->Top1)] = item;
	else              /* 对第二个堆栈操作 */
		PtrS->Data[--(PtrS->Top2)] = item;
}

ElementType Pop( struct DStack *PtrS, int Tag )
{   /* Tag作为区分两个堆栈的标志，取值为1和2  */
	if ( Tag == 1 ) {  /* 对第一个堆栈操作  */
		if ( PtrS->Top1 == -1 ) { /*堆栈1空 */
			printf("堆栈1空");
			return NULL;
		}
		else return PtrS->Data[(PtrS->Top1)--];
	}
	else {          /* 对第二个堆栈操作 */
		if ( PtrS->Top2 == MaxSize ) { /*堆栈2空 */
			printf("堆栈2空");
			return NULL;
		}
		else  return PtrS->Data[(PtrS->Top2)++];
	}
}
