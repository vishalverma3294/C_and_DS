#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
 int data;
 struct _Node* Next;
}Node;
Node* first, *second;

int data_LL[]={101,201,220,432,522,638};
int data_LL2[]={102,211,222,343,452,693};

//function
void display_LL(Node * p);
void create_LL(int* data,int n);
int Find_Max(Node * fst);
void insert_sorted_LL(Node* p,int data);
Node* smart_search(Node* p, int key);

void create_LL(int* data, int n)
{
    Node* last,*t;
    first = (Node*)malloc(sizeof(Node));
    first->data=data[0];
    first->Next=NULL;
    last=first;

    for(int i=1;i<n;i++)
    {
      t=(Node*)malloc(sizeof(Node));
      last->Next = t;
      t->data=data[i];
      t->Next=NULL;
      last=t;
    }
}
void create_LL_second(Node** node_head, int* data, int n)
{
    Node* last,*t;
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data=data[0];
    new_node->Next=NULL;
    last= new_node;

    for(int i=1;i<n;i++)
    {
      t=(Node*)malloc(sizeof(Node));
      last->Next = t;
      t->data=data[i];
      t->Next=NULL;
      last=t;
    }
    *node_head = new_node;
}

int Find_Max(Node * fst)
{
    int temp;

    while(fst != NULL)
    {
        if(fst->data > temp)
           temp=fst->data;
        fst = fst->Next;
    }
    return temp;
}
Node* smart_search(Node* p, int key)
{
    Node*q;
    q=NULL;

    while(p!=NULL)
    {
        if(p->data == key)
        {
            q->Next=p->Next;
            p->Next=first;
            first=p;
            return p;
        }
        q=p;
        p=p->Next;
    }
    return NULL;
}

void insert_ll(Node*p,int data, int pos)
{
    if(pos == 0)
    {
     Node* t = (Node *)malloc(sizeof(Node));
     t->data=data;
     t->Next=first;
     first=t;
    }
    else
    {
     for(int i=0;(i< pos - 1)&&p;i++)
     {
         p=p->Next;
     }
     Node* t= (Node *)malloc(sizeof(Node));
     t->data=data;
     t->Next=p->Next;
     p->Next=t;
    }
}

void display_LL(Node * p)
{
    printf("LL: ");
    while(p != NULL)
    {
     printf("%d,",p->data);
     p = p->Next;
    }
    printf("\n");
}
void insert_sorted_LL(Node* p,int data)
{
    Node* q=NULL;

    while((p!=NULL)&&(p->data<data))
    {
        q=p;
        p = p->Next;
    }
    Node* t= (Node*)malloc(sizeof(Node));
    t->data=data;
    t->Next=q->Next;
    q->Next=t;
}
void delete_node(Node * p, int pos)
{
    if(pos == 1)
    {
     first=first->Next;
     int x=p->data;
     free(p);
    }
    else
    {
      Node *q;
      q=NULL;
     for(int i=0;(i<pos-1 )&& p;i++)
     {
         q = p;
         p = p->Next;
     }
     q->Next = p->Next;
     int x = p->data;
     free(p);
    }
}

void reverse_ll(Node* p)
{
 Node* q=NULL;
 Node* r=NULL;

 while(p!=NULL)
 {
     r=q;
     q=p;
     p=p->Next;
     q->Next=r;
 }
 first=q;
}

void merge(Node** f, Node **s)
{
Node* third;
Node* last;

third=NULL;
last=NULL;

if((*f)->data < (*s)->data)
 {
  third=(*f);
  last=(*f);

  (*f)=(*f)->Next;last->Next=NULL;
 }
 else
  {
     third=(*s);
     last=(*s);

     (*s)=(*s)->Next;     last->Next=NULL;
  }

  while((*f)!=NULL && (*s)!=NULL)
  {
      if((*f)->data < (*s)->data)
      {
        last->Next=(*f);
        last=(*f);
        (*f)=(*f)->Next;
                last->Next=NULL;
      }
      else
      {
        last->Next=(*s);
        last=(*s);
        (*s)=(*s)->Next;
                last->Next=NULL;
      }
  }

  if((*f)!=NULL)
  {
    last->Next=(*f);
  }
  else
  {
    last->Next=(*s);
  }

  (*f)=third;
}

int is_loop(Node*f)
{
    Node*p=NULL,*q=NULL;

    do
    {
        p=p->Next;
        q=q->Next;

        q= q!=NULL?q->Next:NULL;

    }while(p && q && (p!=q));

    if(p==q)
        return 1;
    else
        return 0;
}

extern Node *first_c;
extern void create_c_LL(Node**head, int *data,int count);
extern void display_c_ll(Node * f);

extern void insert_c_node(Node*p, int data,int pos);



typedef struct _Node_D
{
int data;
struct _Node_D *Next;
struct _Node_D *Prev;
} Node_D;
extern Node_D *first_dll;


extern void display_DLL(Node_D * p);
extern void create_dll(Node_D** fst,int* data,int count);
extern void delete_dll(Node_D**fst,int count);
extern void insetion_dll(Node_D**fst,int data, int pos);
int main()
{
   //Node* found;
   // create_LL_second(&first,data_LL,6);
   // display_LL(first);
   // printf("Max: %d\n",Find_Max(first));

   //create_LL_second(&second,data_LL2,6);
   //display_LL(second);

   // insert_ll(first,10,0);
   // display_LL(first);
    //insert_sorted_LL(first,569);

    //reverse_ll(first);
    //delete_node(first,6);
    //merge(&first,&second);
    //display_LL(first);

   // create_c_LL(&first_c,data_LL,6);
   // display_c_ll(first_c);

    //insert_c_node(first_c,5,6);
   // delete_c_ll(first_c,6);
   // display_c_ll(first_c);
    //found = smart_search(first,569);
    //printf("Found: data = %d\n",found->data);

    create_dll(&first_dll,data_LL2,6);
    display_DLL(first_dll);

    insetion_dll(&first_dll,100,1);
    display_DLL(first_dll);

    delete_dll(&first_dll,7);
    display_DLL(first_dll);

    return 0;
}



