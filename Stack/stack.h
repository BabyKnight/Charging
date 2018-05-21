#ifndef __VSTACK__
#define __VSTACK__

#define MAX 100

typedef struct
{
    int data[MAX];
    int top;
}sStack;

typedef struct
{
    int data;
    struct LNode *next;
}LNode;


#endif /*__STACK__*/
