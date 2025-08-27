#include <stdio.h>
#include <stdlib.h>


typedef struct _Node_D
{
int data;
struct _Node_D *Next;
struct _Node_D *Prev;
} Node_D;
Node_D *first_dll;


void display_DLL(Node_D * p)
{
    printf("DLL: ");
    while(p != NULL)
    {
     printf("%d,",p->data);
     p = p->Next;
    }
    printf("\n");
}

void create_dll(Node_D** fst,int* data,int count)
{
Node_D* t=NULL;
Node_D* last=NULL;

t=(Node_D *)malloc(sizeof(Node_D));
(*fst)=t;
last=t;
last->data=data[0];
last->Prev=NULL;
last->Prev=NULL;

for(int i=1;i<count;i++)
{
    t=(Node_D*)malloc(sizeof(Node_D));
    t->data=data[i];
    t->Prev=last;
    t->Next=NULL;
    last->Next=t;
    last=t;
}
}

void insetion_dll(Node_D**fst,int data, int pos)
{
 if(pos ==0)
 {
    Node_D* t=(Node_D*)malloc(sizeof(Node_D));
    t->Next=(*fst);
    t->Prev=NULL;
    t->data=data;
    (*fst)->Prev=t;
    (*fst)=t;
 }
 else
 {
    Node_D* p=(*fst);
    Node_D* t=(Node_D *)malloc(sizeof(Node_D));
    t->Prev=NULL;
    t->data=data;
    for(int i=0;i<pos-1;i++)
    {
     p=p->Next;
    }
    t->Next=p->Next;
    t->Prev=p;
    if(p->Next)
        (p->Next)->Prev=t;
    p->Next=t;

 }
}

void delete_dll(Node_D**fst,int pos)
{
    if(pos==1)
    {
        Node_D *t=(*fst);
        (*fst)=(*fst)->Next;
        (*fst)->Prev=NULL;
        free(t);
    }
    else
    {
        Node_D *t=(*fst);
        for(int i=0;(i<pos-1)&&t;i++)
        {
          t=t->Next;
        }

        (t->Prev)->Next=t->Next;
        if(t->Next)
        (t->Next)->Prev=t->Prev;

        free(t);
    }

}

