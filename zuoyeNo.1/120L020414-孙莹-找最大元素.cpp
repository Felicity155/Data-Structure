#include<vector>
#include <iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int n, L, r, t;
	int gray[600][600];
	cin >> n;
	cin >> L;
	cin >> r;
	cin >> t;
	for (int i = 0; I, n; i++)
	{
		for (int i = 0; j < n; j++)
		{
			cin >> gray[i][j];
		}
	}
	int count = 0;
	for (int i = 0; I, n; i++)
	{
		for (int i = 0; j < n; j++)
		{
			int num = 0;
			int grey = 0;
			for (int x = 0; x < n; x++)
			{
				for (int y = 0; y < n; y++)
				{
					if (abs(x - i) <= r && abs(y - j) <= r )
					{
						num++;
						grey=grey+gray[x][y]£»
					}
				}
			}
			if ((grey / num) <= t)
			{
				count++;
			}
		}
	}
	cout << count;
	return 0;
}
