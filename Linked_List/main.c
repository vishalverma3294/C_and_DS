#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
    int data;
    struct _Node* Next;
} Node;

Node* First;

void Create_LinkedList(int *ptr,int n)
{
    Node *t,*Last;
    int i=0;
    First=(Node*)malloc(sizeof(Node));
    First->data=ptr[0];
    First->Next=NULL;
    Last=First;

    for(i=1;i<n;i++)
    {
        t=(Node*)malloc(sizeof(Node));
        t->data=ptr[i];
        t->Next=NULL;
        Last->Next=t;
        Last=t;

    }


}

void display(Node * Fst)
{
    while(Fst != NULL)
    {
        printf("LL: %d//",Fst->data);
        Fst=Fst->Next;
    }
}


int main()
{
    //Node *t,*Last,*First;
    //First=(Node*)malloc(sizeof(Node));
    //First->data=10;
    //First->Next=NULL;
    //t=(Node*)malloc(sizeof(Node));
    //First->Next=t;

    int Arr[]={2,45,56,75,22};
    Create_LinkedList(Arr,5);
    display(First);

    //printf("Hello world! %d\n",First->Next);
    return 0;
}
