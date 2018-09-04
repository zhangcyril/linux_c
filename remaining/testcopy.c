#include <stdio.h>

int main()
{
   int a = 1;
   int b = a;
   printf("a = %d , b = %d\n",a,b);
   a = 2;
   printf("a = %d , b = %d",a,b);

}

//conclusion: change a can't effect b
