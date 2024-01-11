#include<vector>
#include <iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int n;
    vector<int> flower(1000);
    cin >> n;
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1 || n == 2)
    {
        printf("\nN应该大于等于3");
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> flower[i];
    }
    //存入花盆信息
    int left = 0;
    int right = n - 1;
    int temp;
    //此while用于先将白色移到队伍末尾
    while (left < right)
    {
        if ((flower[left] == 2) && (flower[right] == 1 || flower[right] == 3))
        {
            temp = flower[left];
            flower[left] = flower[right];
            flower[right] = temp;
        }
        else if (flower[left] == 1 || flower[left] == 3)
            left++;
        else if (flower[right] == 2)
            right--;
    }
    left = 0;
    right = right - 1;
    //再将白色之前的红蓝两色排好顺序
    while (left < right)
    {
        if (flower[left] == 3 && flower[right] == 1)
        {
            temp = flower[left];
            flower[left] = flower[right];
            flower[right] = temp;
            left++;
            right--;
        }
        else if (flower[left] == 1)
        {
            left++;
        }
        else if (flower[right] == 3)
        {
            right--;
        }

    }
    //打印出来检查效果
    for (int i = 0; i < n; i++)
    {
        printf("%d", flower[i]);
    }
    return 0;
}