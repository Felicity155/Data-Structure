////测试用例1：(a,b,c,d,(a,b,c,d))     输出：(a,b,c,d,(a,b,c,d))
////测试用例2：(a,b,c,d,e)             输出：(a,b,c,d,e)
////测试用例3：((a,b,c,d))             输出：((a,b,c,d))
////测试用例4：((s,b,c,d),a,b,c)       输出：((s,b,c,d),a,b,c)
////测试用例5：(s,c,d,(d,f,g),(d))     输出：(s,c,d,(d,f,g),(d))
////测试用例6：((a,b),c,d,f,(g,h,s,f,(a,v)),e,t)   输出：((a,b),c,d,f,(g,h,s,f,(a,v)),e,t)
//#include <iostream>
//#include<stdio.h>
//#include<stdlib.h>
//using namespace std;
//enum elemTag { ATOM, LIST };
//struct  GLnode {
//	elemTag Tag; //标志是原子还是子表 0:原子 1:子表
//	union
//	{
//		char data; //原子结点值域
//		struct //表结点指针域
//		{
//			GLnode* hp;
//			GLnode* tp;
//		}ptr;
//	};
//	friend class GList;
//};
//void Create_GList(GLnode*& GL, string S);
//void Copy_GList(GLnode* GL, GLnode*& T);
//void Traverse_GList(GLnode* L);
//string Decompose(string& str);
//
//
//int main()
//{
//	GLnode* A = NULL;
//	string S;
//	//A为原广义表，B为复制后的广义表 
//	cout << "请输入广义表，示例：“(a,(b,c),d)”" << endl;
//	cin >> S;
//	
//	//创建并打印原广义表
//	Create_GList(A, S);
//	Traverse_GList(A);
//	cout << endl;
//
//	//复制并打印复制得到的广义表
//	GLnode* B;
//	Copy_GList(A, B);
//	Traverse_GList(B);
//
//	return 0;
//}
//
//
//
////创建广义表
//void Create_GList(GLnode*& GL, string S) 
//{
//	string hsub;
//	if (S == "()") //S为空串
//	{
//		GL = NULL;
//	}
//	else
//	{
//
//		GL = new GLnode;
//		if (S.length() == 1)
//		{
//			GL->Tag = ATOM;
//			GL->data = S[0];
//		}
//		else
//		{
//			GL->Tag = LIST;
//			hsub = Decompose(S); //从S中分离出表头串hsub
//			Create_GList(GL->ptr.hp, hsub);
//			if (S.empty())
//			{
//				GL->ptr.tp = NULL;
//			}
//			else
//			{
//				Create_GList(GL->ptr.tp, S);
//			}
//		}
//	}
//}
//
////复制广义表
//void Copy_GList(GLnode* GL, GLnode*& T) //T复制GL
//{
//	//当表为空时，复制空表，否则先复制表头在复制表尾
//	if (!GL)
//		T = NULL;
//	else
//	{
//		T = new GLnode;
//		T->Tag = GL->Tag;
//		if (GL->Tag == ATOM)
//			T->data = GL->data;
//		else
//		{
//			Copy_GList(GL->ptr.hp, T->ptr.hp);
//			Copy_GList(GL->ptr.tp, T->ptr.tp);
//		}
//	}
//}
////遍历输出
//void Traverse_GList(GLnode* L)
//{
//	if (!L)       //如果是空表就输出"()"
//		cout << "()";
//	
//	else          //如果遇到Tag=0的结点，则直接输出该结点的值，如果tag = 1，说明是一个子表，首先输出左括号，然后递归调用输出数据元素，并当表尾不空的时候输出逗号，最后输出右括号
//	{
//		if (L->Tag == ATOM)
//			cout << L->data;
//		else
//		{
//			GLnode* p = NULL;
//			cout << '(';
//			p = L;
//			while (p)
//			{
//				Traverse_GList(p->ptr.hp);
//				p = p->ptr.tp;
//				if (p)
//					cout << ',';
//			}
//			cout << ')';
//		}
//	}
//}
////分离子串用，在CSDN上看到这种方法，在此借鉴
//string Decompose(string& str)
//{
//	//将非空串str分割成2部分，hstr为第一个','之前的子串，str为后面的
//	int n, i, k;
//	string ch, hstr;
//	n = str.length();
//	for (i = 0, k = -1; i < n && (ch != "," || k != 0); i++)
//	{
//		//搜索最外层第一个逗号
//		ch = str.substr(i, 1); //从第i个位置起读1个字符
//		if (ch == "(")
//			++k;
//		else if (ch == ")")
//			--k;
//	}
//	if (i < n)
//	{
//		hstr = str.substr(1, i - 2);//不要左括号，不要逗号，所以是i-2
//		str = "(" + str.substr(i, n - i);
//	}
//	else
//	{
//		hstr = str.substr(1, n - 2);
//		str = "";
//	}
//	return hstr;
//}
//

