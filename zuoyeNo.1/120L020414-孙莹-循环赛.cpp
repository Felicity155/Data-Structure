//此题可转化为图模型，选手为点，Pi胜Pj即为Pi指向Pj的一条边，求题目中要求的序列也就是求一条有向路。
//
//测试用例1：
// 请输入选手数量n(2到100)
//4
//请输入n * n的矩阵
//aij 为【1】表明i选手赢了j选手，aij为【0】表明i选手输给了j选手
//(对角线填【2】，表示自己未与自己比赛)
//2 1 0 0
//0 2 1 1
//1 0 2 0
//1 0 1 2
//4 -> 1 -> 2 -> 3
// 
//测试用例2：
//请输入选手数量n(2到100)
//4
//请输入n * n的矩阵
//aij 为【1】表明i选手赢了j选手，aij为【0】表明i选手输给了j选手
//(对角线填【2】，表示自己未与自己比赛)
//2 0 0 0
//1 2 0 0
//1 1 2 0
//1 1 1 2
//4 -> 3 -> 2 -> 1
#include<stdio.h>
#include <iostream>
#include<vector>
int win = 0;        //标志是否找到
int loc = -1;       //用于排序后存入数组
using namespace std;

int go(int start, int size, vector<vector<int>>& race, vector<int>& order);  //递归程序用于排序
int test(int test_size, vector<int>& order, vector<vector<int>> race);       //检验找到的排序是否正确

int main()
{
	int n;
	vector<vector<int>> race(100);       //储存比赛结果
	vector<int> order;           //用于储存排序后的选手顺序
	order.resize(100);
	cout << "请输入选手数量n(2到100)" << endl;
	cin >> n;
	cout << "请输入n*n的矩阵\naij 为【1】表明i选手赢了j选手，aij为【0】表明i选手输给了j选手\n(对角线填【2】，表示自己未与自己比赛)" << endl;
	for (int i = 0; i < n; i++)
	{
		race[i].resize(100);
		order[i] = -1;
		for (int j = 0; j < n; j++)
		{
			cin >> race[i][j];
		}
	}
	//存入比赛结果
	for (int i = 0; i < n; i++)
	{
		loc = -1;
		if (go(i, n, race, order) == 3)  //找到会返回3，接下来打印
		{
			for (int i = 0; i < n - 1; i++)
			{
				printf("%d -> ", order[i] + 1);
			}
			printf("%d", order[n - 1] + 1);
			break;
		}
	}
	return 0;
}
int go(int start, int size, vector<vector<int>>& race, vector<int>& order)
{
	loc++;
	order[loc] = start;    //把找到的存入数组
	if (test(size, order, race) == 1)
	{
		return 3;
	}                      //找完了返回3
	else if (win != 1)     //如果没找到，继续递归
	{
		for (int j = 0; j < size; j++)   //对下一个可能排序的选手遍历
		{
			if (race[start][j] == 1)
			{
				go(j, size, race, order);
			}
			if (test(size, order, race) == 1)
			{
				return 3;
			}
			else if (test(size, order, race) == 2)  //测试结果为2说明排序是一个未包含所有选手的圈，需跳出，否则会陷入循环
			{
				break;
			}
		}
		loc--;  //排序失败时说明最新存入数组的选手不对，位置后退一位
		return 0;
	}
}
int test(int test_size, vector<int>& flag, vector<vector<int>> race)
{
	for (int i = 0; i < test_size; i++)
	{
		if (flag[i] == -1)                  //说明排序中断，没有把所有选手都排上
		{
			return 0;
		}
	}
	for (int i = 0; i < test_size - 1; i++) //说明得到的序列不满足胜负关系要求
	{
		if (race[flag[i]][flag[i + 1]] != 1)
		{
			return 0;
		}
	}
	for (int i = 0; i < test_size; i++)     //有选手被重复排序，陷入了圈循环
	{
		for (int j = i + 1; j < test_size; j++)
		{
			if (flag[i] == flag[j])
			{
				return 2;
			}
		}
	}
	return 1;
}
