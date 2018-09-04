#include <stdio.h>
#include <math.h>

int gcd(int var1,int var2);

struct rational
{
    int numerator;
    int denominator;
};

struct rational make_rational(int num,int deno)
{
    struct rational r;
    int simp = gcd(num,deno);
    r.numerator = num/simp;
    r.denominator = deno/simp;
    return r;
}

struct rational add_rational(struct rational r1,struct rational r2)
{
    return make_rational(r1.numerator*r2.denominator+r2.numerator*r1.denominator,
                            r1.denominator*r2.denominator);
}

struct rational sub_rational(struct rational r1,struct rational r2)
{
    return make_rational(r1.numerator*r2.denominator-r2.numerator*r1.denominator,
                            r1.denominator*r2.denominator);
}

struct rational mul_rational(struct rational r1,struct rational r2)
{
    return make_rational(r1.numerator*r2.numerator,r1.denominator*r2.denominator);
}

struct rational div_rational(struct rational r1,struct rational r2)
{
    if(0 == r2.numerator)
    {
        printf("divisor can't be 0");
        exit(-1);
    }
    return make_rational(r1.numerator*r2.denominator,r1.denominator*r2.numerator);
}

void print_rational(struct rational r)
{
   if(0 == r.denominator)
       printf("denominator can't be 0\n");
   else if(0 == r.numerator)
       printf("0\n");
   else if(abs(r.denominator) == abs(r.numerator))
       printf("%d\n",r.numerator/r.denominator);
   else if((0 > r.numerator && 0 < r.denominator)||(0 < r.numerator && 0 > r.denominator))
       printf("-%d/%d\n",abs(r.numerator),abs(r.denominator));
   else
       printf("%d/%d\n",abs(r.numerator),abs(r.denominator));
}

int main(void)
{
    struct rational a = make_rational(1,8);
    struct rational b = make_rational(-1,8);
    print_rational(add_rational(a,b));
    print_rational(sub_rational(a,b));
    print_rational(mul_rational(a,b));
    print_rational(div_rational(a,b));
    return 0;

}

int gcd(int var1,int var2)
{
   if (var1 % var2 ==0)
   {
        return var2;
   }
            
   if (var2 % var1 ==0)
   {
        return var1;
   }
            
   if (abs(var1) > abs(var2))
        return gcd(abs(var2),abs(var1)%abs(var2));

   if (abs(var2) > abs(var1))
        return gcd(abs(var1),abs(var2)%abs(var1));
}
