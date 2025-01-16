/*  Develop a menu driven program to implement the following operations on an array of integers with dynamic
memory allocation. Display the array contents after each operation.
i) Insert by position ii) Delete by key iii) Search by position iv) Reverse the contents. */

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int ne=0;

void insert_by_pos(int *a,int *n)
{
    int pos,ele;
       printf("Enter the pos to be inserted\n");
         scanf("%d",&pos);
       if(pos<0 || pos > *n+1)
       {
         printf("Invalid pos\n");
         return;
       }
       if(ne==*n)
       {
        printf("array is full\n");
        printf("reallocating array\n");
        *n++;
        a=(int *)realloc(a,*n*sizeof(int));
       }

       printf("Enter the ele\n");
         scanf("%d",&ele);
       for(int i=(*n)-1;i>pos-1;i--)
         *(a+i+1)=*(a+i);

       *(a+pos-1)=ele;
       ne++;
       for(int i=0;i<ne;i++)
        printf("%d ",*(a+i));
}

void delete_by_key(int *a,int *n)
{
    int key,flag=0,pos;
       printf("Enter the key to be deleted\n");
         scanf("%d",&key);
       for(int i=0;i<(*n);i++)
         if(*(a+i)==key)
         {
           printf("%d is found at %d pos\n",key,i+1);
           pos=i+1;
           for(int i=pos-1;i<(*n);i++)
            *(a+i)=*(a+i+1);
           (*n)--;
           flag=1;
           printf("%d ele is deleted from %d pos\n",key,pos);
         }
       if(!flag)
         printf("%d ele is not found\n",key);

       for(int i=0;i<ne;i++)
         printf("%d ",*(a+i));

}

void search_pos(int *a,int n)
{
    int pos,flag=0;
       printf("Enter the pos to be searched\n");
         scanf("%d",&pos);
       for(int i=0;i<n;i++)
        if(pos-1==i)
        {
          printf("%d pos is found and ele present is %d\n",pos,*(a+i));
          flag=1;
          break;
        }
        if(!flag)
         printf("%d pos is not found\n");

         for(int i=0;i<ne;i++)
           printf("%d ",*(a+i));

}

void reverse(int *a,int n)
{
  int temp;
    printf("Array ele in reverse order is: ");

    for(int i=0;i<n/2;i++)
    {
        temp=*(a+i);
        *(a+i)=*(a+n-i-1);
        *(a+n-i-1)=temp;
    }
    for(int i=0;i<ne;i++)
     printf("%d ",*(a+i));
}



void main()
{
    int choice,n;
    //int n=(int *)malloc(sizeof(int));
       printf("Enter the size of the array\n");
         scanf("%d",&n);
    int *arr=(int *)malloc(n*sizeof(int));
    printf("Enter the no of elements\n");
      scanf("%d",&ne);
    printf("Enter the elements of an array\n");
     for(int i=0;i<ne;i++)
       scanf("%d",arr+i);
    do
    {
        printf("\nARRAY IMPLEMENTATION\n");
        printf("--------------------\n");
        printf("1.INSERT BY POSITION\n2.DELETE BY KEY\n3.SEARCH BY POSITION/n4.REVERSE THE CONTENTS\n5.EXIT FROM THE PROGRAM\n");
        printf("Enter the your choice\n");
          scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            insert_by_pos(arr,&n);
            break;
        case 2:
            delete_by_key(arr,&n);
            break;
        case 3:
            search_pos(arr,n);
            break;
        case 4:
            reverse(arr,n);
            break;
        case 5:
            printf("EXITING FROM THE PROG\n");
            exit(0);
        default:
            printf("INVALID CHOICE\n");
            break;
        }
    } while (choice!=5);
}
