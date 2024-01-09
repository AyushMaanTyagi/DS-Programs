#include<stdio.h>
int main()
{
    int n,rs=0,cs=0,c=0,r=0,cn=0;
    int A[30][30];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
while(r<n)
{
    for(int i=0;i<n;i++)
    {rs=rs+A[r][i];
     cs=cs+A[i][cn];
    }
    if(cs>rs)
    c++;
    cn++;
    rs=0;cs=0;
    if(cn==n)
    {
        cn=0;
        r++;
    }
    
}
printf("%d",c);
return 0;
}