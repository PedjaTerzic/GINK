#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

mpz_t a,s,N;
unsigned long  i,ex,b,n;

void P(mpz_t p , unsigned long m , mpz_t x){
mpz_t p0,p1;
unsigned long l;

mpz_set_ui(p,8);
mpz_init_set_ui(p0,2);
mpz_init_set(p1,x);
l=2;

while(l<=m)
{
mpz_mul(p,x,p1);
mpz_sub(p,p,p0);
mpz_set(p0,p1);
mpz_set(p1,p);
l=l+1;
}

}

int main(void)
{

mpz_t r,r1,r2;

printf("Enter the base :");
scanf("%lu",&b);
printf("Enter the exponent :");
scanf("%lu",&n);

mpz_init(r);
mpz_init(r1);
mpz_init(r2);
mpz_init(a);

ex=1 << n;

mpz_set_ui(a,8);
P(r1,b/2,a);
P(r2,b/2,r1);
mpz_init_set(s,r2);

mpz_init(N);
mpz_ui_pow_ui(N,b,ex);
mpz_add_ui(N,N,1);

for (i = 1; i <= ex-2; i++)
{
P(r,b,s);
mpz_mod(s,r,N);
}
mpz_clear(N);
if(mpz_cmp_ui(s,0)==0)
{
printf("%lu^2^%lu+1 is prime\n" , b,n);
}
else
{
printf("%lu^2^%lu+1 is composite\n" , b,n);
}
mpz_clear(s);
return 0;
}