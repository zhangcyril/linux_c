#include <stdio.h>
#include <math.h>

double myround(double x);

int main(void)
{
    double var,prf;
    printf("input num : ");
    scanf("%lf",&var);

    prf=myround(var);
    printf("\n result num : %lf \n",prf);
    printf("\n raw num : %lf \n",var);
    
    return 0;
}

double myround(double x)
{
    if(x > 0)
        if(0.5<=(x-(int)x))
            return ceil(x);
        else
            return floor(x);
    else
        if(-0.5<=(x-(int)x))
            return ceil(x);
        else
            return floor(x);
}        
