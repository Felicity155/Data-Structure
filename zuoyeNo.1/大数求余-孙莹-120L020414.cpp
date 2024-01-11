#include<stdio.h>
#include <iostream>
#include<vector>
#include<string>
using namespace std;


int main()
{
	string num; //除数
	int devide; //被除数
	while (true)
	{
		cout << "请输入数字\n";
		cin >> num;
		for (int i = 0; i < num.size(); i++)
		{
			if (num[i] < '0' || num[i]>'9')
			{
				cout << "有非法字符\n";
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
			//printf("第%d位 余数是%d 目前余数和是%d\n", i, tmp, sum);
		}
		result = sum % devide;
		cout << "余数是" << result << endl;
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
		string num; //除数
		int devide; //被除数
		cout << "请输入数字\n";
		cin >> num;
		int flag = -1; //判断数据合法性
		for (int i = 0; i < num.size(); i++)
		{
			if (num[i] < '0' || num[i]>'9')
			{
				cout << "有非法字符,打1 想重新输入数据，打0 结束操作\n";
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
			//printf("第%d位 余数是%d 目前余数和是%d\n", i, tmp, sum);
		}
		result = sum % devide;
		cout << "余数是" << result << endl;
	}

	return 0;
}