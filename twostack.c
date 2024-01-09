#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
#define T 1;
#define F 0;
int top1,top2;
int x, A[SIZE];
void Initialize1()
{
    top1=-1;
}
void Initialize2()
{
    top2=SIZE;
}
int IsEmpty1()
{
    if (top1==-1)
    {return T;}
    else 
    {return F;}
}
int IsEmpty2()
{
    if (top2==SIZE)
    {return T;}
    else 
    {return F;}
}
void push1(int x)
{
    if(top1+1==top2)
    {
    printf("Stack Overflow");
    exit(1);}
    else{
        top1++;
        A[top1]=x;
    }

}
void push2(int x)
{
    if(top1+1==top2)
    {
    printf("Stack Overflow");
    exit(1);}
    else{
        top2--;
        A[top2]=x;
    }

}
int pop1()
{
    if(IsEmpty1())
    {
        printf("stack underflow");
        exit(1);
    }
    else{
        int x=A[top1];
        top1--;
        return x;
    }
}
int pop2()
{
    if(IsEmpty2())
    {
        printf("stack underflow");
        exit(1);
    }
    else{
        int x=A[top2];
        top2++;
        return x;
    }
}
void main()
{
    
Initialize1();
Initialize2();
push1(1);
push2(10);
push1(3);
push2(8);
push1(5);
push2(6);
push1(7);
push2(4);
push1(9);
push2(2);
x=pop1();
printf("%d",x);
x=pop2();
printf("%d",x);
x=pop1();
printf("%d",x);
x=pop2();
printf("%d",x);
x=pop1();
printf("%d",x);
x=pop2();
printf("%d",x);
x=pop1();
printf("%d",x);
x=pop2();
printf("%d",x);
x=pop1();
printf("%d",x);
x=pop2();
printf("%d",x);
}