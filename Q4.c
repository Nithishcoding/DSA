/* Implement circular single linked list to perform the following operations
i) Insert by order
ii ) Delete by position iii) Search for an item by key iv) Delete by key Display the list
contents after each operation*/

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

NODE* createNode(int value)
{
    NODE *n=(NODE *)malloc(sizeof(NODE));
    if(n==NULL)
    {
        printf("\nMemory allocation failed\n");
        return NULL;
    }
    n->data=value;
    n->link=NULL;
    return n;
}

void display(LIST *list)
{
    NODE *n=list->head;

    if(list->head==NULL)
    {
      printf("List is empty\n");
      return;
    }
    do
    {
      printf("%d ",n->data);
      n=n->link;
    } while (n!=list->head);
    printf("\ncount=%d",list->count);
}

NODE* insert_front(LIST *list,int value)
{
    NODE* n=createNode(value);
    NODE *temp=list->head;
    if(list->head==NULL)
    {
     list->head=n;
     n->link=list->head;
    }
    else
    {
      while (temp->link!=list->head)//traversing to last
      {
         temp=temp->link;
      }
      n->link=list->head;
      list->head=n;
      temp->link=n;//change last link
    }
    list->count++;
    printf("Node with value %d inserted at the front.\n", value);
    display(list);
    return list;
}

void insert_by_order(LIST *p,int value)
{

    NODE *n=createNode(value);
    NODE *cur=p->head;
    NODE *last=p->head;
    if(p->head==NULL || value <= p->head->data)
    {
       insert_front(p,value);
    }
    else
    {
        NODE *temp=p->head;
        NODE *prev=NULL;
        do
        {
           prev=temp;
           temp=temp->link;
        } while (temp!=p->head && temp->data < n->data);
       n->link=temp;
       prev->link=n;
       p->count++;
    }
    printf("Ordered list:");
    display(p);
}

void delete_by_pos(LIST *list,int pos)
{
   if(list->head==NULL)
   {
      printf("LIST IS EMPTY\n");
      return;
   }
   if(pos<1 || pos>list->count)
   {
      printf("Entered invalid pos\n");
      return;
   }

   if(pos==1)//delete front
   {
      NODE *last=list->head;
      NODE *temp=list->head;
     while (last->link!=list->head)
     {
      last=last->link;
     }
    if(list->head==temp->link)//making list head as null
     list->head=NULL;
    else
    {
     list->head=temp->link;
     last->link=list->head;
    }
     printf("DELETED NODE IS %d\n",temp->data);
     free(temp);
     list->count--;
   }
   else
   {
       NODE *temp=list->head;
       NODE *prev=NULL;
      for(int i=0;i<pos-1;i++)
      {
        prev=temp;
        temp=temp->link;
      }
      prev->link=temp->link;
      printf("DELETED NODE IS %d\n",temp->data);
      free(temp);
      list->count--;
   }
   display(list);
}

void search_by_key(LIST *list,int key)
{
    NODE *temp=list->head;
    int pos=1;
    if(temp->data==key)
    {
      printf("%d is found at pos %d",key,pos);
      return;
    }
    do
    {
      temp=temp->link;
      pos++;
    } while (temp!=list->head && temp->data!=key);

    if(temp==list->head)
      printf("\nElement %d is not found\n",key);
    else
     printf("%d is found at pos %d",key,pos);
}

void delete_front(LIST *list)
{
   if(list->head==NULL)
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
    list->count--;
}

void delete_by_key(LIST *list,int key)
{
    if(list->head==NULL)
    {
        printf("\n list is empty,nothing to delete\n");
        return;
    }

    NODE *temp=list->head;
    NODE *prev=NULL;
    NODE *last=list->head;
    if(temp->data==key)//key is found at head
    {
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
     list->count--;
    }
   else
   {
    do
    {
       prev=temp;
       temp=temp->link;
    } while (temp!=list->head && temp->data!=key);

    if(temp==list->head)
    {
     printf("Key is not found\n");
     return;
    }
    prev->link=temp->link;
    printf("\n%d key deleted successfully\n",temp->data);
    free(temp);
    list->count--;
   }
   display(list);
}

void main()
{
    int choice,key,pos,n,value;
    LIST *list=(LIST *)malloc(sizeof(LIST));
    list->count=0;
    list->head=NULL;

    do
    {
        printf("\nCIRCULAR SINGLY LINKED LIST IMPLEMENTATION\n");
        printf("-------------------------------------------\n");
        printf("1.INSERT BY ORDER\n2.DELETE BY POS\n3.SEARCH FOR AN ITEM BY KEY\n4.DELETE BY KEY\n5.Exit\n");
        printf("Enter your choice\n");
          scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to be inserted\n");
              scanf("%d",&value);
            insert_by_order(list,value);
            break;
        case 2:
            printf("Enter the pos to be deleted\n");
              scanf("%d",&pos);
            delete_by_pos(list,pos);
            break;
        case 3:
            printf("Enter the key to be searched\n");
              scanf("%d",&key);
            search_by_key(list,key);
            break;
        case 4:
            printf("Enter the key to be deleted\n");
              scanf("%d",&key);
            delete_by_key(list,key);
            break;
        case 5:
            printf("EXITING FROM THE PROGRAM\n");
            exit(0);
        default:
            printf("INVALID CHOICE\n");
            break;
        }
    } while (choice!=5);
}
