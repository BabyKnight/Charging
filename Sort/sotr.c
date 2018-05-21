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







int main()
{
    int R[8] = {49, 38, 65, 97, 76, 13, 27, 49};
    int n = 8;
    printf("InsertSort: \n");
    printList(R,n);
    InsertSort(R,n);
    printList(R,n);

    // TODO 
    int R2[8] = {49, 38, 65, 97, 76, 13, 27, 49};
    printf("BInsertSort: \n");
    printList(R2,n);
    BInsertSort(R2,n);
    printList(R2,n);
}
