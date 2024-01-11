//本程序所用分栈规则和老师课件中一样：
//(1) t<80 进 1 栈
//(2) 80 = < t <= 100 进 2 栈
//(3) t > 100 进 3 栈
#include <iostream>
using namespace std;
struct nums {
    int data;
    int next;
};
nums A[100];
int top = 3;
int max_size = 0;
void input();             //入栈
void share(void);         //初始化分享栈
void delt(int flag);      //对三栈中某一栈出栈，并释放空间
void show(void);          //打印出数组和三个栈顶，便于检查
int main()
{
    share();
    char want;
    do {
        cout << endl;
        cout << "入栈输入 r,出栈输入 o,退出程序输入q  ";
        cin >> want;
        if (want != 'r' && want != 'q' && want != 'o')
        {
            cout << "输入错误" << endl;
            continue;
        }
        if (want == 'r') //入栈
        {
            input();
            show();
        }
        else if (want == 'o') //出栈及释放空间
        {
            int flag = 0;
            cout << "请输入你想出栈的栈标号（1，2，3）  ";
            cin >> flag;
            if (flag != 1 && flag != 2 && flag != 3)
            {
                cout << "输入错误" << endl;
                continue;
            }
            delt(flag);
            show();
        }
    } while (want != 'q');
    return 0;
}
void share(void) //初始化分享栈
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
void input(void)      //入栈
{
    cout << "请输入正整数，最后以0结尾  ";
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
void delt(int flag)//对三栈中某一栈出栈，并释放空间
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
void show(void) //打印出数组和三个栈顶，便于检查
{
    cout << "现在数组内元素依次是：     ";
    for (int i = 0; i < max_size + 3; i++)
    {
        cout << A[i].data << " ";
    }
    cout << endl;
    cout << "现在各位置后继节点下标为： ";
    for (int i = 0; i < max_size + 3; i++)
    {
        cout << A[i].next << " ";
    }
    cout << endl;
}
