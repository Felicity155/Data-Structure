#include <iostream>
using namespace std;
struct node {
	char data[4];
	node* next;
};

int index(char t[4], node* loc);
void substr(node* head, int m, int n);

int main()
{
	char t[4];        //���Ƚ��ַ���
	cout << "����5������Ϊ4���ַ������Կո�ָ�" << endl;
	node* head = nullptr;
	head = new node;
	node* p = head;
	for (int i = 0; i < 5; i++)
	{
		node* newhead = new node;
		for (int j = 0; j < 4; j++)
		{
			char temp;
			cin >> temp;
			newhead->data[j] = temp;
		}
		newhead->next = nullptr;
		p->next = newhead;
		p = newhead;
	}
	cout << "��������ҵ��ַ���(����Ϊ4)" << endl;
	for (int i = 0; i < 4; i++)
	{
		cin >> t[i];
	}
	int find;
	find = index(t, head);
	if (find == -1)
	{
		cout << "δ�ҵ�" << endl;
	}
	else
	{
		cout << "λ����" << find + 1 << endl;
	}
	int m, n;
	cout << "���������Ӵ��Ŀ�ͷ�ͽ�β��1~5��,��ͷ��β" << endl;
	cin >> m >> n;
	m--; n--;
	substr(head, m, n);
	return 0;
}
int index(char t[4], node* loc)
{
	for (int i = 0; i < 5; i++)
	{
		loc = loc->next;
		int flag = 1;
		for (int j = 0; j < 4; j++)
		{
			if (t[j] != loc->data[j])
				flag = 0;
		}
		if (flag == 1)
		{
			return i;
		}
	}
	return -1;
}
void substr(node* head, int m, int n)
{
	for (int i = 0; i < 5; i++)
	{
		head = head->next;
		if (i >= m && i < n)
		{
			cout << head->data[0] << head->data[1] << head->data[2] << head->data[3] << "->";
		}
		else if (i == n)
		{
			cout << head->data[0] << head->data[1] << head->data[2] << head->data[3];
		}

	}
}