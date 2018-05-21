#include<stdio.h>
#include<stdlib.h>

void printList(int R[], int n)
{
    int i;
    for(i=0; i<n; i++)
        printf("%d ",R[i]);
    printf("\n");
}


void InsertSort(int R[], int n)
{
    int i, j, temp;
    for (i=1; i<=n-1; i++)
    {
        temp = R[i];
        j = i-1;
        while(i>=0 && temp<R[j])
        {
            R[j+1] = R[j];
            j--;
        }
        R[j+1] = temp;
    }

}

void BInsertSort(int R[], int n)
{
    int i, j;
    int low, high;
    int x;
    for(i=1; i<n-1; i++)
    {
        x = R[i];
        low = 0;
        high = i-1;
        while(low <= high)
        {
            int m = (low+high)/2;
            if(x<m)
                high=m-1;
            else
                low = m+1;
        }
        for(j=i-1; j>=high+1; --i)
        {
            R[j+1] = R[j];
        }
        R[j+1] = x;
    }
}

void BubbleSort(int R[], int n)
{
    int i, j, temp, flag;
    // index of data stored in array start from 0
    for(i=0; i<=n-2; i++)
    {
        flag = 0;
        for(j=n-1; j>=i+1; j--)
        {
            if(R[j] < R[j-1])
            {
                temp = R[j];
                R[j] = R[j-1];
                R[j-1] = temp;
                flag = 1;
            }
        }
        if(flag == 0)
            return;
    }
}


int main()
{
    int R[8] = {49, 38, 65, 97, 76, 13, 27, 49};
    int n = 8;
    printf("InsertSort: \n");
    printList(R,n);
    InsertSort(R,n);
    printList(R,n);

    // TODO looks like it's wrong, bcz it's not working 
    int R2[8] = {49, 38, 65, 97, 76, 13, 27, 49};
    printf("BInsertSort: \n");
    printList(R2,n);
    BInsertSort(R2,n);
    printList(R2,n);

    int R3[8] = {49, 38, 65, 97, 76, 13, 27, 49};
    printf("BubbleSort: \n");
    printList(R3, n);
    BubbleSort(R3, n);
    printList(R3, n);
}
