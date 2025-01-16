/*Implement circular double linked list to perform the following operations
i) Insert front ii) Insert rear iii) Delete by position iv) Search by key Display the list
contents after each operation */

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
        n->prev=list->head->prev;
        list->head->prev->next=n;
        n->next=list->head;
        list->head->prev=n;
        list->head=n;
    }
    printf("%d inserted at front\n",n->data);
    list->count++;
    display(list);
}

void insert_rear(LIST *list,int value)
{
    if(list->head==NULL)
    {
        insert_front(list,value);
    }
    else
    {
        NODE *temp=list->head->prev;
        NODE *n=createnode(value);
        n->next=temp->next;
        temp->next->prev=n;
        n->prev=temp;
        temp->next=n;
        printf("%d inserted at rear\n",n->data);
        list->count++;
        display(list);
    }
}

void delete_front(LIST *list)
{
    NODE *temp=list->head;
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    list->head=temp->next;
    if(list->head==temp)
      list->head=NULL;
    printf("%d deleted\n",temp->data);
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
    if(pos<1 || pos>list->count)
    {
        printf("INVALID POS\n");
        return;
    }

    NODE *temp=list->head;
    if(pos==1)
    {
        delete_front(list);
        return;
    }
    for(int i=0;i<pos-1;i++)
     temp=temp->next;

    temp->next->prev=temp->prev;
    temp->prev->next=temp->next;
    printf("%d node deleted\n",temp->data);
    free(temp);
    list->count--;
    display(list);
}

void search_by_key(LIST *list,int key)
{
    if(list->head==NULL)
    {
        printf("LIST IS EMPTY\n");
        return;
    }
    NODE *temp=list->head;
    int pos=1;
    if(key==temp->data)
     printf("%d key is found at %d pos\n",temp->data,pos);
    else
    {
        do
        {
            temp=temp->next;
            pos++;
        } while (temp!=list->head && temp->data!=key);

        if(temp==list->head)
          printf("%d key is not found\n",key);
        else
        {
            printf("%d found at %d pos\n",temp->data,pos);
            display(list);
        }
    }
}











void main()
{
    int choice,key,pos,value;
    LIST *list=(LIST *)malloc(sizeof(LIST));
    list->count=0;
    list->head=NULL;

    for(;;)
    {
        printf("CIRCULAR DOUBLY LINKED LIST IMPLEMENTATION\n");
        printf("===========================================\n");
        printf("1.INSERT FRONT\n2.INSERT REAR\n3.DELETE BY POS\n4.SEARCH BY KEY\n5.EXIT FROM THE PROGRAM\n");
        printf("Enter your choice\n");
          scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to be inserted\n");
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
            printf("Enter the key to be searched\n");
              scanf("%d",&key);
            search_by_key(list,key);
            break;
        case 5:
            printf("Exiting from the program\n");
            free(list);
            exit(0);
        default:
            printf("INVALID CHOICE\n");
            break;
        }
    }
}
