#include<iostream>
using namespace std;
#define maxsize 200
typedef struct {
	int id;
	int prior;
}ELEM;
typedef struct {
	ELEM elem[maxsize];
	int n;
}HEAP;

void creatheap(HEAP& heap, int id, int prior);
void outputheap(HEAP& heap);

int main()
{
	FILE* fp;
	fopen_s(&fp, "task.dat", "r");
	if (fp == NULL) {
		cout << "打不开文件";
		exit(0);
	}
	int id, prior;
	HEAP heap;
	heap.n = 0;
	while (!feof(fp))
	{
		fscanf_s(fp, "%d %d", &id, &prior);
		creatheap(heap, id, prior);
	}
	fscanf_s(fp, "%d %d", &id, &prior);
	creatheap(heap, id, prior);
	while (heap.n != 1)
	{
		outputheap(heap);
	}
}

void creatheap(HEAP& heap, int id, int prior)
{
	int i;
	if (heap.n != maxsize - 1)
	{
		i = heap.n + 1;
		while ((i != 1) && (prior > heap.elem[i / 2].prior))
		{
			heap.elem[i].prior = heap.elem[i / 2].prior;
			heap.elem[i].id = heap.elem[i / 2].id;
			i = i / 2;
		}
		heap.elem[i].prior = prior;
		heap.elem[i].id = id;
		heap.n++;
	}
}
void outputheap(HEAP& heap)
{
	int parent = 1, child = 2;
	ELEM tmp, ele;
	ele = heap.elem[1];
	cout << ele.id << " " << ele.prior << endl;
	tmp = heap.elem[heap.n];
	heap.n--;
	while (child <= heap.n + 1) {
		if (child < heap.n && (heap.elem[child].prior < heap.elem[child + 1].prior))
			child++;
		if (child == heap.n && heap.elem[child].prior == heap.elem[child + 1].prior && heap.elem[child].id > heap.elem[child + 1].id)
			child++;
		if (tmp.prior >= (heap.elem[child]).prior) break;
		heap.elem[parent] = heap.elem[child];
		parent = child;
		child *= 2;
	}
	heap.elem[parent] = tmp;
}