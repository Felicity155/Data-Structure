#include<stdio.h>
#include <iostream>
#include<vector>
#include<string>
using namespace std;


int main()
{
	string num; //����
	int devide; //������
	while (true)
	{
		cout << "����������\n";
		cin >> num;
		for (int i = 0; i < num.size(); i++)
		{
			if (num[i] < '0' || num[i]>'9')
			{
				cout << "�зǷ��ַ�\n";
				break;
			}
		}
		cin >> devide;
		long long  sum = 0;
		int result;
		for (int i = 0; i < num.size(); i++)
		{
			long long tmp = (num[i] - '0') % devide;
			for (int j = 0; j < num.size() - i - 1; j++)
			{
				tmp = tmp * (10 % devide);
			}
			tmp = tmp % devide;
			sum = sum + tmp;
			//printf("��%dλ ������%d Ŀǰ��������%d\n", i, tmp, sum);
		}
		result = sum % devide;
		cout << "������" << result << endl;
	}

	return 0;
}#include<stdio.h>
#include <iostream>
#include<vector>
#include<string>
using namespace std;


int main()
{
	for (int k = 1; k != 0; k++)
	{
		string num; //����
		int devide; //������
		cout << "����������\n";
		cin >> num;
		int flag = -1; //�ж����ݺϷ���
		for (int i = 0; i < num.size(); i++)
		{
			if (num[i] < '0' || num[i]>'9')
			{
				cout << "�зǷ��ַ�,��1 �������������ݣ���0 ��������\n";
				cin >> flag;
				break;
			}
		}
		if (flag == 1)
		{
			continue;
		}
		else if (flag == 0)
		{
			break;
		}
		cin >> devide;
		long long  sum = 0;
		int result;
		for (int i = 0; i < num.size(); i++)
		{
			long long tmp = (num[i] - '0') % devide;
			for (int j = 0; j < num.size() - i - 1; j++)
			{
				tmp = tmp * (10 % devide);
			}
			tmp = tmp % devide;
			sum = sum + tmp;
			//printf("��%dλ ������%d Ŀǰ��������%d\n", i, tmp, sum);
		}
		result = sum % devide;
		cout << "������" << result << endl;
	}

	return 0;
}