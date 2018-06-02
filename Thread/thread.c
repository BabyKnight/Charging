#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void *print_msg(void *arg)
{
    int i;
    for(i=0; i<10; i++)
    {
        printf("Thread []\n");
        fflush(stdout);
        sleep(1);
    }
}


int main()
{
    pthread_t t1, t2;
    printf("Create thread 1\n");
    pthread_create(&t1, NULL, print_msg, NULL);
    printf("Create thread 2\n");
    pthread_create(&t2, NULL, print_msg, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}
