#include <stdio.h>
#include <math.h>

long int fibonacci(long int n);

int main(void)
{
    int n;
    long int res;
    printf("u want to get  NO.x of the Fibonacci?");
    scanf("%d",&n);
    
    res = fibonacci(n);
    printf("\nNo.%d of the fibonacci is %li\n",n,res);

    return 0;
}

long int fibonacci(long int n)
{
    int icnt=1 ;
    int t1=1,t2=1,tp=0;
    while(icnt <= n)
    {
        t1 += t2;
        tp = t1;
        t1 = t2;
        t2 = tp;
        ++icnt;
    }

    return t1;
}
