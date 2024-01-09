  #include<stdlib.h>
 #include<stdio.h>
#define STACKSIZE 10
#define TRUE 1
#define FALSE  0
struct stack
{
    int item [STACKSIZE];
   int top;
};
struct stack *s;
void INIIALISE( struct stack *s)
{
    s->top=-1;
}
void push(struct stack *s,int x)
{if(s->top==STACKSIZE-1)
{printf("\n stack overflows");exit(1);}
else{
    s->top++;
    s->item[s->top]=x;
}

}
int pop(struct stack *s)
{
    if(s->top==-1) 
{printf("\n stack underflows");exit(1);}
else{
    int x;
    x=s->item[s->top];
   s->top--;
    return x;
}

}
int stacktop(struct stack *s)
{
    if(s->top==-1)
    {
    printf("\n stack underflows");
    exit(1);
    }
else{
    int x;
    x=s->item[s->top];
    return x;
}}
 int isempty(struct stack*s)
{
    if(s->top==-1)
    return TRUE;
    else return FALSE;
}

