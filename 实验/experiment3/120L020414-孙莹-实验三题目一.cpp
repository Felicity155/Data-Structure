#include <iostream>
using namespace std;
#define NumVertices 50

typedef struct node {// �߱� ���
    int ad; // �ڽӵ����±꣩
    struct node* next; // ��һ������ָ��
} EdgeNode;
typedef struct { // ����� ���
    int id; // ����������
    EdgeNode* first;// ������ͷָ��
} VertexNode;
typedef struct { // ͼ�� �ڽӱ�
    VertexNode vlist[NumVertices];
    int n, e; // ������������
} AdjGraph;

AdjGraph G;               //ͼ
int visited[NumVertices]; //��������
int dfn[NumVertices]; // �������������������

void CreateGraph();//��ͼ
void DFS1(int i); //�ݹ�������ȱ���
void DFS2(int i); //�ǵݹ�������ȱ���
int main()
{
    CreateGraph();      //��ͼ
    for (int i = 1; i <= G.n; i++) visited[i] = -1; //���������ʼ��
    cout << "�ݹ���������������У�";
    for (int i = 1; i <= G.n; i++)
    {
        if (visited[i] == -1)
            DFS1(i); // �Ӷ��� i ������һ��������DFSX(G, i )
    }
    cout << endl << "�ǵݹ���������������У�";
    for (int i = 1; i <= G.n; i++) visited[i] = -1; //���������ٴγ�ʼ��
    for (int i = 1; i <= G.n; i++)
    {
        if (visited[i] == -1)
            DFS2(i); // �Ӷ��� i ������һ��������DFSX(G, i )
    }
}
void CreateGraph()
{
    cout << "�����붥������ͱ���:" << endl;
    cin >> G.n >> G.e; //1. ���붥������ͱ���
    for (int i = 1; i <= G.n; i++) { //2. ���������
        G.vlist[i].id = i; //2.1 ������Ϣ
        G.vlist[i].first = NULL;
    } //2.2 �߱���Ϊ�ձ�
    for (int i = 1; i <= G.e; i++) { //3. ����������, �����߱�
        int tail, head;
        cout << "�������" << i << "���ߵ���������";
        cin >> tail >> head; //3.1 ����
        EdgeNode* p = new EdgeNode; //3.2 �����߽��
        p->ad = head; //3.3 ���ñ߽��
        p->next = G.vlist[tail].first; //3.4 ����� tail �������ǰ��
        G.vlist[tail].first = p;
        p = new EdgeNode;
        p->ad = tail;
        p->next = G.vlist[head].first; // ����� head �������ǰ��
        G.vlist[head].first = p;
    }
}
void DFS1(int i)
// �Ե�i�Ž��Ϊ������ʱ���ڽӱ��ʾ��ͼG ���������������
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
} //DFS1 �ݹ��㷨
void DFS2(int i) //�ǵݹ�������ȱ���
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