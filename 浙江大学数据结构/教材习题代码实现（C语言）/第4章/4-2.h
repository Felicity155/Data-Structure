
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
struct Node {
	ElementType Element;  /*结点的值域*/
	PtrToNode Next;       /*下一个结点的指针域*/
};
