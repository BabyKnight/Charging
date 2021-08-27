#ifndef __VSTRUCT__
#define __VSTRUCT__

typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode;

typedef struct DLNode
{
    int data;
    struct DLNode *prior;
    struct DLNode *next;
}DLNode;

#endif /*__VSTRUCT__*/
