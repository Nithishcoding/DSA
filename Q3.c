/*Develop a menu driven program to implement the following operations on an array of integers with dynamic
memory allocation. Display the array contents after each operation.
i) Insert by order ii) Delete by position iii) Search by key iv) Reverse the contents. */

#include<stdio.h>
#include<stdlib.h>
int ne=0;

void display(int *a,int size)
{
    if(ne==0)
    {
        printf("Array is empty\n");
        return;
    }

    for(int i=0;i<ne;i++)
      printf("%d ",*(a+i));
    printf("\n");
}

void insert_by_order(int *a,int size)
{
  int ele;
  if(ne==size)
  {
    printf("Array is full\n");
    printf("reallocating array\n");
    size++;
    a=(int *)realloc(a,size*sizeof(int));
  }
  printf("Enter the ele to be inserted\n");
   scanf("%d",&ele);
  *(a+ne)=ele;
  ne++;
    for(int i=1;i<ne;i++)
    {
          int j=i;
           while(j>=1 && *(a+j)<*(a+j-1))
           {
            int temp;
            temp=*(a+j);
            *(a+j)=*(a+j-1);
            *(a+j-1)=temp;
            j--;
           }
    }
  display(a,size);
}

void delete_by_pos(int *a,int size)
{
  int pos,flag=0;
  if(ne==0)
  {
    printf("Array is empty\n");
    return;
  }
  printf("Enter the pos to be deleted\n");
    scanf("%d",&pos);
  if(pos<0 || pos>ne+1)
  {
    printf("Invalid pos\n");
    return;
  }
  pos--;
  for(int i=0;i<ne;i++)
   if(pos==i)
   {
    printf("Ele in %d pos is %d\n",i+1,*(a+i));
    for(int i=pos;i<ne-1;i++)
     *(a+i)=*(a+i+1);
    ne--;
    flag=1;
    break;
   }
   if(!flag)
    printf("%d pos is not found\n",pos+1);
  display(a,size);

}

void search_by_key(int *a,int size)
{
  int key,flag=0;
  if(ne==0)
  {
    printf("Array is empty\n");
    return;
  }
  printf("Enter the ele to be searched\n");
    scanf("%d",&key);
  for(int i=0;i<ne;i++)
    if(key==*(a+i))
    {
     printf("%d key is found at pos %d\n",key,i+1);
     flag=1;
     break;
    }
    if(!flag)
     printf("%d key is no found\n",key);
}


void reverse(int *a,int size)
{
  int temp;
  if(ne==0)
  {
    printf("Array is empty\n");
    return;
  }
    printf("Array ele in reverse order is: ");

    for(int i=0;i<ne/2;i++)
    {
        temp=*(a+i);
        *(a+i)=*(a+ne-i-1);
        *(a+ne-i-1)=temp;
    }
    display(a,size);
}






void main()
{
    int choice,size;
       printf("Enter the size of the array\n");
         scanf("%d",&size);
    int *arr=(int *)malloc(size*sizeof(int));
    printf("Enter the no of ele\n");
      scanf("%d",&ne);

    printf("Enter the %d no ofelements of an array\n",ne);
     for(int i=0;i<ne;i++)
       scanf("%d",arr+i);
    do
    {
        printf("\nARRAY IMPLEMENTATION\n");
        printf("--------------------\n");
        printf("1.INSERT BY ORDER\n2.DELETE BY POS\n3.SEARCH BY KEY/n4.REVERSE THE CONTENTS\n5.EXIT FROM THE PROGRAM\n");
        printf("Enter the your choice\n");
          scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            insert_by_order(arr,size);
            break;
        case 2:
            delete_by_pos(arr,size);
            break;
        case 3:
            search_by_key(arr,size);
            break;
        case 4:
            reverse(arr,size);
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
