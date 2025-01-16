#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct 
{
    char name[30];
    char regno[20];
    int marks[3];
    float avgmarks;
}student;

void read(student *s,int n)
{
    printf("Enter the students details\n");
    for(int i=0;i<n;i++)
    {
        printf("Enter %d student details:\n",(i+1));
        printf("Enter the name of the student:\n");
          scanf("%s",s[i].name);
        printf("Enter the register number of the student\n");
          scanf("%s",s[i].regno);
        printf("Enter the 3 test marks\n");
        for(int j=0;j<3;j++)
         scanf("%d",&s[i].marks[j]);    
    }
}



float calculateAverage(int a, int b, int c)
{
     if(a<=b && a<=c)
      return (b+c)/2.0;
    else if(b<=a && b<=c)
      return (a+c)/2.0;
    else
      return (a+b)/2.0;    
}


void calavg(student *s, int n)
{
    for (int i = 0; i < n; i++)
    {
        s[i].avgmarks = calculateAverage(s[i].marks[0], s[i].marks[1], s[i].marks[2]);
        printf("\nAverage of best two marks of %d student is: %.2f\n", i + 1, s[i].avgmarks);
    }
}

void display(student *s,int n)
{
    printf("***STUDENT DETAILS***\n");
    printf("======================\n");
    for(int i=0;i<n;i++)
    {
        printf("STUDENT NAME:%s\n",s[i].name);
        printf("REGISTER NO OF STUDENT:%s\n",s[i].regno);
        for(int j=0;j<3;j++)
          printf("MARKS OF TEST %d:%d\n",(j+1),s[i].marks[j]);
    }
    calavg(s,n);

}

void main()
{
    int n,choice;
       printf("Enter the value of n:");
         scanf("%d",&n);     
    student *s=(student *)malloc(n*sizeof(student));//dynamic memory allocation to array of structures
    for(;;)
    {
        printf("STUDENT DETAILS\n");
        printf("----------------\n");
        printf("1.READ THE STUDENTS DETAILS\n2.DISPLAY THE STUDENTS INFORMATION\n3.TO CALCULATE THE AVERAGE OF BEST TWO MARKS\n4.STOP THE PROGRAM\n");
        printf("Enter your choice\n");
          scanf("%d",&choice);
        switch(choice)
        {
            case 1:
              read(s,n);
              break;
            case 2:
              display(s,n);
              break;
            case 3:
              calavg(s,n);
              break;
            case 4:
              free(s);
              printf("EXITING FROM THE PROGRAMn");
              exit(0);
            default:
              printf("INVALID CHOICE\n");
              break;    
        }  
    }
}