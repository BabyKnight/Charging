#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

/*
 * This is a demo BTree
 * */
BTNode *sampleTree()
{
    printf("This is a Sample Binary Tree:\n");
    printf("      * \n");
    printf("   /     \\\n");
    printf("  -       /\n");
    printf(" / \\     / \\\n");
    printf("a   +   d   e\n");
    printf("    /\\\n");
    printf("   b  c\n");
    BTNode *t1, *t2, *t3, *t4, *t5, *t6, *t7, *t8, *t9;
    t1 = (BTNode*)malloc(sizeof(BTNode));
    t1->data = '*';
    t2 = (BTNode*)malloc(sizeof(BTNode));
    t2->data = '-';
    t3 = (BTNode*)malloc(sizeof(BTNode));
    t3->data = '/';
    t4 = (BTNode*)malloc(sizeof(BTNode));
    t4->data = 'a';
    t5 = (BTNode*)malloc(sizeof(BTNode));
    t5->data = '+';
    t6 = (BTNode*)malloc(sizeof(BTNode));
    t6->data = 'd';
    t7 = (BTNode*)malloc(sizeof(BTNode));
    t7->data = 'e';
    t8 = (BTNode*)malloc(sizeof(BTNode));
    t8->data = 'b';
    t9 = (BTNode*)malloc(sizeof(BTNode));
    t9->data = 'c';

    t1->left = t2;
    t1->right = t3;
    t2->left = t4;
    t2->right = t5;
    t3->left = t6;
    t3->right = t7;
    t4->left = t4->right =NULL;
    t5->left = t8;
    t5->right = t9;
    t6->left = t6->right =NULL;
    t7->left = t7->right =NULL;
    t8->left = t8->right =NULL;
    t9->left = t9->right =NULL;

    BTNode *t = t1;
    return t;
}


void preorder(BTNode *p)
{
    if(p!=NULL)
    {
        printf("%c ", p->data);
        preorder(p->left);
        preorder(p->right);
    }

}

void inorder(BTNode *p)
{
    if(p!=NULL)
    {
        inorder(p->left);
        printf("%c ", p->data);
        inorder(p->right);
    }
}

void postorder(BTNode *p)
{
    if(p!=NULL)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%c ", p->data);
    }
}

int getDepth(BTNode *p)
{
    int ld, rd;
    if(p==NULL)
    {
        return 0;
    }
    else
    {
        ld = getDepth(p->left);
        rd = getDepth(p->right);
        printf("[%c]  depth id (%d), ld is %d, rd is %d\n", p->data, (MAX(ld,rd)+1), ld, rd);
        //return (MAX(ld, rd) + 1); 
        return (ld>rd?ld:rd)+1;
    }
}

void level(BTNode *p)
{
    int front, rear;
    BTNode *que[MAX_LEN];
    front = rear = 0;
    BTNode *q;
    if(p!=NULL)
    {
        rear = (rear+1) % MAX_LEN;
        que[rear] = p;
        while(front!=rear)
        {
            front = (front+1) % MAX_LEN;
            q = que[front];
            printf("%c ", q->data);
            if(q->left != NULL)
            {
                rear = (rear+1) % MAX_LEN;
                que[rear] = q->left;
            }
            if(q->right != NULL)
            {
                rear = (rear+1) % MAX_LEN;
                que[rear] = q->right;
            }
        }
    }
}

int MaxLnoNode(BTNode *p)
{
    St que[MAX_LEN];
    BTNode *q;
    int rear, front;
    int Lno;
    int max, i, j, n;
    front = rear = 0;
    if(p != NULL)
    {
        // push all node into  queue with level no.
        rear++;
        que[rear].node = p;
        que[rear].lno = 1;
        while(front!=rear)
        {
            front++;
            q = que[front].node;
            Lno = que[front].lno;
            if(q->left!=NULL)
            {
                rear++;
                que[rear].node = q->left;
                que[rear].lno = Lno++;
            }
            if(q->right!=NULL)
            {
                rear++;
                que[rear].node = q->right;
                que[rear].lno = Lno++;
            }
        }
        
        max = 0;
        for(i=0; i<=Lno; i++)
        {
            n = 0;
            for(j=0; j<=rear; j++)
            {
                if(que[j].lno == i)
                    n++;
            } 
            if(max < n)
                max = n;
        }
        return max;   
    }
    else
        return 0;
}


int main()
{
    printf("Load a sample binary tree\n");
    BTNode * p = sampleTree(); 
    printf("preorder is :\n");
    preorder(p);
    printf("\ninorder id :\n");
    inorder(p);
    printf("\npostorder is :\n");
    postorder(p);
    printf("\n");
    int dep = getDepth(p);
    printf("Depth of tree is [%d]\n", dep);
    printf("Level trav is: \n");
    level(p);
    printf("\n");
    int max_no = MaxLnoNode(p);
    printf("Max no of level is %d\n", max_no);
}

