#include<iostream>
using namespace std;
#define size_max 16
using namespace std;
typedef struct V {
	int farmer;
	int sheep;
	int veget;
	int wolf;
}V;//每一个顶点代表一种过河状态，0为左侧，1为右侧
typedef struct G {
	int num;          //图内顶点个数
	V dian[size_max];     //顶点序列
	int bian[size_max][size_max];//存储边的邻接矩阵，0为无边，1为有边
};
G tu;//图结构
int path[size_max] = { -1 };//储存路径
int been[size_max] = { 0 };//标记访问数组

void creat_tu();//生成图
int ok(int farmer, int sheep, int veget, int wolf);//判断某个状态点合不合法
int can(int i, int j);//判断某两个状态之间可不可以转化，即两点之间有无线
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
					if (ok(f, s, v, w) == 1)//符合条件的点就存入
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
			if (can(i, j) == 1)//可转化的点之间连线
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
		cout << "在左侧的有： ";
		if (tu.dian[i].farmer == 0)  cout << "farmer ";
		if (tu.dian[i].sheep == 0)  cout << "sheep ";
		if (tu.dian[i].veget == 0)  cout << "veget ";
		if (tu.dian[i].wolf == 0)  cout << "wolf ";
		cout << "              ";
		cout << "在右侧的有： ";
		if (tu.dian[i].farmer == 1)  cout << "farmer ";
		if (tu.dian[i].sheep == 1)  cout << "sheep ";
		if (tu.dian[i].veget == 1)  cout << "veget ";
		if (tu.dian[i].wolf == 1)  cout << "wolf ";
		cout << endl;
		i = path[i];
	}
	i = 9;
	cout << "在左侧的有： ";
	if (tu.dian[i].farmer == 0)  cout << "farmer ";
	if (tu.dian[i].sheep == 0)  cout << "sheep ";
	if (tu.dian[i].veget == 0)  cout << "veget ";
	if (tu.dian[i].wolf == 0)  cout << "wolf ";
	cout << "              ";
	cout << "在右侧的有： ";
	if (tu.dian[i].farmer == 1)  cout << "farmer ";
	if (tu.dian[i].sheep == 1)  cout << "sheep ";
	if (tu.dian[i].veget == 1)  cout << "veget ";
	if (tu.dian[i].wolf == 1)  cout << "wolf ";
	cout << endl;
}
