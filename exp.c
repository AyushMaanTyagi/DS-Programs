#include<stdio.h>
#define m 1000
int power(int a,int b)
{
    if(b==0)
    return 1;
    else
    {
int p=power(a,b/2);
if(b%2==0)
return (p*p)%m;
else
return (((a*p)%m)*p)%m;
    }

}
void main()
{
int x=power(2,60);
printf("%d",x);
}