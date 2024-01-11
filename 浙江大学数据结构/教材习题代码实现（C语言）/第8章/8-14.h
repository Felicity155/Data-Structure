
void MinHeap( int i, int M )
{   /* 将M个元素的数组中以ESet[i]为根的子堆调整为最小堆 */
	int child;
	struct EdgeType temp;

	temp = ESet[i];
	for(; (2*i + 1) < M; i = child){
		child = 2*i+1;
		if(child != M-1 && ESet[child + 1].W < ESet[child].W)
			child++;
		if(temp.W > ESet[child].W) 
			ESet[i] = ESet[child];
		else
			break;
	}
	ESet[i] = temp;  
}

int GetEdge( int CurrentSize )
{   /* 给定当前堆的大小CurrentSize，将当前最小边位置弹出并调整堆 */
	struct EdgeType temp;

    /* 将最小边与当前堆的最后一个位置的边交换 */
	temp = ESet[0];
	ESet[0] = ESet[CurrentSize-1];
	ESet[CurrentSize-1] = temp;  
    /* 将剩下的边继续调整成最小堆 */
	MinHeap(0, CurrentSize-1);

	return CurrentSize-1; /* 返回最小边所在位置 */
}
