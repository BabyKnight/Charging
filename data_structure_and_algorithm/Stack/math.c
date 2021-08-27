#include <stdio.h>
#define MAX 100

int operate(int a, char op, int b)
{
    if(op == '+')
        return a+b;
    if(op == '-')
        return a-b;
    if(op == '*')
        return a*b;
    if(op == '/')
        if(b == 0)
        {
            printf("Operation error, a/b  b can not be 0\n");
            return 0;
        }
        else
            return a/b;
}


int main()
{
    char exp[] = "1234*++5/";
    int i,a,b,res;
    int st[MAX];
    int top=-1;
    char op;

    for(i=0; exp[i]!='\0';i++)
    {
        if(exp[i] >= '0' && exp[i] <= '9' )
        {
            st[++top] = exp[i] - '0';
        }
        else
        {
            op = exp[i];
            b = st[top--];
            a = st[top--];
            res = operate(a, op, b);
            st[++top] = res;
        }
    }
    printf("%d\n", st[top]);
}
