#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int NearestPrime(int n)
 {
    int i=0,j=0,flag=0;
 for(i=n;i>=2;i--)
 {
  for(j=2;j<=sqrt(i);j++)
  {
    if(i%j==0)
    {
        flag=1;
     break;
    }
  }
  if(j>sqrt(i))
  return i;
 }
    
 }

int NoOfDigits(int ts)
{int n=0;
 while (ts!=0)
    {
      n++;
      ts=ts/10;
    }
    return n;
}
int size(int ts)
{int n=0;
 while (ts!=0)
    {
      n++;
      ts=ts/10;
    }
    return n;
}
int power(int a,int b)
{if(b==0)
return 1;
else
return a*power(a,b-1);
}
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
int DivisionHash(long long k,int ts)
{
    int p=NearestPrime(ts);
    printf("%d\n",p);
    int l=k%p;
    return l;
}
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
int MidsquareHash(long long k,int ts)
{
     int d,l;
    d=NoOfDigits(ts-1);
    l=NoOfDigits(k);
    int e=((2*l)-d)/2;
   int r=power(10,e);
    k=(k*k)/r;
    r=power(10,d);
    return k%r;
}
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
int FoldingHash(long long k,int ts)
{
    int d=size(ts-1);
    int sum=0;
    int mod=power(10,d);
    while (k!=0)
    {
        sum=sum+k%mod;
        k=k/mod; 
    }

    return sum%ts;
}
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
int LinearProbing(int Table[],int ts,int x)
{
  int flag;
  int m=x%ts;
  if(Table[m]==0)
  {
    Table[m]=x;
  }
  else
  {
     int flag=0,newpos;
    for (int i = 1; i < ts; i++)
    {
       newpos=(m+i)%ts;
       if(Table[newpos]==0)
       {
        Table[newpos]=x;
        flag=1;
        break;
       }
    }
  }
  return flag;
}
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
int QuadraticProbing(int Table[],int ts,int x)
{
  int flag=0,m;
  m=x%ts;
  if(Table[m]==0)
  Table[m]=x;
  else
  {
   int i=1;
   while (flag==0)
   {
    int newpos=(m+i*i)%ts;
    i++;
    if(Table[newpos]==0)
    {
      Table[newpos]=x;
      flag=1;
    }
   }
   
  }
  return flag;
}
 /*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
 int doublehashing(int Table[],int ts,int x)
 {
  int h=x%ts;
  int flag=0;
  if(Table[h]==0)
  Table[h]=x;
  else
  {
   int hdash=(2*x-7)%ts;
   int i=1;
   while (flag==0)
   {
    int newpos=(h+(i*hdash))%ts;
    if(Table[newpos]==0)
    {
      Table[newpos]=x;
      flag=1;
    }
    i++;
   }
   
  }
  return flag;
 }
int main()
{
     long long key;
     int L,TS=15,n,i;
     int Table[15]={0};
     printf("enter key for MidsquareHash and ts:");
     scanf("%lld%d",&key,&TS);
    L= MidsquareHash(key,TS);
     printf("%d\n",L);
    //  printf("enter key for FoldingHash and ts:");
    //  scanf("%lld%d",&key,&TS);
    //  L=FoldingHash(key,TS);
    //  printf("%ld\n",L);
    //   printf("enter key for DivisionHash and ts:");
    //  scanf("%lld%ld",&key,&TS);
    //  L=DivisionHash(key,TS);
    //  printf("%ld\n",L);
    // printf("enter no of elements to be inserted");
    // scanf("%d",&n);
    // for( i=0;i<n;i++)
    // {
    //   scanf("%d",&key);
    //   doublehashing(Table,TS,key);
    // }
    // for(i=0;i<=TS-1;i++)
    // {
    //   printf("%d\t",i);
    // }
    // printf("\n");
    // for(i=0;i<TS;i++)
    // {
    //   printf("%d\t",Table[i]);
    // }
    return 0;
}