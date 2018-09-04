#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

int a[N];

void gen_random(int upper_bound)
{
	int i;
    srand(time(NULL));
	for (i = 0; i < N; i++)
		a[i] = rand() % upper_bound;
}

int main(void)
{
	int i, histogram[10] = {0};

	gen_random(10);
	for (i = 0; i < N; i++)
		histogram[a[i]]++;
	for (i = 0; i < N; i++)	
		printf("%d\t",i);
    printf("\n");
	for (i = 0; i < 10; i++)
	{
        for (int j = 0; j < 10; j++)
        {
            if (histogram[j]>0)
            {
                printf("*\t");
                histogram[j]--;
            }
            else
            {
                printf(" \t");
            }
        }
        printf("\n");
    }
	
    printf("\n");
	return 0;
}
