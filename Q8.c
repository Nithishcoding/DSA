/*Implement circular single linked list to perform the following operations
i) Insert by position ii) Delete rear iii) Delete Front iv) Search for an item by value Display the list contents
after each operation */

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
}NODE;

typedef struct
{
    int count;
    NODE *head;
}LIST;

NODE *createnode(int value)
{
    NODE *n=(NODE *)malloc(sizeof(NODE));
    if(n==NULL)
    {
        printf("MEMORY ALLOCATION IS FAILED\n");
        return NULL;
    }
    n->data=value;
    n->link=NULL;

    return n;
}

void display(LIST *list)
{
    if(list->head==NULL)
    {
        printf("LIST IS EMPTY\n");
        return;
    }
    NODE *temp=list->head;
    do
    {
        printf("%d ",temp->data);
        temp=temp->link;
    } while (temp!=list->head);
    printf("\ncount=%d\n",list->count);
    printf("\n");
}

void insert_front(LIST *list,int value)
{
    NODE *n=createnode(value);
    if(list->head==NULL)
    {
        list->head=n;
        n->link=list->head;
    }
    else
    {
        NODE *last=list->head;
        while (last->link!=list->head)
        {
            last=last->link;
        }
        n->link=list->head;
        list->head=n;
        last->link=list->head;
    }
    list->count++;
    display(list);
}

void insert_rear(LIST *list,int value)
{
    NODE *n=createnode(value);
    NODE *last=list->head;
    while (last->link!=list->head)
    {
        last=last->link;
    }
    n->link=last->link;
    last->link=n;
    list->count++;
    display(list);
}








void insert_by_pos(LIST *list,int pos,int value)
{
     if(pos>list->count+2)
    {
        printf("INALID POS\n");
        return;
    }
    if(list->head==NULL || pos==1)
    {
        insert_front(list,value);
        return;
    }

    if(pos==list->count+1)
    {
        insert_rear(list,value);
        return;
    }
    NODE *n=createnode(value);
    NODE *temp=list->head;
    for(int i=0;i<pos-2;i++)
    {
      temp=temp->link;
    }
    n->link=temp->link;
    temp->link=n;
    list->count++;
    display(list);
}

void delete_rear(LIST *list)
{
    if(list->head==NULL)
    {
        printf("LIST IS EMPTY\n");
        return;
    }
    NODE *prev=NULL;
    NODE *temp=list->head;
    while (temp->link!=list->head)
    {
      prev=temp;
      temp=temp->link;
    }
    if(temp==list->head)
    {
        printf("%d is deleted\n",temp->data);
        list->head=NULL;
        free(temp);
        display(list);
    }
    else
    {
    prev->link=temp->link;
    printf("%d is deleted\n",temp->data);
    free(temp);
    list->count--;
    display(list);
    }
}

void delete_front(LIST *list)
{
    if(list->head==NULL)
    {
        printf("LIST IS EMPTY\n");
        return;
    }
    NODE *temp=list->head;
    NODE *last=list->head;
    while (last->link!=list->head)
    {
        last=last->link;
    }
   if(list->head==temp->link)
    list->head=NULL;
    else
    {
     list->head=temp->link;
     last->link=list->head;
    }
    printf("%d deleted at front\n",temp->data);
    free(temp);
    list->count--;
    display(list);
   /* if(list->head==NULL)
   {
      printf("LIST IS EMPTY\n");
      return;
   }
   NODE *last=list->head;
   NODE *temp=list->head;
    while (last->link!=list->head)
    {
      last=last->link;
    }
   if(list->head==temp->link)
    list->head=NULL;
   else
   {
    list->head=temp->link;
    last->link=list->head;
   }
    printf("DELETED NODE IS %d\n",temp->data);
    free(temp);
    list->count--;*/
}

void search_by_value(LIST *list,int value)
{
    if(list->head==NULL)
    {
        printf("LIST IS EMPTY\n");
        return;
    }
    NODE *temp=list->head;
    if(value==temp->data)
    {
        printf("%d is found at pos 1\n",temp->data);
    }
    else
    {
        int pos=1;
        do
        {
           temp=temp->link;
           pos++;
        } while (temp!=list->head && temp->data!=value);
        if(temp==list->head)
         printf("%d is not found\n",value);
        else
         printf("%d is found at %d pos\n",temp->data,pos);

        display(list);

    }
}














void main()
{
    int choice,pos,key,value;
    LIST *list=(LIST *)malloc(sizeof(LIST));
    list->head=NULL;
    list->count=0;

    for(;;)
    {
        printf("CIRCULAR LINKED LIST IMPLEMENTATION\n");
        printf("====================================\n");
        printf("1.INSERT BY POS\n2.DELETE AT REAR\n3.DELETE FRONT\n4.SEARCH BY VALUE\n5.EXITING FROM THE PROGRAM\n");
        printf("Enter your choice\n");
          scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter the pos and value to be inserted\n");
              scanf("%d %d",&pos,&value);
            insert_by_pos(list,pos,value);
            break;
        case 2:
            delete_rear(list);
            break;
        case 3:
            delete_front(list);
            break;
        case 4:
            printf("Enter the value to be searched\n");
              scanf("%d",&value);
            search_by_value(list,value);
            break;
        case 5:
            printf("EXITING FROM THE PROGRAM\n");
            free(list);
            exit(0);
        default:
            printf("INVALID CHOICE\n");
            break;
        }
    }
}
