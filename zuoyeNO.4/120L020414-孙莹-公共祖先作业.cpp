// 一棵二叉树按照顺序存储结构进行存储，本程序可求任两个结点的最近的公共祖先
//输入示例1：[a,b,c,d,e,f,g，#，#,h,i]
//此示例的二叉树为：
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

    //输入二叉树
    cout << "请输入二叉树【形如[a,b,c,d,e,f,g,#,#,h,i]，请不要有重复元素】:" << endl;
    cout << "此示例二叉树图为：" << endl;
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
    cout << "请输入你想要查找的两个元素" << endl;
    char a, b;
    int i = 0, j = 0, flag = 1;
    cin >> a >> b;

    //找到元素对应的编号
    while (tree[flag] != ']')
    {
        if (tree[flag] == a) i = flag;
        if (tree[flag] == b) j = flag;
        flag++;
    }
    if (i == 0 || j == 0)
    {
        cout << "找不到此元素";
        return 0;
    }

    //输出祖先元素
    int ancester = theancester(i, j);
    cout << "此两元素的公共祖先为：" << tree[ancester];
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