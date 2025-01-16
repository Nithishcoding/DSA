/* Implement circular single linked list to perform the following operations
i) Insert front ii) Insert rear iii) Delete a node with the given key iv) Search for an item by position
Display the list contents after each operation*/

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
        printf("MEMORY ALLOCATON IS FAILED\n");
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
        last->link=list->head;//n
    }
    list->count++;
    display(list);
}

void insert_rear(LIST *list,int value)
{
    NODE *n=createnode(value);
    if(list->head==NULL)
    {
        insert_front(list,value);
    }
    else
    {
        NODE *temp=list->head;
        while (temp->link!=list->head)
        {
            temp=temp->link;
        }
        n->link=temp->link;
        temp->link=n;
        list->count++;
        display(list);
    }
}

void delete_front(LIST *list)
{
    NODE *temp=list->head;
    list->head=temp->link;
     if(list->head==temp)
     {
        list->head=NULL;
        free(temp);
     }
    NODE *last=list->head;
    while (last->link!=list->head)
    {
        last=last->link;
    }
    last->link=list->head;
    list->count--;
    display(list);
}













void delete_by_pos(LIST *list,int pos)
{
    if(list->head==NULL)
    {
        printf("LIST IS EMPTY\n");
        return;
    }
    if(pos<0 || pos>list->count)
    {
        printf("INVALID POS\n");
        return;
    }
    if(pos==1)
    {
        delete_front(list);
    }
    else
    {
     NODE *temp=list->head;
     NODE *prev;
     for(int i=0;i<pos-1;i++)
     {
      prev=temp;
      temp=temp->link;
     }
     prev->link=temp->link;
     printf("%d node is deleted\n",temp->data);
     free(temp);
     list->count--;
     display(list);
    }
}

void search_by_pos(LIST *list,int pos)
{
    if(list->head==NULL)
    {
        printf("LIST IS EMPTY\n");
        return;
    }
    if(pos<1 || pos>list->count)
    {
        printf("INVALID POS\n");
        return;
    }
    int p=1;
    NODE *temp=list->head;
    if(pos==p)
    {
        printf("%d node is found at %d pos\n",temp->data,pos);
        display(list);
    }
    else
    {
        do
        {
            temp=temp->link;
            p++;
        } while (temp!=NULL && pos!=p);

        printf("%d node is found at %d pos\n",temp->data,pos);
        display(list);
    }
}










void main()
{
    int choice,pos,key,value;
    LIST *list=(LIST *)malloc(sizeof(LIST));
    list->count=0;
    list->head=NULL;

    for(;;)
    {
        printf("CIRCULAR LINKED LIST OPERATION\n");
        printf("===============================\n");
        printf("1.INSERT FRONT\n2.INSERT REAR\n3.DELETE BY KEY\n4.SEARCH BY POS\n5.EXIT FROM THE PROGRAM\n");
        printf("Enter your choice\n");
          scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to be inserted at front\n");
              scanf("%d",&value);
            insert_front(list,value);
            break;
        case 2:
            printf("Enter the value to be inserted at rear\n");
              scanf("%d",&value);
            insert_rear(list,value);
            break;
        case 3:
            printf("Enter the pos to be deleted\n");
              scanf("%d",&pos);
            delete_by_pos(list,pos);
            break;
        case 4:
            printf("Enter the pos to be searched\n");
              scanf("%d",&pos);
            search_by_pos(list,pos);
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
