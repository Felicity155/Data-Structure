//�������н�������Ϊ������Ϊ1��������Ϊ0
//Ҫ�������ļ���Ϊ��paper.txt����������ֻ��a~z 26��Ӣ��Сд��ĸ�����������ļ���Ϊ��data.txt����
#include<iostream>
#include<string.h>
using namespace std;

typedef struct TREE {
	int frecy; //�˽ڵ�Ȩ��ֵ
	int asc;   //���ڱ�־a~z�ַ�λ��
	TREE* lchild;//����
	TREE* rchild;//�Һ���
	int parent;  //���ڵ��ڽ����е�λ��
	int been;    //��־����Ƿ����
}TREE;
TREE* eng[100]; //ǰ26ΪҶ��㣬ʣ�µ����ڽ���ʱ�洢�½����
char code[27][50];//�洢����������
int flag = 26;//��־��������λ��


int find_min(int& min1, int& min2);//���ڽ���ʱѰ��ֵ��С�Ŀ��ý��
void writein(TREE* root);//������д���ļ�
void readout(TREE* root);//���ļ������������뷭��Ϊ����
void Encoding();//�����㷨�ҵ�ÿ��Ҷ����Ӧ�Ĺ���������


int main() {
	FILE* fp;
	fopen_s(&fp, "paper.txt", "r");
	if (fp == NULL) {
		cout << "�򲻿��ļ�";
		exit(0);
	}
	//�����ʼ��
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
	//����ÿ����ĸ��Ƶ��
	char temp;
	while (fscanf_s(fp, "%c", &temp, 1) != EOF)
	{
		eng[temp - 'a']->frecy++;
	}
	fclose(fp);
	//��ʼ����
	TREE* root;
	root = (TREE*)malloc(sizeof(TREE));
	int min1, min2;
	while (find_min(min1, min2) != 0)
	//����ҵ�������С���ý�㣬��Ҫ�½����Ϊ���������ĸ��ڵ�
	{
		eng[min1]->parent = flag;
		eng[min2]->parent = flag;
		eng[flag]->lchild = eng[min1];
		eng[flag]->rchild = eng[min2];
		eng[flag]->frecy = eng[min1]->frecy + eng[min2]->frecy;
		flag++;
	}
	root = eng[min1];
	//���ʣ��һ��û�и��ڵ�Ŀ��ý�㣬Ҳ���Ǹ��ڵ�
	Encoding();   //������ÿ����ĸ����
	writein(root);//����
	readout(root);//����
}

int find_min(int& min1, int& min2)
{
	int temp = 9999999;
	int min1_temp = -1, min2_temp = -1;
	//��Ȩֵ��С���
	for (int i = 0; i < flag; i++)
	{
		if (eng[i]->been == 0 && eng[i]->frecy < temp)
		{
			min1_temp = i;
			temp = eng[i]->frecy;
		}
	}
	if (min1_temp != -1) eng[min1_temp]->been = 1;
	//��Ȩֵ�ڶ�С�Ľ��
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
		cout << "д���ļ�ʧ��\n";
		exit(0);
	}
	FILE* fp;
	fopen_s(&fp, "paper.txt", "r");
	if (fp == NULL) {
		cout << "�򲻿��ļ�";
		exit(0);
	}
	char temp;
	while (fscanf_s(fp, "%c", &temp, 1) != EOF)
	{
		//�ӡ�paper.txt����ÿ�ζ�ȡһ���ַ����������������д�롰data.txt��
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
		cout << "�򲻿��ļ�";
		exit(0);
	}
	char temp;
	while (fscanf_s(fp, "%c", &temp) != EOF)
	{
		//�ӡ�data.txt���ж�ȡ����
		if (temp == '1')//1����������
		{
			p = p->lchild;
		}
		else if (temp == '0')//0����������
		{
			p = p->rchild;
		}
		if (p->lchild == NULL && p->rchild == NULL)//�ߵ�Ҷ�������
		{
			printf("%c", 'a' + p->asc);
			p = root;
		}
	}
	fclose(fp);
}

void Encoding()
{ // ����Huffman ��T ��Huffman ����� H
	int c, p, i; // c ��p �ֱ�ָʾT �к��Ӻ�˫�׵�λ��
	char cd[100 + 1]; // ��ʱ��ű���
	int start; // ָʾ������cd �е�λ��
	cd[100] = '\0'; // ���������
	for (i = 0; i < 26; i++) { // ������Ҷ��T[i] �ı���
		start = 100; // ������ʼλ�õĳ�ֵ
		c = i; // ��Ҷ��T[i] ��ʼ����
		while ((p = eng[c]->parent) >= 0) { // ֱ�����ݵ�T[c] ������λ��
			if (eng[p]->lchild->asc == c)
			{
				cd[--start] = '1';
			}
			else
			{
				cd[--start] = '0';
			}
			// ��T[c] ��T[p] �����ӣ������ɴ���1 ���������ɴ���0
			c = p; // ��������
		}
		for (int j = 0; j <= 100 - start; j++)
		{
			code[i][j] = cd[start + j];
		} // ���Ʊ���Ϊ���ڱ����H

	}
}
