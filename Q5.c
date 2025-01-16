/*Implement circular double linked list to perform the following operations
i) Insert by order ii ) Delete by position iii ) Delete by key iv) Search by position Display the list contents
after each operation
*/

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
    NODE *n=(NODE*)malloc(sizeof(NODE));
    if(n==NULL)
    {
        printf("Memory allocation is failed\n");
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
        n->prev=list->head->prev;
        list->head->prev->next=n;
        n->next=list->head;
        list->head->prev=n;
        list->head=n;
    }
    list->count++;
    display(list);
}

void insert_by_order(LIST *list,int value)
{
    if(list->head==NULL || value <= list->head->data)
    {
        insert_front(list,value);
    }
    else
    {
     NODE *n=createnode(value);
     NODE *temp=list->head;
     do
     {
         temp=temp->next;
     } while (temp!=list->head && temp->data < value);

     n->next=temp;
     n->prev=temp->prev;
     temp->prev->next=n;
     temp->prev=n;
     list->count++;
     display(list);
    }
}

void delete_by_pos(LIST *list,int pos)
{
    if(list->head==NULL)
    {
        printf("LIST IS EMPTY\n");
        return;
    }
    if(pos<1 || pos > list->count)
    {
        printf("INVALID POS\n");
        return;
    }

    NODE *temp=list->head;
    for(int i=0;i<pos-1;i++)
      temp=temp->next;

    if(temp==list->head)
    {
        list->head=temp->next;
        if(list->head==temp)
         list->head=NULL;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    printf("node present is %d pos is %d is deleted\n",pos,temp->data);
    free(temp);
    list->count--;
    display(list);
}

void delete_front(LIST *list,int key)
{
    NODE *temp=list->head;
    list->head=temp->next;
     if(list->head==temp)
        list->head=NULL;
     printf("%d key is deleted\n",temp->data);
     list->count--;
     free(temp);
}

void delete_by_key(LIST *list,int key)
{
    if(list->head==NULL)
    {
        printf("LIST IS EMPTY\n");
        return;
    }
    NODE *temp=list->head;
    if(key==temp->data)
    {
        delete_front(list,key);
    }
    else
    {
        do
        {
            temp=temp->next;
        }while(temp!=list->head && temp->data!=key);
        if(temp==list->head)
        {
            printf("%d key is not found\n",key);
            return;
        }
        temp->next->prev=temp->prev;
        temp->prev->next=temp->next;
        printf("%d key is deleted\n",temp->data);
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
        return;
    }
    do
    {
        temp=temp->next;
        p++;
    } while (temp!=list->head && pos!=p);

    printf("%d node is found at %d pos\n",temp->data,pos);
    display(list);
}






void main()
{
    int choice,value,pos,key;
    LIST *list=(LIST *)malloc(sizeof(LIST));
    list->head=NULL;
    list->count=0;

    for(;;)
    {
        printf("CIRCULAR DOUBLY LINKED LIST IMPLEMENTATION\n");
        printf("===========================================\n");
        printf("1.INSERT BY ORDER\n2.DELETE BY POSITION\n3.DELETE BY KEY\n4.SEARCH BY POS\n5.EXIT FROM THE PROGRAM\n");
        printf("Enter your choice\n");
          scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter the node to be inserted\n");
              scanf("%d",&value);
            insert_by_order(list,value);
            break;
        case 2:
            printf("Enter the pos to be deleted\n");
              scanf("%d",&pos);
            delete_by_pos(list,pos);
            break;
        case 3:
            printf("Enter the key to be deleted\n");
              scanf("%d",&key);
            delete_by_key(list,key);
            break;
        case 4:
            printf("Enter the pos to be searched\n");
              scanf("%d",&pos);
            search_by_pos(list,pos);
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
