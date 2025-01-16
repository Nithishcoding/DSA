#include<stdio.h>
#include<stdlib.h>

typedef struct queue
{
    int size;
    int rear,front;
    int *Q;
}QUEUE;

void create(QUEUE *q,int size)
{
    q->front=0;
    q->rear=-1;
    q->size=size;
    q->Q=(int *)malloc(q->size*sizeof(int));
}

int isEmpty(QUEUE *q)
{
    return q->front > q->rear ? 1 : 0;
}

int isfull(QUEUE *q)
{
    return q->rear==q->size-1 && q->front==0 ? 1: 0;
}

void insert_front(QUEUE *q)
{
    if(isfull(q))
    {
        printf("Queue is overflow....reallocating memory\n");
        int newsize=q->size+1;
        int *newq=(int *)realloc(q->Q,newsize*sizeof(int));
        if(newq==NULL)
        {
            printf("reallocating memory failed\n");
            return;
        }
        q->Q=newq;
        q->size=newsize;
    }
    if(q->front==0 && q->rear==-1)
    {
        int item;
        printf("Enter the ele to be inserted at front\n");
          scanf("%d",&item);
        q->rear++;
        q->Q[q->rear]=item;
   }
   else if(q->front!=0)
   {
     int item;
        printf("Enter the ele to be inserted at front\n");
          scanf("%d",&item);
        q->front--;
        q->Q[q->front]=item;  
   }
   else
     printf("INSERTION AT FRONT IS NOT POSSINBLE\n");
}

void insert_rear(QUEUE *q)
{
    if(isfull(q))
    {
      printf("Queue is overflow...reallocating memory\n");
      int newsize=q->size+1;
      int *newq=(int *)realloc(q->Q,newsize*sizeof(int));
      if(newq==NULL)
      {
        printf("Reallocating memory failed\n");
        return;
      }
      q->Q=newq;
      q->size=newsize;
    }
    int item;
      printf("Enter the ele to be insertes at rear\n");
        scanf("%d",&item);
      q->rear++;
      q->Q[q->rear]=item;  
}

void delete_front(QUEUE *q)
{
    if(isEmpty(q))
    {
        printf("Queue is underflow\n");
        return;
    }
    printf("Deleted ele at front is %d\n",q->Q[q->front]);
    q->front++;
    if(q->front > q->rear)
    {
        q->front=0;
        q->rear=-1;
    }
}

void delete_rear(QUEUE *q)
{
    if(isEmpty(q))
    {
        printf("Queue is underflow\n");
        return;
    }
    printf("Deleted ele at rear is %d\n",q->Q[q->rear]);
    q->rear--;
    if(q->front > q->rear)
    {
        q->front=0;
        q->rear=-1;
    }
}

void display(QUEUE q)
{
    if(isEmpty(&q))
    {
        printf("Queue is empty\n");
        return;
    }
    for(int i=q.front;i<=q.rear;i++)
      printf("%d ",q.Q[i]);
    printf("\n");       
}

void main()
{
    QUEUE q;
    int choice,size;
      printf("Enter the size of the queue\n");
        scanf("%d",&size);
    create(&q,size);
    for(;;)
    {
        printf("DOUBLE ENDED QUEUE IMPLEMENTATION\n");
        printf("==================================\n");
        printf("1.INSERT FRONT\n2.INSERT REAR\n3.DELETE FRONT\n4.DELETE REAR\n5.DISPLAY\n6.EXIT FROM THE PROGRAM\n");
        printf("Enter your choice\n");
          scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            insert_front(&q);
            break;
        case 2:
            insert_rear(&q);
            break;
        case 3:
            delete_front(&q);
            break;
        case 4:
            delete_rear(&q);
            break;
        case 5:
            display(q);
            break;    
        case 6:
            printf("Exiting from the program\n");
            free(q.Q);
            exit(0);                
        default:
            printf("INVALID CHOICE\n");
            break;
        }  
    }    
}