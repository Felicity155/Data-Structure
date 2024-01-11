//��������1��ABD##E##C##  �����YES
// ����������ͼΪ�� A
//                 / \
//                B	  C
//               / \
//              D   E
//��������2��ABD#G###CE##F##  �����NO
//����������ͼΪ��  A
//                 / \
//                B   C
//               /   / \
//              D   E   F
//               \
//                G
//
#include <iostream>
#include<stdio.h>
#include<queue>
using namespace std;
typedef struct Tree {
	char data;
	struct Tree* lchild, * rchild;
}Tree;

void Creat_Tree(Tree*& root); //�������˳�򴴽�������
int Complete_Tree(Tree* root);//�ж��Ƿ�Ϊ��ȫ������

int main()
{
	Tree* root = NULL;
	printf("��#�������������:\n");
	Creat_Tree(root);
	if (Complete_Tree(root) == 1)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
void Creat_Tree(Tree*& root) //�������˳�򴴽�������
{
	char temp;
	cin >> temp;
	if (temp == '#') root = NULL;
	else
	{
		root = new Tree;
		root->data = temp;
		Creat_Tree(root->lchild);
		Creat_Tree(root->rchild);
	}
}
int Complete_Tree(Tree* root)//�ж��Ƿ�Ϊ��ȫ������
{
	if (root == NULL) return 0;
	queue<Tree*> q;
	Tree e;
	q.push(root);
	Tree* cur = q.front();
	while (cur != NULL)
	{
		q.pop();
		q.push(cur->lchild);
		q.push(cur->rchild);
		cur = q.front();
	}
	q.pop();
	while (!q.empty())
	{
		if (q.front() != NULL) return 0;
		q.pop();
	}
	return 1;
}