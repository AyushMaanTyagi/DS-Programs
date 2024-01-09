#include <stdio.h>
#include "Stackheader.h"
void main()
{
    int X, min;
    struct stack s1;
    struct stack s2;
    INIIALISE(&s1);
    INIIALISE(&s2);
    push(&s1, 7);
    push(&s1, 5);
    push(&s1, 12);
    push(&s1, 13);
    push(&s1, 6);
    push(&s1, 11);
    push(&s1, 10);
    min = stacktop(&s1);
    while(!isempty(&s1))
    {
        X=pop(&s1);
        if(X<min)
        {
            min=X;
        }
        push(&s2,X);
    }
    while(!isempty(&s2))
{
    X=pop(&s2);
    push(&s1,X);
}
 printf("min: %d",min);

    //     while (s1.top>0)
    //     {s1.top--;
    //     // X=pop(&s1);
    //     X=stacktop(&s1);
    //     if(X<min)
    //         {
    //             min=X;
    //         }
    //     }
    // // push(&s2,X);
   
}

