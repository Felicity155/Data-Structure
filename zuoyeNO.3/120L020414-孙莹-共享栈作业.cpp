//���������÷�ջ�������ʦ�μ���һ����
//(1) t<80 �� 1 ջ
//(2) 80 = < t <= 100 �� 2 ջ
//(3) t > 100 �� 3 ջ
#include <iostream>
using namespace std;
struct nums {
    int data;
    int next;
};
nums A[100];
int top = 3;
int max_size = 0;
void input();             //��ջ
void share(void);         //��ʼ������ջ
void delt(int flag);      //����ջ��ĳһջ��ջ�����ͷſռ�
void show(void);          //��ӡ�����������ջ�������ڼ��
int main()
{
    share();
    char want;
    do {
        cout << endl;
        cout << "��ջ���� r,��ջ���� o,�˳���������q  ";
        cin >> want;
        if (want != 'r' && want != 'q' && want != 'o')
        {
            cout << "�������" << endl;
            continue;
        }
        if (want == 'r') //��ջ
        {
            input();
            show();
        }
        else if (want == 'o') //��ջ���ͷſռ�
        {
            int flag = 0;
            cout << "�����������ջ��ջ��ţ�1��2��3��  ";
            cin >> flag;
            if (flag != 1 && flag != 2 && flag != 3)
            {
                cout << "�������" << endl;
                continue;
            }
            delt(flag);
            show();
        }
    } while (want != 'q');
    return 0;
}
void share(void) //��ʼ������ջ
{
    int i;
    for (i = 0; i < 3; i++)
    {
        A[i].next = 0;
    }
    for (i = 3; i < 99; i++)
    {
        A[i].next = i + 1;
        A[99].next = 0;
    }
}
void input(void)      //��ջ
{
    cout << "�������������������0��β  ";
    int tmp;
    do
    {
        cin >> tmp;
        if (tmp != 0)
        {
            while (A[top].data != 0)
            {
                top++;
            }
            A[top].data = tmp;
            if (tmp < 80)
            {
                A[top].next = A[0].next;
                A[0].next = top;
            }
            else if (tmp > 100)
            {
                A[top].next = A[2].next;
                A[2].next = top;
            }
            else
            {
                A[top].next = A[1].next;
                A[1].next = top;
            }
            top++;
            max_size++;
        }
    } while (tmp != 0);
}
void delt(int flag)//����ջ��ĳһջ��ջ�����ͷſռ�
{
    flag--;
    if (A[flag].next != 0)
    {
        int free = A[flag].next;
        int temp = A[flag].next;
        A[flag].next = A[A[flag].next].next;
        A[temp].data = 0;
        A[temp].next = 0;
        top = free;
    }

}
void show(void) //��ӡ�����������ջ�������ڼ��
{
    cout << "����������Ԫ�������ǣ�     ";
    for (int i = 0; i < max_size + 3; i++)
    {
        cout << A[i].data << " ";
    }
    cout << endl;
    cout << "���ڸ�λ�ú�̽ڵ��±�Ϊ�� ";
    for (int i = 0; i < max_size + 3; i++)
    {
        cout << A[i].next << " ";
    }
    cout << endl;
}
