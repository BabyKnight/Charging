#ifndef __VTREE__
#define __VTREE__

#define MAX(a,b) ((a)>(b))?(a):(b)
#define MAX_LEN 100

typedef struct BTNode
{
    char data;
    struct BTNode *left;
    struct BTNode *right;
}BTNode;

typedef struct St
{
    BTNode *node;
    int lno;
}St;

#endif /*__VTREE__*/
