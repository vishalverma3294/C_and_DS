#include <stdio.h>
#include <stdlib.h>


typedef struct _Node
{
 int data;
 struct _Node* Next;
}Node;

Node *first_c;

void create_c_LL(Node**head, int *data,int count)
{
    Node*last;
    Node*t;

    last=(Node *)malloc(sizeof(Node));
    last->data=data[0];
    (*head)=last;
    last->Next=NULL;

    for(int i=1;i<count;i++)
    {
     t=(Node*)malloc(sizeof(Node));
     t->data=data[i];
     last->Next=t;
     t->Next=NULL;
     last=t;
    }
    last->Next=(*head);
}


void display_c_ll(Node * f)
{
    Node *head = first_c;
    do
    {
     printf("CLL: %d,",f->data);
     f=f->Next;
    }while(f!=head);
    printf("\n");

}

void insert_c_node(Node*p, int data,int pos)
{
    if(pos==0)
    {
      Node*t=(Node*)malloc(sizeof(Node));
      t->data=data;
      while(p->Next!=first_c)
      {
          p=p->Next;
      }
      p->Next=t;
      t->Next=first_c;
      first_c=t;
    }
    else
    {
        Node*t=(Node*)malloc(sizeof(Node));
        t->data=data;
        for(int i=0;(i<pos-1)&&p;i++)
        {
            p=p->Next;
        }
        t->Next=p->Next;
        p->Next=t;
    }
}
void delete_c_ll(Node*p,int pos)
{
  if(pos==1)
    {
        while(p->Next!=first_c)
        {
            p=p->Next;
        }
        p->Next=first_c->Next;
        free(first_c);
        first_c=p->Next;
    }
  else
    {
        Node*q=NULL;
        for(int i=0;(i<pos-1);i++)
        {
            q=p;
            p=p->Next;
        }
        q->Next=p->Next;
        free(p);
    }
}
