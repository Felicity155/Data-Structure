// ��������CSDN�ϡ�[��ɢ�¼�ģ��] ���д���ģ�⡷���ģ���ʳ���۷�����ת��Ϊ��ɢ�¼�ģ�⣬�������ͬѧ�ǵ�ʳ�õȴ����򷹡��Է����¼��б�Ȼ��ʱ����������¼���
//���У����Ǹ�����Ӧ�����ݽṹ�ص㣬�ô����Ŷӳ���Ϊ���Ƚ��ȳ����Ķ��У��¼������Ϊ������в����ɾ������������
//�����������ڵ����ͬѧ���1~3min,һ��ͬѧ����Ҫ1~5min,�Է���Ҫ1~15min.
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include<time.h>

using namespace std;

#define MAX 10000
#define WINDOWS_NUM 4   //ʳ����4������

//�¼�(��������Ŷӣ��򷹣��Է�)
//�¼��б���ͷ���ĵ�����
typedef struct {
    long occur_time;         //�¼�����ʱ���
                             //Ϊ������㱾������ʱ�䶼Ϊ��ʳ�ÿ��ŵ�ʱ�䡣���ʱ���д���Ϊʱ�̡�
    int type;                //0:Ԥ����һ��ͬѧ��1��2��3��4�ֱ�Ϊ��1��2��3��4���ڴ򷹣�
}LElemType;
typedef LElemType Event;     //�����¼�
typedef struct LNode {
    Event data;
    struct LNode* next;
}LNode,*LinkList;
typedef LinkList EventList;  //�����¼�����������

//ͬѧ
typedef struct {
    long arrival_time;       //����ʳ�õ�ʱ��
    long get_time;           //�򷹵�ʱ��
    long eat_time;           //�Է���ʱ��
    int id;                  //�ڼ���ͬѧ
}SElemType;
typedef SElemType Student;   //����ͬѧ

//���ڶ���
typedef struct SNode {
    SElemType data;
    struct SNode* next;
}SNode ,*SueuePtr;
typedef struct {
    SueuePtr front;           //�ŶӵĶ�ͷ
    SueuePtr rear;            //�ŶӵĶ�β
}LinkSueue;
typedef LinkSueue StudentSueue;//�����ŶӶ���

//�¼���صĴ���
void LunchSimulation();           //ģ��ʳ��
void OpenLunch();                 //ʳ�ÿ���
void CloseLunch();                //ʳ�ù���
int GetMin(LinkSueue q[]);        //�ҵ��Ŷ������ٵĶ���
void StudentArriving();           //Ԥ��ͬѧ����
void StudentDeparture();          //ͬѧ�뿪

//������
void InitList(LinkList* pL);    //��ʼ������
int ListEmpty(LinkList L);      //�ж������Ƿ�Ϊ��
void OrderInsert(LinkList* pL, LElemType en);  //�����¼����
void DelFirst(LinkList* pL, LElemType* e);      //ɾ���¼����

//���д���
void InitSueue(LinkSueue* Q);   //��ʼ������
int DelSueue(LinkSueue* pQ, SElemType* e);     //ɾ��ͬѧ���
int EnSueue(LinkSueue* pQ, SElemType e);       //����ͬѧ���
int SueueLength(LinkSueue Q);                  //�鿴���г���

//ȫ�ֱ���
int total_time = 0, student_num = 0;    //�ۼ�ͬѧ��ʳ��ʱ�䣬ͬѧ��Ŀ
EventList eventList;                    //�¼���
Event event;                            //�¼�
StudentSueue windows[WINDOWS_NUM + 1];  //�ĸ�ʳ�ô��ڵĶ��У�1��2��3��4
Student student;                        //ѧ��
int close_time = 120;                   //ʳ�ÿ�������Сʱ��120����

//������
int main()
{
    srand(time(NULL));                  //������ӣ�����ÿ�εõ������������ͬ
    cout << "ȥʳ�ð�������ʳ��->�Ŷ�->��->�Է�\n�����������ڵ����ͬѧ���1~3min,һ��ͬѧ����Ҫ1~5min,�Է���Ҫ1~15min.\n";
    LunchSimulation();                    //ģ��ʳ��
    return 0;
}

