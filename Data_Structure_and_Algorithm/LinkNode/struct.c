#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

void InitList(LNode *L)
{
   /* Create Single link list
    * by stdin with numbers
    * input type: int
    * */
    int data, count=0;
    LNode *t, *p;
    printf("Initinal a Single link list.\n");
    printf("Please input numbers:\n");

    // create head node of single link list
    L->next = NULL;
    t = L;

    // input with unknow numbers of val
    while(1 == scanf("%d",&data ))
    {
        p = (LNode*)malloc(sizeof(LNode));
        p->data = data;
        p->next = t->next;
        t->next = p;
        ++count;
    }

    printf("Initinal Single link list DONE!\n");
    printf("Total created node is [%d].\n", count);
}


void InitListFromTail(LNode *L)
{
   /* Create Single link list
    * by stdin with numbers
    * input type: int
    * */
    int data, count=0;
    LNode *t, *p;
    printf("Initinal a Single link list.\n");
    printf("Please input numbers:\n");

    // create head node of single link list
    L->next = NULL;
    t = L;

    // input with unknow numbers of val
    while(1 == scanf("%d",&data ))
    {
        p = (LNode*)malloc(sizeof(LNode));
        p->data = data;
        t->next = p;
        t = t->next;
        ++count;
    }
    t->next = NULL;

    printf("Initinal Single link list DONE!\n");
    printf("Total created node is [%d].\n", count);
}


void MergeList(LNode *a, LNode *b, LNode *c)
{
    /* Merge two sorted list
     * */
    LNode *h_a = a->next;
    LNode *h_b = b->next;
    LNode *temp;
    //c = a;
    c->next = NULL;
    temp = c;
    while(h_a!=NULL && h_b!=NULL)
    {
        if(h_a->data < h_b->data)
        {
            temp->next = h_a;
            temp = temp->next;
            h_a = h_a->next;
        }
        else
        {
            temp->next = h_b;
            temp = temp->next;
            h_b = h_b->next;
        }
    }
}


int SearchAndDelete(LNode *L, int val)
{
    LNode *p, *q;
    p = L;
    while(p->next != NULL)
    {
        if(p->next->data == val)
            break;
        p = p->next;
    }
    if(p->next == NULL && p->data != val)
        return 0;
    else
        q = p->next;
        p->next = p->next->next;
        free(q); 
        return 1;
}


void PrintList(LNode *L)
{
    /* Print data in Single link list
     * */
    LNode *p = L->next;
    int i = 0;
    while(p)
    {
        printf("Node %d:\n", i++);
        printf("    Address is [ %p ]\n", p);
        printf("    Data is [ %d ]\n", p->data);
        printf("    Next is [ %p ]\n", p->next);
        p = p->next;
    }
}


int main()
{
    LNode *a, *b, *c;
    a = (LNode*)malloc(sizeof(LNode));
    b = (LNode*)malloc(sizeof(LNode));
    c = (LNode*)malloc(sizeof(LNode));
    InitList(a);
    PrintList(a);
    InitListFromTail(b);
    PrintList(b);

    MergeList(a, b, c);
    PrintList(c);

    printf("Please input a number to delete:");
    int del;
    scanf("%d", &del);
    int ret = SearchAndDelete(c,del);
    printf("%s\n", ret ? "True": "False");
    PrintList(c);
    printf("Please input a number to delete:");
    scanf("%d", &del);
    ret = SearchAndDelete(c,del);
    printf("%s\n", ret ? "True": "False");
    PrintList(c);

}
