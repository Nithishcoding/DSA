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

void insert_by_pos(int *a,int size)
{
    int pos,ele;
    if(ne==size)
    {
        printf("array is full\n");
        printf("reallocating array\n");
        size++;
        a=(int *)realloc(a,size*sizeof(int));
    }
    printf("Enter the ele\n");
      scanf("%d",&ele);
    printf("Enter the pos\n");
      scanf("%d",&pos);
    if(pos<0 || pos>ne+1)
    {
        printf("Invalid pos\n");
        return;
    }   
    for(int i=ne-1;i>=pos-1;i--)
     *(a+i+1)=*(a+i);

    *(a+pos-1)=ele;
    ne++;      
    display(a,size);
}

void delete_by_key(int *a,int size)
{
    int key,pos,flag=0;
    if(ne==0)
    {
        printf("array is empty\n");
        return;
    }
    printf("Enter the key to be deleted\n");
      scanf("%d",&key);
    for(int i=0;i<ne;i++)
        if(key==*(a+i))
        {
            printf("%d ele is found at pos %d\n",key,i+1);
            pos=i+1;
            for(int i=pos-1;i<ne;i++)
             *(a+i)=*(a+i+1);
             ne--;
            flag=1;
            printf("%d ele is deleted from %d pos\n",key,pos); 
        }
    if(!flag)
        printf("%d is not found\n");
    
    display(a,size);

}

void search_pos(int *a,int size)
{
    int pos,flag=0;
    if(ne==0)
    {
        printf("Array is empty\n");
        return;
    }
       printf("Enter the pos to be searched\n");
         scanf("%d",&pos);
       for(int i=0;i<ne;i++)
        if(pos-1==i)
        {
          printf("%d pos is found and ele present is %d\n",pos,*(a+i));
          flag=1;
          break;
        }
        if(!flag)
         printf("%d pos is not found\n",pos);

        display(a,size);  
     
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
    int size,choice;
       printf("Enter the size\n");
         scanf("%d",&size);
    int *a=(int *)malloc(size*sizeof(int));
    printf("Enter the no of the elemente\n");
      scanf("%d",&ne);
    printf("enter the %d no of ele\n",ne);
     for(int i=0;i<ne;i++)
       scanf("%d",a+i);
    for(;;)
    {
        printf("ARRAY OPERATIONA\n");
        printf("1.INSERT BY POSITION\n2.DELETE BY KEY\n3.SEARCH BY POSITION/n4.REVERSE THE CONTENTS\n5.EXIT FROM THE PROGRAM\n");
        printf("Enter the your choice\n");
          scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            insert_by_pos(a,size);
            break;
        case 2:
            delete_by_key(a,size);
            break;
        case 3:
            search_pos(a,size);
            break;
        case 4:
            reverse(a,size);
            break;
        case 5:
            printf("EXITING FROM THE PROG\n");
            exit(0);
        default:
            printf("INVALID CHOICE\n");
            break;
        }  
    }     
}