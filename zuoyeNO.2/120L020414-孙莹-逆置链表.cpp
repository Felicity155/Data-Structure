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
    //创建链表
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
    //获得K值
    int k;
    do {
        cout << "请输入K" << endl;
        cin >> k;
    } while (k > 10);
    int count;
    Num* pre;
    Num* curr;
    Num* last;
    Num* nextlast = head;
    Num* temp;
    //开始第一次倒置
    count = k;
    pre = nullptr;
    curr = head;
    last = head;                 //两次倒置的连接点，记录下来便于下次连接链表
    while (count > 0)
    {
        temp = curr->next; //暂时储存下一个节点
        curr->next = pre;       //当前节点指向上一个节点
        pre = curr;             //重置下一次操作的“上一个节点”
        curr = temp;            //“当前节点”向下进行
        count--;                //count计数;
    }
    Num* newhead = pre;         //第一次倒置会得到头节点，记录下来
    //开始进行后面的倒置
    for (int j = 0; j < 10 / k - 1; j++)
    {
        count = k;
        pre = nullptr;
        nextlast = curr;                 //下一次倒置得到链表的上一节点，记录下来便于下次连接各链表
        while (count > 0)
        {
            temp = curr->next; 
            curr->next = pre;      
            pre = curr;             
            curr = temp;           
            count--;               
        }
        last->next = pre;                //将本次倒置得到的链表接上
        last = nextlast;                 //重置下一次需要的连接点
    }
    if (10 % k != 0)          //如果还剩下一部分，需要连接上
    {
        nextlast->next = curr;
    }
    //输出
    for (int i = 0; i < 10; i++)
    {
        cout << newhead->data << " ";
        newhead = newhead->next;
    }
    return 0;
}