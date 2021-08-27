#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int initSequenceStack(sStack *s)
{
    s->top = -1;
}

int SSPush(sStack *s, int val)
{
    if(s->top < MAX-1)
    {
        s->top++;
        s->data[s->top] = val;
        return 1;
    }
    else
        return 0;
}

void SSPrint(sStack *s)
{
    int i = s->top;
    while(i != -1)
    {
        printf("%d  [%p]\n", s->data[i], s->data[i]);
        i--;
    }
}


void SSPop(sStack *s)
{
    printf("Starting pop element...\n");
    while(s->top != -1)
    {
        printf("%d\n", s->data[s->top--]);
    }
}

void initLStack(LNode *ls)
{
    ls = NULL;
}

void LSPush(LNode *ls, int val)
{
    LNode *p = (LNode*)malloc(sizeof(LNode));
    p->data = val;

    p->next = ls->next;
    ls = p;
}

void LSPrint(LNode *ls)
{
    LNode *t = ls;
    while(t != NULL)
    {
        printf("%d [%p]\n", t->data, t);
        t = t->next;
    }
}


void LSPop(LNode *ls)
{
    LNode *t = ls;
    while(ls != NULL)
    {
       t = ls;
       printf("%d\n", t->data);
       ls = t->next;
       free(t);
    }
}

int main()
{
    int val;

    printf("Sequence stack...\n");
    printf("Please input val for Sequence stack:\n");
    sStack *st = (sStack*)malloc(sizeof(sStack));
    initSequenceStack(st);
    while (1==scanf("%d", &val))
    {
        SSPush(st, val);
    }
    SSPrint(st);
    SSPop(st);

    printf("Link stack...\n");
    LNode *ls = (LNode*)malloc(sizeof(LNode));
    initLStack(ls);
    printf("Please input val for Link stack:\n");
    while (1==scanf("%d",&val))
    {
        LSPush(ls, val);
    }
    LSPrint(ls);
    LSPop(ls);
}
