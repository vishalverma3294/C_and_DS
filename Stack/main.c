#include <stdio.h>
#include <stdlib.h>

struct _stack
{
 int size;
 int top;
 int *data;
};
 struct _stack st;

int push(struct _stack * s, int data)
{
    int temp=0;

    if(s->top>=(s->size-1))
    {
        printf("stack overflow\n");
        temp=-1;
    }
    else
    {
        s->top++;
        s->data[s->top]=data;
        printf("Push successful\n");
        temp=0;
    }
    return temp;
}

int pop(struct _stack * s)
{
    int temp=0;

    if(s->top<0)
    {
        printf("stack empty\n");
        temp=-1;
    }
    else
    {
        temp= s->data[s->top];
        s->data[s->top] = 0;
        s->top--;
        printf("Pop successful\n");
    }
    return temp;
}

void display_stack(struct _stack * s)
{
    printf("Stack: \n");
    for(int i=(s->size-1);i>=0;i--)
    {
        printf("%d\n",st.data[i]);
    }
}

int d[]={1,2,32,42,34,32,434,5,35,34,23,42,4,324,1};

int main()
{
    int temp;
    st.top=-1;
    st.size=10;
    st.data=(int*)malloc(st.size*(sizeof(int)));

    for(int i=0;i<15;i++)
    push(&st,d[i]);
    display_stack(&st);

    temp = pop(&st);

    printf("pop: %d",temp);


    return 0;
}
