// һ�ö���������˳��洢�ṹ���д洢�������������������������Ĺ�������
//����ʾ��1��[a,b,c,d,e,f,g��#��#,h,i]
//��ʾ���Ķ�����Ϊ��
//                 a
//               /   \
//              b     c
//            /   \  /  \
//           d    e  f    g
//               / \ 
//              h   i
#include <iostream>
using namespace std;

int theancester(int i, int j);
int main()
{
    char tree[100];
    char temp;
    int k = 0;

    //���������
    cout << "�����������������[a,b,c,d,e,f,g,#,#,h,i]���벻Ҫ���ظ�Ԫ�ء�:" << endl;
    cout << "��ʾ��������ͼΪ��" << endl;
    cout << "              a" << endl;
    cout << "            /   \\" << endl;
    cout << "           b     c" << endl;
    cout << "         /  \\   / \\" << endl;
    cout << "        d    e f   g" << endl;
    cout << "            / \\ " << endl;
    cout << "           h   i" << endl;
    do {
        cin >> temp;
        if (temp != ',')
        {
            tree[k] = temp;
            k++;
        }
    } while (tree[k - 1] != ']');
    cout << "����������Ҫ���ҵ�����Ԫ��" << endl;
    char a, b;
    int i = 0, j = 0, flag = 1;
    cin >> a >> b;

    //�ҵ�Ԫ�ض�Ӧ�ı��
    while (tree[flag] != ']')
    {
        if (tree[flag] == a) i = flag;
        if (tree[flag] == b) j = flag;
        flag++;
    }
    if (i == 0 || j == 0)
    {
        cout << "�Ҳ�����Ԫ��";
        return 0;
    }

    //�������Ԫ��
    int ancester = theancester(i, j);
    cout << "����Ԫ�صĹ�������Ϊ��" << tree[ancester];
    return 0;
}
int theancester(int i, int j)
{
    while (i != j)
    {
        if (i > j) i = i / 2;
        else j = j / 2;
    }
    return i;

}