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