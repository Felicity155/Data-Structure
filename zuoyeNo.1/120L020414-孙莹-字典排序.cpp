//���ۿ��ܵĴ洢�ṹ��
//������Ŀ������8���ַ��������Բ��ñ������еĶ�ά���飬Ҳ���Բ�������������������Ŀ���ݽ��ٵ�����£��Դ洢�ռ�Ҫ�󲻴��ö�ά���鼴�ɣ�Ҳ���ڴ���
#include<vector>
#include <iostream>
#include<stdio.h>
using namespace std;
int flag(char a); //��ĸ���ֵ���˳��
int compare(vector<char>& member1, vector<char>& member2); //�Ƚ�λ�ã���������

int main()
{
	vector<vector<char>> member;
	member = { {'P','A','B'},{'5','C'},{'P','A','B','C'},{'C','X','Y'},{'C','R','S','I'},{'7' }, { 'B','8','9','9' }, { 'B','9' } };
	vector<char> temp;
	//ð������
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
	//��һ�������㷨
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
	//������������Ƿ�ɹ�
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
	//�ַ��������ڱȽ�
	for (int i = 0; i < member1.size(), i < member2.size(); i++)
	{
		if (flag(member1[i]) < flag(member2[i]))
			return 1;
		else if (flag(member1[i]) > flag(member2[i]))
			return 0;
		else;
	}
	//�ַ��������ڶ���ͬ����Ҫ�Ƚϳ���
	if (member1.size() < member2.size())
		return 1;
	else if (member1.size() > member2.size())
		return 0;
}