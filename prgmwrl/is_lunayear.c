#include <stdio.h>
#include <math.h>

int main(void)
{
    int year;
    printf("enter a year : ");
    scanf("%d",&year);

    if((year % 400) == 0 )
        printf("%d is a leep-year\n",year);
    else  if((year % 4) == 0 )
        if(year % 100 == 0)
            printf("%d is not a leep-year\n",year);
        else 
            printf("%d is a leep-year\n",year);
    else
            printf("%d is not a leep-year\n",year);
        
    return 0;
}
            
