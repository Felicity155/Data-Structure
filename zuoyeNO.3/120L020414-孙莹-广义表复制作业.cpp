//测试用例1：(a,b,c,d,(a,b,c,d))     输出：(a,b,c,d,(a,b,c,d))
//测试用例2：(a,b,c,d,e)             输出：(a,b,c,d,e)
//测试用例3：((a,b,c,d))             输出：((a,b,c,d))
//测试用例4：((s,b,c,d),a,b,c)       输出：((s,b,c,d),a,b,c)
//测试用例5：(s,c,d,(d,f,g),(d))     输出：(s,c,d,(d,f,g),(d))
//测试用例6：((a,b),c,d,f,(g,h,s,f,(a,v)),e,t)   输出：((a,b),c,d,f,(g,h,s,f,(a,v)),e,t)
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
enum elemTag { ATOM, LIST };
struct  GLnode {
	elemTag Tag; //标志是原子还是子表 0:原子 1:子表
	union
	{
		char data; //原子结点值域
		struct //表结点指针域
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
	//A为原广义表，B为复制后的广义表 
	cout << "请输入广义表，示例：“(a,(b,c),d)”" << endl;
	cin >> S;

	//创建并打印原广义表
	Create_GList(A, S);
	Traverse_GList(A);
	cout << endl;

	//复制并打印复制得到的广义表
	GLnode* B;
	Copy_GList(A, B);
	Traverse_GList(B);

	return 0;
}



//创建广义表
void Create_GList(GLnode*& GL, string S)
{
	string hsub;
	if (S == "()") //S为空串
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
			hsub = Decompose(S); //从S中分离出表头串hsub
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

//复制广义表
void Copy_GList(GLnode* GL, GLnode*& T) //T复制GL
{
	//当表为空时，复制空表，否则先复制表头在复制表尾
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
//遍历输出
void Traverse_GList(GLnode* L)
{
	if (!L)       //如果是空表就输出"()"
		cout << "()";

	else          //如果遇到Tag=0的结点，则直接输出该结点的值，如果tag = 1，说明是一个子表，首先输出左括号，然后递归调用输出数据元素，并当表尾不空的时候输出逗号，最后输出右括号
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
//分离子串用，在CSDN上看到这种方法，在此借鉴
string Decompose(string& str)
{
	//将非空串str分割成2部分，hstr为第一个','之前的子串，str为后面的
	int n, i, k;
	string ch, hstr;
	n = str.length();
	for (i = 0, k = -1; i < n && (ch != "," || k != 0); i++)
	{
		//搜索最外层第一个逗号
		ch = str.substr(i, 1); //从第i个位置起读1个字符
		if (ch == "(")
			++k;
		else if (ch == ")")
			--k;
	}
	if (i < n)
	{
		hstr = str.substr(1, i - 2);//不要左括号，不要逗号，所以是i-2
		str = "(" + str.substr(i, n - i);
	}
	else
	{
		hstr = str.substr(1, n - 2);
		str = "";
	}
	return hstr;
}
