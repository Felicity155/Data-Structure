#include<iostream>
using namespace std;
#define size_max 16
using namespace std;
typedef struct V {
	int farmer;
	int sheep;
	int veget;
	int wolf;
}V;//ÿһ���������һ�ֹ���״̬��0Ϊ��࣬1Ϊ�Ҳ�
typedef struct G {
	int num;          //ͼ�ڶ������
	V dian[size_max];     //��������
	int bian[size_max][size_max];//�洢�ߵ��ڽӾ���0Ϊ�ޱߣ�1Ϊ�б�
};
G tu;//ͼ�ṹ
int path[size_max] = { -1 };//����·��
int been[size_max] = { 0 };//��Ƿ�������

void creat_tu();//����ͼ
int ok(int farmer, int sheep, int veget, int wolf);//�ж�ĳ��״̬��ϲ��Ϸ�
int can(int i, int j);//�ж�ĳ����״̬֮��ɲ�����ת����������֮��������
void BFS_path(int start, int end);
void print_path();
int main()
{
	creat_tu();
	int start = 0;
	int end = 9;
	creat_tu();
	BFS_path(start, end);
	print_path();
	return 0;
}
void creat_tu()
{
	tu.num = 0;
	for (int f = 0; f <= 1; f++)
	{
		for (int s = 0; s <= 1; s++)
		{
			for (int v = 0; v <= 1; v++)
			{
				for (int w = 0; w <= 1; w++)
				{
					if (ok(f, s, v, w) == 1)//���������ĵ�ʹ���
					{
						tu.dian[tu.num].farmer = f;
						tu.dian[tu.num].sheep = s;
						tu.dian[tu.num].veget = v;
						tu.dian[tu.num].wolf = w;
						tu.num++;
					}
				}
			}
		}
	}
	for (int i = 0; i < tu.num; i++)
	{
		for (int j = 0; j < tu.num; j++)
		{
			if (can(i, j) == 1)//��ת���ĵ�֮������
			{
				tu.bian[i][j] = 1;
				tu.bian[j][i] = 1;
			}
			else
			{
				tu.bian[i][j] = 0;
				tu.bian[j][i] = 0;
			}
		}
	}
}
int ok(int farmer, int sheep, int veget, int wolf)
{
	if (sheep == veget && farmer != sheep)
		return 0;
	if (wolf == sheep && farmer != wolf)
		return 0;
	return 1;
}
int can(int i, int j)
{
	int dong = 0;
	if (tu.dian[i].sheep != tu.dian[j].sheep) dong++;
	if (tu.dian[i].veget != tu.dian[j].veget) dong++;
	if (tu.dian[i].wolf != tu.dian[j].wolf) dong++;

	if (dong <= 1 && tu.dian[i].farmer != tu.dian[j].farmer)
		return 1;
	else
		return 0;
}
void BFS_path(int start, int end)
{
	int i = 0;
	been[start] = 1;
	if (start == end) return;
	for (i = 0; i < tu.num; i++)
	{
		if (tu.bian[start][i] == 1 && been[i] != 1)
		{
			path[start] = i;
			BFS_path(i, end);
		}
	}
}
void print_path()
{
	int i = 0;
	while (i != 9)
	{
		cout << "�������У� ";
		if (tu.dian[i].farmer == 0)  cout << "farmer ";
		if (tu.dian[i].sheep == 0)  cout << "sheep ";
		if (tu.dian[i].veget == 0)  cout << "veget ";
		if (tu.dian[i].wolf == 0)  cout << "wolf ";
		cout << "              ";
		cout << "���Ҳ���У� ";
		if (tu.dian[i].farmer == 1)  cout << "farmer ";
		if (tu.dian[i].sheep == 1)  cout << "sheep ";
		if (tu.dian[i].veget == 1)  cout << "veget ";
		if (tu.dian[i].wolf == 1)  cout << "wolf ";
		cout << endl;
		i = path[i];
	}
	i = 9;
	cout << "�������У� ";
	if (tu.dian[i].farmer == 0)  cout << "farmer ";
	if (tu.dian[i].sheep == 0)  cout << "sheep ";
	if (tu.dian[i].veget == 0)  cout << "veget ";
	if (tu.dian[i].wolf == 0)  cout << "wolf ";
	cout << "              ";
	cout << "���Ҳ���У� ";
	if (tu.dian[i].farmer == 1)  cout << "farmer ";
	if (tu.dian[i].sheep == 1)  cout << "sheep ";
	if (tu.dian[i].veget == 1)  cout << "veget ";
	if (tu.dian[i].wolf == 1)  cout << "wolf ";
	cout << endl;
}
