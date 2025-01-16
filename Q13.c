/*Develop a menu driven program to implement the following types of Queues by allocating memory
dynamically.
i) Circular Queue
ii) Priority Queue
Note: Define Queue structure and implement the operation with array representation */

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
    return q->front>q->rear ? 1 : 0;
}

int isfull(QUEUE *q)
{
    return q->rear==q->size-1 ? 1 : 0;
}

void Enqueue(QUEUE *q)
{
    if(isfull(q))
    {
        printf("Queue is full..reallocating memory\n");
        int newsize=q->size+1;
        int *newq=(int *)realloc(q->Q,newsize*sizeof(int));
        if(newq==NULL)
        {
            printf("reallocation failed\n");
            return;
        }
        q->Q=newq;
        q->size=newsize;
    }
    int item;
    printf("Enter the ele to be insertes\n");
      scanf("%d",&item);
    q->rear++;
    q->Q[q->rear]=item;
}

void ASC_PR(QUEUE *q)
{
    if(isEmpty(q))
    {
        printf("Queue is underflow\n");
        return;
    }
    int min,minindex;
    min=q->Q[q->front];
    minindex=q->front;
    for(int i=q->front;i<=q->rear;i++)
     if(q->Q[i] < min)
     {
        min=q->Q[i];
        minindex=i;
     }
    printf("deleted ele is:%d\n",q->Q[minindex]);
    for(int i=minindex;i<=q->rear;i++)
     q->Q[i]=q->Q[i+1];

    q->rear--;
}

void DSC_PR(QUEUE *q)
{
  if(isEmpty(q))
  {
    printf("Queue is underflow\n");
    return;
  }
  int max,maxindex;
  max=q->Q[q->front];
  maxindex=q->front;
  for(int i=q->front;i<=q->rear;i++)
    if(q->Q[i] > max)
    {
        max=q->Q[i];
        maxindex=i;
    }
  printf("Deleted ele is %d\n",q->Q[maxindex]);
  for(int i=maxindex;i<=q->rear;i++)
   q->Q[i]=q->Q[i+1];

   q->rear--;
}



/*void Enqueue(QUEUE *q)
{
    if(isfull(q))
    {
        printf("Queue is overflow..reallocating memory\n");
        int newsize=q->size+1;
        int *newq=(int *)realloc(q->Q,newsize*sizeof(int));
        if(newq==NULL)
        {
            printf("Reallocation failed\n");
            return;
        }
        q->Q=newq;
        q->size=newsize;
    }
    int j=q->rear;
    int i,item;
    printf("Enter the ele to be insertes\n");
      scanf("%d",&item);
    while (j>=0 && item<q->Q[j])
    {
        q->Q[j+1]=q->Q[j];
        j--;
    }
    q->Q[j+1]=item;
    q->rear++;
}

void ASC_PR(QUEUE *q)
{
    if(isEmpty(q))
    {
        printf("Queue is underflow\n");
        return;
    }
    printf("deleted ele %d\n",q->Q[q->front]);
    q->front++;
    if(q->front>q->rear)
    {
        q->front=0;
        q->rear=-1;
    }
}

void DSC_PR(QUEUE *q)
{
    if(isEmpty(q))
    {
        printf("Queue is underflow\n");
        return;
    }
    printf("Deleted ele %d\n",q->Q[q->rear]);
    q->rear--;
    if(q->front>q->rear)
    {
        q->front=0;
        q->rear=-1;
    }
}*/

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
        printf("PROIRITY QUEUE IMPLEMENTATION\n");
        printf("==============================\n");
        printf("1.ENQUEUE\n2.ASECENDING PRIORITY\n3.DESCENDING PRIORITY\n4.DISPLAY\n5.EXIT FROM THE PROGRAM\n");
        printf("Enter your choice\n");
          scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            Enqueue(&q);
            break;
        case 2:
            ASC_PR(&q);
            break;
        case 3:
            DSC_PR(&q);
            break;
        case 4:
            display(q);
            break;
        case 5:
            printf("Exiting from the program\n");
            free(q.Q);
            exit(0);
        default:
            printf("INVALID CHOICE\n");
            break;
        }
    }
}
