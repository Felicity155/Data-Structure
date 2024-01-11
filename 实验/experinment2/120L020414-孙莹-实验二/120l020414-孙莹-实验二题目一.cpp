//已知二叉树的前序序列和中序序列，建立相应的二叉树，完成遍历算法（前、中、后序的非递归遍历）；要求输出二叉树，二叉树结点个数不少于8 个；
//测试用例①： 前序：ABCDEFGHI#
//             中序：BCAEDGHFI#   
//         输出后序：CBEHGIFDA
//测试用例②： 前序：ABDEC#
//             中序：DBEAC#   
//         输出后序：DEBCA
//测试用例③： 前序：FCAEGDB#
//             中序：CEAFDBG#   
//         输出后序：EACBDGF
#include <iostream>
#include<stack>
using namespace std;

typedef struct TREE {
    char data;
    TREE* lchild;
    TREE* rchild;
}TREE;

TREE* tree_creat(char A[], char B[], int l1, int h1, int l2, int h2); //根据中序和前序序列建树
void PreOrder(TREE* T);                                               //前序非递归
void InOrder(TREE* T);                                                //中序非递归
void PostOrder(TREE* T);                                              //后序非递归

int main()
{
    char A[40], B[40];
    int l1 = 1, l2 = 1;
    int h1 = 0, h2 = 0;
    cout << "请输入前序序列（最多30个字符，以#结尾）" << endl;
    do {
        h1++;
        cin >> A[h1];
    } while (A[h1] != '#');
    h1--;
    cout << "请输入中序序列（最多30个字符，以#结尾）" << endl;
    do {
        h2++;
        cin >> B[h2];
    } while (B[h2] != '#');
    h2--;

    TREE* root;
    root = (TREE*)malloc(sizeof(TREE));
    root = tree_creat(A, B, l1, h1, l2, h2);
    cout << endl;
    cout << "非递归输出先序遍历：" << endl;
    PreOrder(root);
    cout << endl;
    cout << "非递归输出中序遍历：" << endl;
    InOrder(root);
    cout << endl;
    cout << "非递归输出后序遍历：" << endl;
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
    llen = i - l2;        //左子树长度
    rlen = h2 - i;        //右子树长度
    if (llen != 0)
    {
        root->lchild = tree_creat(A, B, l1 + 1, l1 + llen, l2, l2 + llen - 1);
        //递归建立左子树
    }
    else
    {
        root->lchild = NULL;
    }
    if (rlen != 0)
    {
        root->rchild = tree_creat(A, B, h1 - rlen + 1, h1, h2 - rlen + 1, h2);
        //递归建立右子树
    }
    else
    {
        root->rchild = NULL;
    }
    return root;
}

void PreOrder(TREE* T)
{
    TREE* S[40]; // 递归工作栈
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
            p = p->lchild; // 进左子树
        else
        {
            p = S[flag - 1];
            flag--;
        }
    } // 左子树空, 访问右子树 
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
            //走到最左
        }
        if (flag >= 0)
        {
            T = S[flag];
            flag--;
            //弹出栈顶
            cout << T->data;
            T = T->rchild;
            //进入右子树
        }
    }
}
void PostOrder(TREE* T)
{
    TREE* S[40];
    TREE* r = NULL;      //用来标志上一个访问的结点
    int top = -1;
    while (T != NULL || top != -1)
    {
        if (T != NULL)
        {
            top++;
            S[top] = T;
            T = T->lchild;//走到最左
        }
        else
        {
            T = S[top];//读取栈顶【不是弹栈！！】
            if (T->rchild != NULL && T->rchild != r) 
                T = T->rchild;
            //如果右子树还未访问过，要先访问右子树
            else {
                //如果右子树访问过了，那则访问他自己
                cout << T->data;
                top--;
                r = T;
                T = NULL;
            }
        }
    }
}