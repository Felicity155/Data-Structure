#include <iostream>
#include<vector>
#include<stdio.h>
using namespace std;

struct Num {
    int data;
    struct Num* next;
};
int main()
{
    //��������
    Num* head = nullptr;
    head = new Num;
    head->data = 1;
    head->next = nullptr;
    Num* p = head;
    for (int i = 2; i < 11; ++i)
    {
        Num* newhead = new Num;
        newhead->data = i;
        newhead->next = nullptr;
        p->next = newhead;
        p = newhead;
    }
    //���Kֵ
    int k;
    do {
        cout << "������K" << endl;
        cin >> k;
    } while (k > 10);
    int count;
    Num* pre;
    Num* curr;
    Num* last;
    Num* nextlast = head;
    Num* temp;
    //��ʼ��һ�ε���
    count = k;
    pre = nullptr;
    curr = head;
    last = head;                 //���ε��õ����ӵ㣬��¼���������´���������
    while (count > 0)
    {
        temp = curr->next; //��ʱ������һ���ڵ�
        curr->next = pre;       //��ǰ�ڵ�ָ����һ���ڵ�
        pre = curr;             //������һ�β����ġ���һ���ڵ㡱
        curr = temp;            //����ǰ�ڵ㡱���½���
        count--;                //count����;
    }
    Num* newhead = pre;         //��һ�ε��û�õ�ͷ�ڵ㣬��¼����
    //��ʼ���к���ĵ���
    for (int j = 0; j < 10 / k - 1; j++)
    {
        count = k;
        pre = nullptr;
        nextlast = curr;                 //��һ�ε��õõ��������һ�ڵ㣬��¼���������´����Ӹ�����
        while (count > 0)
        {
            temp = curr->next; 
            curr->next = pre;      
            pre = curr;             
            curr = temp;           
            count--;               
        }
        last->next = pre;                //�����ε��õõ����������
        last = nextlast;                 //������һ����Ҫ�����ӵ�
    }
    if (10 % k != 0)          //�����ʣ��һ���֣���Ҫ������
    {
        nextlast->next = curr;
    }
    //���
    for (int i = 0; i < 10; i++)
    {
        cout << newhead->data << " ";
        newhead = newhead->next;
    }
    return 0;
}