#include <stdio.h>
#define N 5
int a[N];

void permutation(int flr,int ceil);

int main(void)
{
    for (int i = 0; i < N; i++)
        a[i] = i+1;
    
    permutation(0,N-1);



    return 0;

}

void permutation(int flr,int ceil)
{
    if(ceil - flr >1)
        for(int i = flr; i < N; i++)
        {
            int temp = a[flr];
            a[flr] = a[i];
            a[i] = temp;
            permutation(flr+1,ceil);
            a[i] = a[flr];
            a[flr] = temp;
        }
    else
        {
            for (int i = 0; i < N; i++)
            {
                printf("%d ",a[i]);
            }
            printf("\n");
            for (int i = 0; i < N-2; i++)
            {
                printf("%d ",a[i]);
            }
            printf("%d ",a[N-1]);
            printf("%d ",a[N-2]);
            printf("\n");

        }
}
