#include <stdio.h>
#include <math.h>

int main(void)
{
    int x;
    printf("enter a value : ");
    scanf("%d",&x);
    printf("\nthe units digit of %d is %d \n",x,x%10);
    printf("\nthe tens digit of %d is %d \n",x,(x%100-x%10)/10);
    return 0;
}

