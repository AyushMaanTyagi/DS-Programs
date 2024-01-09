#include<stdio.h>
int search(char a[],char c)
{
    for(int i=0;i<9;i++)
    {
if(c==a[i])
return i;
    }
}
int main()
{
    char c,S1[3],S2[3];int i1,i2;
        scanf("%c",&c);
        scanf("%s",S1);
        scanf("%s",S2);
        char a[]={'6', '7', '8', '9', 'T', 'J', 'Q', 'K' ,'A','\0'};
        if(S1[1]==c&&S[1]!=c)
        printf("YES");
        else if(S1[1]==S2[1])
        {
i1=search(a,S1[0]);
i2=search(a,S2[0]);
if(i1>i2)
printf("YES");
else
printf("NO");
        }
        else
        printf("NO");
        return 0;

}