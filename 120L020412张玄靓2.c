#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
struct node
    {
        char data[4] ;
        struct node *next ;
    };
    typedef struct node STR ;
    STR *s;
void Sub(STR *s,int h,int e)
{
    STR *t;
    h--;
    e--;
    int i, j;
    t = s->next;
    for(i = 0; i < h/4; i++)
    {
        t = t->next;
    }
    j = h;
    while(j<=e && t != NULL)
    {
        printf("%c",t->data[j%4]);
        if(j%4==3)
        {
            t = t->next;
        }
        j++;
    }
}

int main()
{
    char c;
    int m, n;
    STR *p, *r, *q;
    printf("ÇëÊäÈë×Ö·û´®S\n");
    s = (STR*)malloc(sizeof(STR));
    r = s;
    int o;
    do
    {
        p = (STR*)malloc(sizeof(STR));
        for(o=0;o<4;o++)
        {
            scanf("%c",&c);
            p -> data[o] = c;
            if(c == '\n')
                break;
        }
        r->next = p;
        r = p;
    }while(c != '\n');
    p->next = NULL;
    printf("ÇëÊäÈëm,n\n");
    scanf("%d%d",&m,&n);
    Sub(s,m,n);
    p = s;
    while(p != NULL)
    {
        q = p;
        p = p->next;
        free(q);
    }
    return 0;
}
