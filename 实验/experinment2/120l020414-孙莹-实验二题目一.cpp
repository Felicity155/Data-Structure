//��֪��������ǰ�����к��������У�������Ӧ�Ķ���������ɱ����㷨��ǰ���С�����ķǵݹ��������Ҫ�������������������������������8 ����
//���������٣� ǰ��ABCDEFGHI#
//             ����BCAEDGHFI#   
//         �������CBEHGIFDA
//���������ڣ� ǰ��ABDEC#
//             ����DBEAC#   
//         �������DEBCA
//���������ۣ� ǰ��FCAEGDB#
//             ����CEAFDBG#   
//         �������EACBDGF
#include <iostream>
#include<stack>
using namespace std;

typedef struct TREE {
    char data;
    TREE* lchild;
    TREE* rchild;
}TREE;

TREE* tree_creat(char A[], char B[], int l1, int h1, int l2, int h2); //���������ǰ�����н���
void PreOrder(TREE* T);                                               //ǰ��ǵݹ�
void InOrder(TREE* T);                                                //����ǵݹ�
void PostOrder(TREE* T);                                              //����ǵݹ�

int main()
{
    char A[40], B[40];
    int l1 = 1, l2 = 1;
    int h1 = 0, h2 = 0;
    cout << "������ǰ�����У����30���ַ�����#��β��" << endl;
    do {
        h1++;
        cin >> A[h1];
    } while (A[h1] != '#');
    h1--;
    cout << "�������������У����30���ַ�����#��β��" << endl;
    do {
        h2++;
        cin >> B[h2];
    } while (B[h2] != '#');
    h2--;

    TREE* root;
    root = (TREE*)malloc(sizeof(TREE));
    root = tree_creat(A, B, l1, h1, l2, h2);
    cout << endl;
    cout << "�ǵݹ�������������" << endl;
    PreOrder(root);
    cout << endl;
    cout << "�ǵݹ�������������" << endl;
    InOrder(root);
    cout << endl;
    cout << "�ǵݹ�������������" << endl;
    PostOrder(root);
    cout << endl;
}
TREE* tree_creat(char A[], char B[], int l1, int h1, int l2, int h2)
{
    TREE* root;
    root = (TREE*)malloc(sizeof(TREE));
    root->data = A[l1];
    int i, llen, rlen;
    for (i = l2; B[i] != root->data; i++);
    llen = i - l2;        //����������
    rlen = h2 - i;        //����������
    if (llen != 0)
    {
        root->lchild = tree_creat(A, B, l1 + 1, l1 + llen, l2, l2 + llen - 1);
        //�ݹ齨��������
    }
    else
    {
        root->lchild = NULL;
    }
    if (rlen != 0)
    {
        root->rchild = tree_creat(A, B, h1 - rlen + 1, h1, h2 - rlen + 1, h2);
        //�ݹ齨��������
    }
    else
    {
        root->rchild = NULL;
    }
    return root;
}

void PreOrder(TREE* T)
{
    TREE* S[40]; // �ݹ鹤��ջ
    int flag = 0;
    struct TREE* p = T;
    while (p != NULL && flag >= 0) {
        cout << p->data;
        if (p->rchild != NULL)
        {
            S[flag] = p->rchild;
            flag++;
        }
        if (p->lchild != NULL)
            p = p->lchild; // ��������
        else
        {
            p = S[flag - 1];
            flag--;
        }
    } // ��������, ���������� 
}
void InOrder(TREE* T)
{
    TREE* S[40];
    int flag = -1;
    while (T != NULL || flag != -1)
    {
        while (T != NULL)
        {
            S[++flag] = T;
            T = T->lchild;
            //�ߵ�����
        }
        if (flag >= 0)
        {
            T = S[flag];
            flag--;
            //����ջ��
            cout << T->data;
            T = T->rchild;
            //����������
        }
    }
}
void PostOrder(TREE* T)
{
    TREE* S[40];
    TREE* r = NULL;      //������־��һ�����ʵĽ��
    int top = -1;
    while (T != NULL || top != -1)
    {
        if (T != NULL)
        {
            top++;
            S[top] = T;
            T = T->lchild;//�ߵ�����
        }
        else
        {
            T = S[top];//��ȡջ�������ǵ�ջ������
            if (T->rchild != NULL && T->rchild != r) 
                T = T->rchild;
            //�����������δ���ʹ���Ҫ�ȷ���������
            else {
                //������������ʹ��ˣ�����������Լ�
                cout << T->data;
                top--;
                r = T;
                T = NULL;
            }
        }
    }
}