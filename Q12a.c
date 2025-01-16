/*  Develop a menu driven program to implement the following types of Queues by allocating memory dynamically.
i) Circular Queue
ii) Double ended Queue
Note: Define Queue structure and implement the operation with array representation*/
#include<stdio.h>
#include<stdlib.h>

typedef struct queue
{
    int count;
    int size;
    int rear,front;
    int *Q;
}QUEUE;

void create(QUEUE *q,int size)
{
  q->count=0;
  q->front=0;
  q->rear=-1;
  q->size=size;
  q->Q=(int *)malloc(q->size*sizeof(int));
}

int isEmpty(QUEUE *q)
{
    return q->count==0 ? 1 : 0;
}

int isfull(QUEUE *q)
{
    return q->count==q->size ? 1 : 0;
}

void Enqueue(QUEUE *q)
{
    if(isfull(q))
    {
        printf("Queue is overflow...reallocationg memory\n");
        int newsize=q->size+1;
        int *newq=(int *)realloc(q->Q,newsize*sizeof(int));
        if(newq==NULL)
        {
            printf("Memory reallocation is failed\n");
            return;
        }
        q->Q=newq;
        q->size=newsize;
    }
    int item;
    printf("Enter the ele to be inserted\n");
      scanf("%d",&item);
    q->rear=(q->rear+1)%q->size;
    q->Q[q->rear]=item;
    q->count++;
}

void Dequeue(QUEUE *q)
{
    if(isEmpty(q))
    {
        printf("Queue is underflow\n");
        return;
    }
    printf("Deleted ele is %d\n",q->Q[q->front]);
    q->count--;
    q->front=(q->front+1)%q->size;
}

void display(QUEUE q)
{
   if(isEmpty(&q))
   {
    printf("QUEUE IS EMPTY\n");
    return;
   }
   int i,j;
   i=q.front;
   for(j=0;j<q.count;j++)
   {
    printf("%d ",q.Q[i]);
    i=(i+1)%q.size;
   }
   printf("\n");
}



void main()
{
    QUEUE q;
    int size,choice;
       printf("Enter the size of the queue\n");
         scanf("%d",&size);
       create(&q,size);

       for(;;)
       {
        printf("CIRCULAR QUEUE IMPLEMENTATION\n");
        printf("==============================\n");
        printf("1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT FROM THE PROGRAM\n");
        printf("Enter your choice\n");
          scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            Enqueue(&q);
            break;
        case 2:
            Dequeue(&q);
            break;
        case 3:
            display(q);
            break;
        case 4:
            printf("EXITING FROM THE PROGRAM\n");
            free(q.Q);
            exit(0);
        default:
            printf("INVALID CHOICE\n");
            break;
        }
       }

}
