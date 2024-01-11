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
        printf("\nNӦ�ô��ڵ���3");
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> flower[i];
    }
    //���뻨����Ϣ
    int left = 0;
    int right = n - 1;
    int temp;
    //��while�����Ƚ���ɫ�Ƶ�����ĩβ
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
    //�ٽ���ɫ֮ǰ�ĺ�����ɫ�ź�˳��
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
    //��ӡ�������Ч��
    for (int i = 0; i < n; i++)
    {
        printf("%d", flower[i]);
    }
    return 0;
}