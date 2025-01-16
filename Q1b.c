/*Define a structure called Time containing 3 integer members (hour, minute,
second). Develop a menu driven program to perform the following by writing
separate function for each operation.
 a) Read (T): To read time b) Display (T):To display time c) update(T):To
Update time d) Add (T1, T2) : Add two times.
Update function increments the time by one second and returns the new time
(if the increment results in 60 seconds, then the second member is set to zero
and minute member is incremented by one. If the result is 60 minutes, the
minute member is set to zero and the hour member is incremented by one.
Finally, when the hour becomes 24, Time should be reset to zero. While
adding two time variable, normalize the resultant time value as in the case of
update function.
Note: Illustrate the use of pointer to pass time variable to different functions. */

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct time
{
    int hour;
    int min;
    int sec;
};

 void readtime(struct time *t)
 {
    printf("Enter the time in the form (hh:mm:ss)\n");
      scanf("%d %d %d",&t->hour,&t->min,&t->sec);
 }

 void display(struct time *t)
 {
    printf("%d:%d:%d\n",t->hour,t->min,t->sec);
 }

 void update(struct time *t)
 {
     t->sec++;
    if(t->sec==60)
    {
        t->sec=0;
        t->min++;
    }
    if(t->min==60)
    {
        t->min=0;
        t->hour++;
    }
    if(t->hour==24)
    {
      t->hour=0;
      t->min=0;
      t->sec=0;
    }
 }

 struct time addtimes(struct time *t1,struct time *t2)
 {
    struct time result;
    result.sec=t1->sec + t2->sec;
    result.min=t1->min + t2->min;
    result.hour=t1->hour + t2->hour;

    if(result.sec>=60)
    {
        result.sec-=60;
        result.min++;
    }
    if(result.min>=60)
    {
        result.min-=60;
        result.hour++;
    }
   /* if(result.hour>=24)
      result.hour-=24;*/

    if(result.hour>=12)
      result.hour-=12;

      return result;

 }

 int main()
 {
    struct time t1,t2,result;
    int choice;
    do
    {
      printf("\n..***Main Menu***..\n");
      printf("\n1.read time\n2.display time\n3.update time\n4.add times\n5.exit from the program\n");
      printf("Enter your choice\n");
        scanf("%d",&choice);

      switch (choice)
      {
      case 1:
        readtime(&t1);
        break;
      case 2:
        display(&t1);
        break;
      case 3:
        update(&t1);
        display(&t1);
        break;
      case 4:
        readtime(&t1);
        readtime(&t2);
        result=addtimes(&t1,&t2);
        display(&result);
        break;
      case 5:
        printf("\nExiting from the program\n");
        exit(1);
      default:
        printf("INVALID CHOICE\n");
        break;
      }
    } while (choice!=5);
    getch();
 }