#include <iostream>
using namespace std;
#define NumVertices 50

typedef struct node {// 边表 结点
    int ad; // 邻接点域（下标）
    struct node* next; // 下一边链接指针
} EdgeNode;
typedef struct { // 顶点表 结点
    int id; // 顶点数据域
    EdgeNode* first;// 边链表头指针
} VertexNode;
typedef struct { // 图的 邻接表
    VertexNode vlist[NumVertices];
    int n, e; // 顶点个数与边数
} AdjGraph;

AdjGraph G;               //图
int visited[NumVertices]; //访问数组
int dfn[NumVertices]; // 顶点的深度优先搜索编号

void CreateGraph();//建图
void DFS1(int i); //递归深度优先遍历
void DFS2(int i); //非递归深度优先遍历
int main()
{
    CreateGraph();      //建图
    for (int i = 1; i <= G.n; i++) visited[i] = -1; //访问数组初始化
    cout << "递归深度优先搜索序列：";
    for (int i = 1; i <= G.n; i++)
    {
        if (visited[i] == -1)
            DFS1(i); // 从顶点 i 出发的一次搜索，DFSX(G, i )
    }
    cout << endl << "非递归深度优先搜索序列：";
    for (int i = 1; i <= G.n; i++) visited[i] = -1; //访问数组再次初始化
    for (int i = 1; i <= G.n; i++)
    {
        if (visited[i] == -1)
            DFS2(i); // 从顶点 i 出发的一次搜索，DFSX(G, i )
    }
}
void CreateGraph()
{
    cout << "请输入顶点个数和边数:" << endl;
    cin >> G.n >> G.e; //1. 输入顶点个数和边数
    for (int i = 1; i <= G.n; i++) { //2. 建立顶点表
        G.vlist[i].id = i; //2.1 顶点信息
        G.vlist[i].first = NULL;
    } //2.2 边表置为空表
    for (int i = 1; i <= G.e; i++) { //3. 逐条边输入, 建立边表
        int tail, head;
        cout << "请输入第" << i << "条边的两个顶点";
        cin >> tail >> head; //3.1 输入
        EdgeNode* p = new EdgeNode; //3.2 建立边结点
        p->ad = head; //3.3 设置边结点
        p->next = G.vlist[tail].first; //3.4 链入第 tail 号链表的前端
        G.vlist[tail].first = p;
        p = new EdgeNode;
        p->ad = tail;
        p->next = G.vlist[head].first; // 链入第 head 号链表的前端
        G.vlist[head].first = p;
    }
}
void DFS1(int i)
// 以第i号结点为出发点时对邻接表表示的图G 进行深度优先搜索
{
    EdgeNode* p;
    cout << G.vlist[i].id << " ";
    visited[i] = 1;
    p = G.vlist[i].first;
    while (p != NULL) {
        if (visited[p->ad] == -1)
            DFS1(p->ad);
        p = p->next;
    }
} //DFS1 递归算法
void DFS2(int i) //非递归深度优先遍历
{
    int s[NumVertices];
    int top = -1;
    s[++top] = i;
    visited[i] = 1;
    while (top >= 0)
    {
        int k = s[top--];
        cout << G.vlist[k].id << " ";
        for (EdgeNode* j = G.vlist[k].first; j != NULL; j = j->next)
        {
            if (visited[j->ad] == -1)
            {
                s[++top] = j->ad;
                visited[j->ad] = 1;
            }
        }
    }
}