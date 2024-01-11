//左子树为1，右子树为0
#include<iostream>
#include<string.h>
using namespace std;

typedef struct TREE {
	int frecy;
	int asc;
	TREE* lchild;
	TREE* rchild;
	int parent;
	int been;
}TREE;
TREE* eng[100];
char code[27][50];
int flag = 26;


int find_min(int& min1, int& min2);
void writein(TREE* root);
void readout(TREE* root);
void Encoding();


int main() {
	FILE* fp;
	fopen_s(&fp, "paper.txt", "r");
	if (fp == NULL) {
		cout << "打不开文件";
		exit(0);
	}
	for (int i = 0; i < 100; i++)
	{
		eng[i] = (TREE*)malloc(sizeof(TREE));
		eng[i]->lchild = NULL;
		eng[i]->rchild = NULL;
		eng[i]->frecy = 1;
		eng[i]->been = 0;
		eng[i]->asc = i;
		eng[i]->parent = -1;
	}
	char temp;
	while (fscanf_s(fp, "%c", &temp, 1)!=EOF)
	{
			eng[temp - 'a']->frecy++;
	}
	fclose(fp);
	TREE* root;
	root= (TREE*)malloc(sizeof(TREE));
	int min1, min2;
	while (find_min(min1, min2) !=0)
	{
		eng[min1]->parent = flag;
		eng[min2]->parent = flag;
		eng[flag]->lchild = eng[min1];
		eng[flag]->rchild = eng[min2];
		eng[flag]->frecy = eng[min1]->frecy + eng[min2]->frecy;
		flag++;
	}
	root = eng[min1];
	Encoding();
	writein(root);
	readout(root);
}

int find_min(int& min1, int& min2)
{
	int temp = 9999999;
	int min1_temp=-1, min2_temp=-1;
	for (int i = 0; i < flag; i++)
	{
		if (eng[i]->been == 0 && eng[i]->frecy < temp)
		{
			min1_temp = i;
			temp = eng[i]->frecy;
		}
	}
	if (min1_temp != -1) eng[min1_temp]->been = 1;
	temp = 999999;
	for (int i = 0; i < flag; i++)
	{
		if (eng[i]->been == 0 && eng[i]->frecy < temp)
		{
			min2_temp = i;
			temp = eng[i]->frecy;
		}
	}
	if (min2_temp != -1) eng[min2_temp]->been = 1;
	min1 = min1_temp;
	min2 = min2_temp;

	if (min1_temp != -1 && min2_temp != -1)
	{
		return 1;
	}
	else
	{
		return 0;

	}
}

void writein(TREE* root)
{
	FILE* fp2;
	fopen_s(&fp2,"data.txt", "w");
	if (fp2 == NULL)
	{
		cout << "写入文件失败\n";
		exit(0);
	}
	FILE* fp;
	fopen_s(&fp, "paper.txt", "r");
	if (fp == NULL) {
		cout << "打不开文件";
		exit(0);
	}
	char temp;
	while (fscanf_s(fp, "%c", &temp, 1)!=EOF)
	{
		for (int j = 0; code[temp - 'a'][j] != '\0'; j++)
		{
			fprintf(fp2, "%c", code[temp - 'a'][j]);
		}
	}
	fclose(fp);
	fclose(fp2);
}

void readout(TREE* root)
{
	TREE* p = root;
	FILE* fp;
	fopen_s(&fp, "data.txt", "r");
	if (fp == NULL) {
		cout << "打不开文件";
		exit(0);
	}
	char temp;
	while (fscanf_s(fp, "%c", &temp) != EOF)
	{

		if (temp == '1')
		{
			p = p->lchild;
		}
		else if (temp == '0')
		{
			p = p->rchild;
		}
		if (p->lchild == NULL && p->rchild == NULL)
		{
			printf("%c", 'a' + p->asc);
			p = root;
		}
	}
	fclose(fp);
}

void Encoding()
{ // 根据Huffman 树T 求Huffman 编码表 H
	int c, p, i; // c 和p 分别指示T 中孩子和双亲的位置
	char cd[100 + 1]; // 临时存放编码
	int start; // 指示编码在cd 中的位置
	cd[100] = '\0'; // 编码结束符
	for (i = 0; i < 26; i++) { // 依次求叶子T[i] 的编码
		start = 100; // 编码起始位置的初值
		c = i; // 从叶子T[i] 开始上溯
		while ((p = eng[c]->parent) >= 0) { // 直到上溯到T[c] 是树根位置
			if (eng[p]->lchild->asc == c)
			{
				cd[--start] = '1';
			}
			else
			{
				cd[--start] = '0';
			}
			// 若T[c] 是T[p] 的左孩子，则生成代码1 ，否则生成代码0
			c = p; // 继续上溯
		}
		for (int j = 0; j <= 100-start; j++)
		{
			code[i][j] = cd[start + j];
		} // 复制编码为串于编码表H

	}
}
