/*  Implement circular double linked list to perform the following operations
i)
Insert by order ii) Delete rear iii) Delete Front iv) Search for an item by position Display the list
contents after each operation*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
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
    n->next=n->prev=NULL;

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
        temp=temp->next;
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
        n->next=n->prev=list->head;
    }
    else
    {
        n->next=list->head;
        n->prev=list->head->prev;
        list->head->prev->next=n;
        list->head->prev=n;
        list->head=n;
    }
    list->count++;
    display(list);
}


void insert_by_order(LIST *list,int value)
{
    if(list->head==NULL || value<=list->head->data)
    {
        insert_front(list,value);
        return;
    }
    NODE *temp=list->head;
    NODE *n=createnode(value);
    do
    {
        temp=temp->next;
    } while (temp!=list->head && temp->data<value);

    n->next=temp;
    n->prev=temp->prev;
    temp->prev->next=n;
    temp->prev=n;
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
    NODE *temp=list->head->prev;
    if(list->head==list->head->next)//single node
     list->head=NULL;
    else
    {
     temp->prev->next=list->head;
     temp->next->prev=temp->prev;
    }
    printf("%d is deleted\n",temp->data);
    free(temp);
    list->count--;
    display(list);
}


void delete_front(LIST *list)
{
    if(list->head==NULL)
    {
        printf("LIST IS EMPTY\n");
        return;
    }
    NODE *temp=list->head;
    if(list->head==temp->next)
     list->head=NULL;
    else
    {
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        list->head=temp->next;
    }
    printf("%d is deleted\n",temp->data);
    free(temp);
    list->count--;
    display(list);
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
    while (pos!=p)
    {
        temp=temp->next;
        p++;
    }
    printf("%d is dound at pos %d\n",temp->data,pos);
    display(list);

}













void main()
{
    int choice,pos,key,value;
    LIST *list=(LIST *)malloc(sizeof(LIST));
    list->count=0;
    list->head=NULL;

    for(;;)
    {
        printf("\nCIRCULAR DOUBLY LINKED LIST IMPLEMENTATION\n");
        printf("=============================================\n");
        printf("1.INSERT BY ORDER\n2.DELETE AT REAR\n3.DELETE AT FRONT\n4.SEARCH BY POS\n5.EXIT FROM THE PROGRAM\n");
        printf("Enter your choice\n");
          scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter the ele to be inserted\n");
              scanf("%d",&value);
            insert_by_order(list,value);
            break;
        case 2:
            delete_rear(list);
            break;
        case 3:
            delete_front(list);
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
