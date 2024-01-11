//本程序中建树规则为左子树为1，右子树为0
//要求文章文件名为“paper.txt”，文章中只含a~z 26个英文小写字母；储存编码的文件名为“data.txt”。
#include<iostream>
#include<string.h>
using namespace std;

typedef struct TREE {
	int frecy; //此节点权重值
	int asc;   //用于标志a~z字符位置
	TREE* lchild;//左孩子
	TREE* rchild;//右孩子
	int parent;  //父节点在结点表中的位置
	int been;    //标志结点是否可用
}TREE;
TREE* eng[100]; //前26为叶结点，剩下的用于建树时存储新建结点
char code[27][50];//存储哈夫曼编码
int flag = 26;//标志有意义结点位置


int find_min(int& min1, int& min2);//用于建树时寻找值最小的可用结点
void writein(TREE* root);//将编码写入文件
void readout(TREE* root);//读文件将哈夫曼编码翻译为文章
void Encoding();//上溯算法找到每个叶结点对应的哈夫曼编码


int main() {
	FILE* fp;
	fopen_s(&fp, "paper.txt", "r");
	if (fp == NULL) {
		cout << "打不开文件";
		exit(0);
	}
	//结点表初始化
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
	//计算每个字母的频率
	char temp;
	while (fscanf_s(fp, "%c", &temp, 1) != EOF)
	{
		eng[temp - 'a']->frecy++;
	}
	fclose(fp);
	//开始建树
	TREE* root;
	root = (TREE*)malloc(sizeof(TREE));
	int min1, min2;
	while (find_min(min1, min2) != 0)
	//如果找到两个最小可用结点，需要新结点作为这两个结点的父节点
	{
		eng[min1]->parent = flag;
		eng[min2]->parent = flag;
		eng[flag]->lchild = eng[min1];
		eng[flag]->rchild = eng[min2];
		eng[flag]->frecy = eng[min1]->frecy + eng[min2]->frecy;
		flag++;
	}
	root = eng[min1];
	//最后剩下一个没有父节点的可用结点，也就是根节点
	Encoding();   //上溯找每个字母编码
	writein(root);//编码
	readout(root);//译码
}

int find_min(int& min1, int& min2)
{
	int temp = 9999999;
	int min1_temp = -1, min2_temp = -1;
	//找权值最小结点
	for (int i = 0; i < flag; i++)
	{
		if (eng[i]->been == 0 && eng[i]->frecy < temp)
		{
			min1_temp = i;
			temp = eng[i]->frecy;
		}
	}
	if (min1_temp != -1) eng[min1_temp]->been = 1;
	//找权值第二小的结点
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
	fopen_s(&fp2, "data.txt", "w");
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
	while (fscanf_s(fp, "%c", &temp, 1) != EOF)
	{
		//从“paper.txt”中每次读取一个字符，将其哈夫曼编码写入“data.txt”
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
		//从“data.txt”中读取编码
		if (temp == '1')//1向左子树走
		{
			p = p->lchild;
		}
		else if (temp == '0')//0向右子树走
		{
			p = p->rchild;
		}
		if (p->lchild == NULL && p->rchild == NULL)//走到叶结点就输出
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
		for (int j = 0; j <= 100 - start; j++)
		{
			code[i][j] = cd[start + j];
		} // 复制编码为串于编码表H

	}
}
