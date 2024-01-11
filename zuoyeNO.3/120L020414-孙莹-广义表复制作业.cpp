//��������1��(a,b,c,d,(a,b,c,d))     �����(a,b,c,d,(a,b,c,d))
//��������2��(a,b,c,d,e)             �����(a,b,c,d,e)
//��������3��((a,b,c,d))             �����((a,b,c,d))
//��������4��((s,b,c,d),a,b,c)       �����((s,b,c,d),a,b,c)
//��������5��(s,c,d,(d,f,g),(d))     �����(s,c,d,(d,f,g),(d))
//��������6��((a,b),c,d,f,(g,h,s,f,(a,v)),e,t)   �����((a,b),c,d,f,(g,h,s,f,(a,v)),e,t)
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
enum elemTag { ATOM, LIST };
struct  GLnode {
	elemTag Tag; //��־��ԭ�ӻ����ӱ� 0:ԭ�� 1:�ӱ�
	union
	{
		char data; //ԭ�ӽ��ֵ��
		struct //����ָ����
		{
			GLnode* hp;
			GLnode* tp;
		}ptr;
	};
	friend class GList;
};
void Create_GList(GLnode*& GL, string S);
void Copy_GList(GLnode* GL, GLnode*& T);
void Traverse_GList(GLnode* L);
string Decompose(string& str);


int main()
{
	GLnode* A = NULL;
	string S;
	//AΪԭ�����BΪ���ƺ�Ĺ���� 
	cout << "����������ʾ������(a,(b,c),d)��" << endl;
	cin >> S;

	//��������ӡԭ�����
	Create_GList(A, S);
	Traverse_GList(A);
	cout << endl;

	//���Ʋ���ӡ���Ƶõ��Ĺ����
	GLnode* B;
	Copy_GList(A, B);
	Traverse_GList(B);

	return 0;
}



//���������
void Create_GList(GLnode*& GL, string S)
{
	string hsub;
	if (S == "()") //SΪ�մ�
	{
		GL = NULL;
	}
	else
	{

		GL = new GLnode;
		if (S.length() == 1)
		{
			GL->Tag = ATOM;
			GL->data = S[0];
		}
		else
		{
			GL->Tag = LIST;
			hsub = Decompose(S); //��S�з������ͷ��hsub
			Create_GList(GL->ptr.hp, hsub);
			if (S.empty())
			{
				GL->ptr.tp = NULL;
			}
			else
			{
				Create_GList(GL->ptr.tp, S);
			}
		}
	}
}

//���ƹ����
void Copy_GList(GLnode* GL, GLnode*& T) //T����GL
{
	//����Ϊ��ʱ�����ƿձ������ȸ��Ʊ�ͷ�ڸ��Ʊ�β
	if (!GL)
		T = NULL;
	else
	{
		T = new GLnode;
		T->Tag = GL->Tag;
		if (GL->Tag == ATOM)
			T->data = GL->data;
		else
		{
			Copy_GList(GL->ptr.hp, T->ptr.hp);
			Copy_GList(GL->ptr.tp, T->ptr.tp);
		}
	}
}
//�������
void Traverse_GList(GLnode* L)
{
	if (!L)       //����ǿձ�����"()"
		cout << "()";

	else          //�������Tag=0�Ľ�㣬��ֱ������ý���ֵ�����tag = 1��˵����һ���ӱ�������������ţ�Ȼ��ݹ�����������Ԫ�أ�������β���յ�ʱ��������ţ�������������
	{
		if (L->Tag == ATOM)
			cout << L->data;
		else
		{
			GLnode* p = NULL;
			cout << '(';
			p = L;
			while (p)
			{
				Traverse_GList(p->ptr.hp);
				p = p->ptr.tp;
				if (p)
					cout << ',';
			}
			cout << ')';
		}
	}
}
//�����Ӵ��ã���CSDN�Ͽ������ַ������ڴ˽��
string Decompose(string& str)
{
	//���ǿմ�str�ָ��2���֣�hstrΪ��һ��','֮ǰ���Ӵ���strΪ�����
	int n, i, k;
	string ch, hstr;
	n = str.length();
	for (i = 0, k = -1; i < n && (ch != "," || k != 0); i++)
	{
		//����������һ������
		ch = str.substr(i, 1); //�ӵ�i��λ�����1���ַ�
		if (ch == "(")
			++k;
		else if (ch == ")")
			--k;
	}
	if (i < n)
	{
		hstr = str.substr(1, i - 2);//��Ҫ�����ţ���Ҫ���ţ�������i-2
		str = "(" + str.substr(i, n - i);
	}
	else
	{
		hstr = str.substr(1, n - 2);
		str = "";
	}
	return hstr;
}