//ģ��ʳ��
void LunchSimulation() {
    OpenLunch();                         //ʳ�ÿ���
    while (!ListEmpty(eventList)){      //�������¼�û�д�����
        DelFirst(&eventList, &event);    //��Ϊ������ʱ������ɾ����һ���¼����
        if (event.type == 0)
        {
            StudentArriving();           //ģ����һ��ͬѧ����
        }
        else
        {
            StudentDeparture();          //���˴��극�ˣ��뿪����
        }
     }
    CloseLunch();                        //ʳ�ù���
}

//ʳ�ÿ���
void OpenLunch() {
    int i = 0;
    total_time = 0;                      //��ʼ��ʱ
    student_num = 0;                     //��ʼ��ѧ����
    InitList(&eventList);                //��ʼ���¼�����
    event.occur_time = 0;
    event.type = 0;                      //��ʼ���¼���Ϣ
    OrderInsert(&eventList, event);      //�����¼���Ϣ��Ҫ��ʱ��˳��
    InitSueue(&windows[1]);
    InitSueue(&windows[2]);
    InitSueue(&windows[3]);
    InitSueue(&windows[4]);              //��ʼ��ʳ�ô���
    printf("                      ####��ʼģ��ʳ���۷�����####\n");
}

//ʳ�ù���
void CloseLunch() {
    float mean_time = float(total_time) / student_num;
    printf("\n �Է�ͬѧ����Ϊ%d ,��ʳ���ۼ�ʱ��Ϊ%dmin,ƽ����ʳ��ʱ��Ϊ%1fmin\n", student_num, total_time,mean_time);
}

//Ԥ��ͬѧ����
void StudentArriving() {
    long gettime, intertime, eattime;
    int minWindow;
    student_num++;               //ѧ����Ŀ��һ

    //��ʼ���������ͬѧ��Ϣ
    intertime = rand() % 3 + 1;  //ͬѧ������ʱ��1~3min
    gettime = rand() % 5 + 1;    //������ʱ��1~5min
    eattime = rand() % 15 + 1;   //�Է�����ʱ��1~15min
    student.id = student_num;    //�ڼ�������
    student.arrival_time = event.occur_time + intertime;
                                 //����ʱ���
    student.get_time = gettime;  //��ʱ��
    student.eat_time = eattime;  //�Է�ʱ��
    if (student.arrival_time >= close_time) {
        printf("��%d��ͬѧ��%d:%d����ʳ���ѹ��ţ����Բ��Ϸ�\n", student.id, 11 + student.arrival_time / 60, student.arrival_time % 60);
        //�������ʱ���ѹ��ţ���Բ��Ϸ������ý������ʱ������
    }
    else {
        //�������ʱ��û���ţ����Կ�ʼ�ȴ�����������ŶӶ���
        minWindow = GetMin(windows);                 //�ҵ���ʱ��̵Ķ�
        EnSueue(&windows[minWindow], student);       //ȥ��̶��Ŷ�

        //��Ҫ�Ѹ�ͬѧ���극ʱ������¼�����
        event.occur_time = student.arrival_time + gettime;//���극��ʱ��
        event.type = minWindow;
        if (SueueLength(windows[minWindow]) == 1)
            OrderInsert(&eventList, event);              //ֻ��һ�����Ŷӣ��������뿪��
        printf("��%d��ͬѧ��%d:%d�������%d�����Ŷӣ���Ҫ%dmin�򷹣�%dmin�Է� \n", student.id, 11 + student.arrival_time / 60, student.arrival_time % 60, minWindow, student.get_time, student.eat_time);

        //����Ԥ����һ��ͬѧ����
        event.occur_time = student.arrival_time;
        event.type = 0;
        if (event.occur_time < close_time) //�ŵ�����û���ţ�����
            OrderInsert(&eventList, event);
    }
}

