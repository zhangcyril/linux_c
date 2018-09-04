#include <stdio.h>
#include <math.h>

void diamond(int n,char symbol);

int main(void)
{
    int size;
    char symbol;
    printf("enter diamond size and symbol you like,interval with space:");
    scanf("%d %c",&size,&symbol);
    if( 0 ==  size%2)
        return 0;

    diamond(size,symbol);

    return 0;

}

void diamond(int n,char symbol)
{
   int lim = (n+1)/2;
   for (int icnt=1 ; icnt <= n ; ++icnt)
   {
       for (int jcnt=1 ; jcnt <= n; ++jcnt)
       {
            if (abs(jcnt - lim) <= (n - abs(icnt - lim)*2)/2)
                printf(" %c",symbol);
            else
                printf("  ");
       }
       printf("\n");
   }
   return ;
}
