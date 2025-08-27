#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows=0;
    printf("enter the number of rows:");
    scanf("%d",&rows);


    int temp =0;
    int temp2 =1;
    int num = temp + temp2;
    printf("%d %d", temp,temp2);

    for(int i=3;i<=rows;i++)
    {
        printf(" %d",num);
        temp = temp2;
        temp2= num;
        num = temp + temp2;

    }





/*
    for(int i=rows;i>0;i--)
    {
        for(int j=i;j>0;j--)
        {
            printf("*");
        }
        printf("\n");
    }
*/
/*
  for(int i=0;i<=rows;i++)
    {
        for(int j=i;j<=rows-1;j++)
        {
            printf(" ");
        }
        for(int k=1;k<=2*i-1;k++)
        {
            printf("*");
        }
        printf("\n");
    }
*/

/*
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<=i;j++)
        {
            printf("*");
        }
        printf("\n");
    }
*/








 /*   for(int i=0;i< rows;i++)
    {
        for(int j=0;j<i;j++)
        {
          printf(" ");
        }
        for(int j=i;j<rows;j++)
        {
          printf("*");
        }
        printf("\n");
    }
*/
/*    for(int i=0;i<rows;i++)
    {
        for(int j=i;j<rows;j++)
        {
          printf(" ");
        }
        for(int j=0;j<=i;j++)
        {
          printf("*");
        }
        printf("\n");
    }
*/

    return 0;
}