//���극�ˣ�ͬѧ�뿪����
void StudentDeparture() {
    int type = event.type;                  //�ڼ�������
    SNode* p;
    SElemType qe;
    DelSueue(&windows[type], &student);     //���극��ͬѧ
    printf("       %d����,%d��ͬѧ�򷹣�",type,student.id);
    if (event.occur_time > close_time) {
        printf("�����ŵ�����ʱ��ʳ�ô����ѹر��ˣ���û���Ϸ�\n");
        total_time += close_time - student.arrival_time;    //���ͬѧû�򷹣��������ĵȴ�ʱ��ҲҪ����
    }
    else {
        printf("%d:%d���극,Ȼ���ֻ���%dminʱ��Է�\n", 11 + event.occur_time / 60, event.occur_time % 60, student.eat_time);
        total_time += event.occur_time - student.arrival_time + student.eat_time;    //��ʱ���ۼ���
        if (SueueLength(windows[type])) {                                            //���л����ˣ�������

            p = windows[type].front->next;
            qe = p->data;
            student.arrival_time = qe.arrival_time;
            student.get_time = qe.get_time;
            student.eat_time = qe.eat_time;
            event.occur_time += student.get_time;
            event.type = type;
            OrderInsert(&eventList, event);
        }
    }
}

//���Ŷ���̵Ĵ���
int GetMin(LinkSueue q[]) {
    int  k, min;
    int cnt;
    SNode* p;

    min = MAX;
    for (int i = 1; i <= WINDOWS_NUM; i++) {
        if (q[i].front == q[i].rear) {
            cnt = 0;                 //�ô���û����
        }
        else {
            for (cnt = 1, p = q[i].front->next; p != q[i].rear; p = p->next)
            {
                cnt++;
            }
        }
        if (min > cnt) {
            min = cnt;
            k = i;
        }
    }
    return k;
}

//������
//�����ʼ��
void InitList(LinkList* pL) {
    *pL = (LNode*)malloc(sizeof(LNode));
    if (!*pL)  exit(0);
    (*pL)->next = NULL;
}
//�ж�����Ϊ��
int ListEmpty(LinkList L) {
    if (L->next == NULL) return 1;
    else return 0;
}
//������ ����Ҫ���¼�ʱ��(occur_time)����
void OrderInsert(LinkList* pL, LElemType en) {
    LNode* p, * q, * s;
    for (p = *pL, q = p->next; q && q->data.occur_time < en.occur_time; p = q, q = p->next);
    //��ʱ���ҵ�����λ��
    s = (LNode*)malloc(sizeof(LNode));
    if (!s)  exit(0);
    s->data.type = en.type;
    s->data.occur_time = en.occur_time;
    p->next = s;
    s->next = q;
}
//ɾ���¼����
void DelFirst(LinkList* pL, LElemType* e) {
    LNode* p;
    p = (*pL)->next;
    (*pL)->next = p->next;
    e->occur_time = p->data.occur_time;
    e->type = p->data.type;
    free(p);
}

//���д���
//���г�ʼ��
void InitSueue(LinkSueue* Q) {
    SNode* p;
    p = (SNode*)malloc(sizeof(SNode));
    Q->front = p;
    Q->rear = p;
    Q->front->next = nullptr;
}
//���Ӳ������Ƚ��ȳ����Ӷ��׿�ʼ
int DelSueue(LinkSueue* pQ, SElemType* e) {
    SNode* p;
    if((*pQ).front == (*pQ).rear) return 0;
    p = (*pQ).front->next;
    e->arrival_time = p->data.arrival_time;
    e->get_time = p->data.get_time;
    e->eat_time = p->data.eat_time;
    e->id = p->data.id;

    (*pQ).front->next = p->next;
    if ((*pQ).rear == p)     //���ɾ�������Ϊ�գ���Ҫ����һ�£��Ա����ʱ���
        (*pQ).rear = (*pQ).front;
    free(p);
    return 1;                //ɾ���ɹ�
}
//��Ӳ������ڶ�β��
int EnSueue(LinkSueue* pQ, SElemType e) {
    SNode* p;
    p = (SNode*)malloc(sizeof(SNode));
    if (!p) exit(0);
    p->data.arrival_time = e.arrival_time;
    p->data.get_time = e.get_time;
    p->data.eat_time = e.eat_time;
    p->data.id = e.id;

    p->next = NULL;
    (*pQ).rear->next = p;
    (*pQ).rear = p;
    return 1;
}
//�鿴���г���
int SueueLength(LinkSueue Q) {
    int count = 0;
    SNode* p;
    if (Q.front == Q.rear) count = 0;
    else {
        p = Q.front;
        while (p != Q.rear) {
            count++;
            p = p->next;
        }
    }
    return count;
}
