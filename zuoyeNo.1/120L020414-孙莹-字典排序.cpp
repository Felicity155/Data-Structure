//讨论可能的存储结构：
//对于题目给出的8个字符串，可以采用本程序中的二维数组，也可以采用链表。但是在这种题目数据较少的情况下，对存储空间要求不大，用二维数组即可，也便于处理。
#include<vector>
#include <iostream>
#include<stdio.h>
using namespace std;
int flag(char a); //字母在字典中顺序
int compare(vector<char>& member1, vector<char>& member2); //比较位置，用于排序

int main()
{
	vector<vector<char>> member;
	member = { {'P','A','B'},{'5','C'},{'P','A','B','C'},{'C','X','Y'},{'C','R','S','I'},{'7' }, { 'B','8','9','9' }, { 'B','9' } };
	vector<char> temp;
	//冒泡排序
	for (int i = 7; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (compare(member[j], member[j + 1]) == 0)
			{
				temp = member[j];
				member[j] = member[j + 1];
				member[j + 1] = temp;
			}
		}
	}
	//另一种排序算法
	/*for (int i = 0; i < 8; i++)
	{

		for (int j = i+1; j < 8 ; j++)
		{
			if (compare(member[i], member[j]) == 0)
			{
				temp = member[i];
				member[i] = member[j];
				member[j] = temp;
			}
		}
	}*/
	//输出检验排序是否成功
	for (int k = 0; k < 8; k++)
	{
		for (int i = 0; i < member[k].size(); i++)
		{
			printf("%c", member[k][i]);
		}
		printf(" ");
	}
	return 0;
}
int flag(char a)
{
	vector<char> stand(36);
	stand = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9' };
	for (int i = 0; i < 36; i++)
	{
		if (a == stand[i])
			return i;
	}

}
int compare(vector<char>& member1, vector<char>& member2)
{
	//字符串长度内比较
	for (int i = 0; i < member1.size(), i < member2.size(); i++)
	{
		if (flag(member1[i]) < flag(member2[i]))
			return 1;
		else if (flag(member1[i]) > flag(member2[i]))
			return 0;
		else;
	}
	//字符串长度内都相同，需要比较长短
	if (member1.size() < member2.size())
		return 1;
	else if (member1.size() > member2.size())
		return 0;
}