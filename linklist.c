#include<stdio.h>
#include"Linkedlist.h"
void main()
{
    int x;
    struct Node *START;
    START=NULL;
    InsBeg(&START,100);
     InsBeg(&START,200);
      InsBeg(&START,300);
      InsBeg(&START,10);
     InsBeg(&START,20);
      InsBeg(&START,400);
      traverse(START);
    Insend(&START,89);
    Insend(&START,59);
    Insend(&START,69);
    Insend(&START,29);
    InsAft(&START,10,51);
    traverse(START);
    x=Delbeg(&START);
    printf("Deleted Element is->%d\n",x);
    x=Delbeg(&START);
    printf("Deleted Element is->%d\n",x);
    x=Delbeg(&START);
    printf("Deleted Element is->%d\n",x);
    traverse(START);
    x=delEnd(&START);
    printf("Deleted Element is->%d\n",x);
    x=delEnd(&START);
    printf("Deleted Element is->%d\n",x);
    x=delEnd(&START);
    printf("Deleted Element is->%d\n",x);
    traverse(START);
// Reverse();
// traverse();
 }