#include <stdio.h>
#include <math.h>



int main(void)
{
    int n,res=0;
    printf("the num n is:");
    scanf("%d",&n);
    
    for(int icnt = 1;icnt <= 100;++icnt)
    {
       if(n == icnt%10||n == (icnt%100)/10 ||n == (icnt/100))
            res++;
    }

    printf("\nFrom 1 to 100,num %d show %d times.\n",n,res);

    return 0;

}
