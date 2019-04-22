#include <time.h>      
#include <stdlib.h>      
#include <unistd.h> 
#include<stdio.h>
#include<pthread.h>
void *mythread(int i)
{
	int j;
	j=i;
	sleep(1);
	printf("this process %d \n" , j);	
}
main ()      
{     clock_t ct1, ct2;      
    int i;      

    if ((ct1 = clock ()) == -1)      
        perror ("clock");      

    printf ("CLOCKS_PER_SEC = %ld\n", CLOCKS_PER_SEC);
/*	pthread_t tid;
	pthread_create(&tid , NULL , mythread , i);
	pthread_join(tid , NULL);      
	*/
	pthread_t tid;
    for (i = 0; i < 10; i++)      
       // printf("hi");  
	{
	pthread_create(&tid , NULL , mythread , i);
	pthread_join(tid , NULL);  }   
    if ((ct2 = clock ()) == -1)      
        perror ("clock");      

    printf ("ct1 = %ld, ct2 = %ld, diff = %ld\n", ct1, ct2, ct2 - ct1);      
}
