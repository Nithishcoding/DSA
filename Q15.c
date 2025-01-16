/*  Develop a menu driven program to implement Binary Search tree with the following operations.
i)
Construction ii) Traversals (Pre, In and Post Order) iii) Searching a node by key and deleting if
exists ( node to be deleted may be leaf or non- leaf with one child or two children) */
#include<stdio.h>
#include<stdlib.h>
int count=0;
typedef struct node
{
    int data;
    struct node *lchild,*rchild;
}NODE;

/*NODE *createnode()
{
    NODE *n=(NODE *)malloc(sizeof(NODE));
    printf("Enter the value\n");
      scanf("%d",&n->data);
    n->lchild=n->rchild=NULL;

    return n;
}*/

/*NODE *insert(NODE *root)//iterative method
{
    NODE *temp=createnode();
    NODE *cur=root;
    NODE *prev;
    while (cur!=NULL)
    {
        prev=cur;
        if(temp->data < cur->data)
          cur=cur->lchild;
        else
          cur=cur->rchild;
    }
    if(temp->data < prev->data)
      prev->lchild=temp;
    else
      prev->rchild=temp;

    return root;
}*/

NODE* insert(NODE *temp,int ele)//recursive call
{
  NODE *t;
  if(temp==NULL)
  {
    t=(NODE *)malloc(sizeof(NODE));
    t->data=ele;
    t->lchild=t->rchild=NULL;

    return t;
  }

  if(ele < temp->data)
    temp->lchild=insert(temp->lchild,ele);
  else
    temp->rchild=insert(temp->rchild,ele);

  return temp;
}


void inorder(NODE *temp)
{
    if(temp!=NULL)
    {
    inorder(temp->lchild);
    printf("%d ",temp->data);
    inorder(temp->rchild);
    }
}

void postorder(NODE *temp)
{
    if(temp!=NULL)
    {
    postorder(temp->lchild);
    postorder(temp->rchild);
    printf("%d ",temp->data);
    }
}

void preorder(NODE *temp)
{
    if(temp!=NULL)
    {
    printf("%d ",temp->data);
    preorder(temp->lchild);
    preorder(temp->rchild);
    }
}

void Search(NODE *root,int key)
{
  NODE *temp=root;
  NODE *prev=NULL;
   while (temp!=NULL)
   {
     if(key==temp->data)
     {
       printf("%d is found\n",temp->data);
       if(temp->data==root->data)
       {
        printf("%d parent does not exit because %d is root node\n",temp->data,temp->data);
        break;
       }
       else
       {
        printf("%d key's parent is %d\n",temp->data,prev->data);
        break;
       }
     }
     else if(key < temp->data)
     {
      prev=temp;
      temp=temp->lchild;
     }

     else
     {
      prev=temp;
      temp=temp->rchild;
     }

   }
   if(temp==NULL)
    printf("%d key is not found\n",key);
}

int count_nodes(NODE *temp)
{
  /* if(temp==NULL)
    return;
   count_nodes(temp->lchild);
   count++;
   count_nodes(temp->rchild);*/
   if(temp!=NULL)
    return count_nodes(temp->lchild)+count_nodes(temp->rchild)+1;
   else
    return 0;

}


int MAX(int a,int b)
{
  return a>b ? a:b;
}

int height(NODE *temp)
{
  if(temp==NULL)
   return 0;
  return 1+MAX(height(temp->lchild),height(temp->rchild));
}

/*int height(NODE *temp)
{
  int x,y;
  if(temp!=NULL)
  {
    x=height(temp->lchild);
    y=height(temp->rchild);
    if(x>y)
     return x+1;
    else
     return y+1;
  }

  return 0;
}*/

void MAXNODE(NODE *temp)
{
  NODE *prev;
   if(temp==NULL)
   {
    printf("Tree is empty\n");
    return;
   }
   while (temp->rchild!=NULL)
   {
    prev=temp;
    temp=temp->rchild;
   }
   printf("MAX NODE IS %d\n",temp->data);
   printf("parent of the max node is:%d\n",prev->data);
}

NODE *Inpre(NODE *p)
{
  while (p && p->rchild!=NULL)
  {
    p=p->rchild;
  }
  return p;

}

NODE *Insuc(NODE *p)
{
  while (p && p->lchild!=NULL)
  {
    p=p->lchild;
  }
  return p;

}





NODE *delete_node(NODE *root,int key)
{
  NODE *temp=root;
  NODE *q;
  int flag=0;
  if(root==NULL)
   return NULL;
  if(temp->lchild==NULL && temp->rchild==NULL)
  {
    if(temp==root)
     root=NULL;
    free(temp);
    return NULL;
  }
  if(key < temp->data)
    temp->lchild=delete_node(temp->lchild,key);
  else if(key > temp->data)
    temp->rchild=delete_node(temp->rchild,key);
  else
  {
    if(height(temp->lchild) > height(temp->rchild))
    {
      q=Inpre(temp->lchild);
      temp->data=q->data;
      temp->lchild=delete_node(temp->lchild,q->data);
    }
    else
    {
      q=Insuc(temp->rchild);
      temp->data=q->data;
      temp->rchild=delete_node(temp->rchild,q->data);
    }
    flag=1;
  }
  if(flag==0)
   printf("%d node is not found\n",key);
  return temp;
}

/*NODE *delete_node(NODE *root,int key)
{
  NODE *temp=root;
  NODE *q;
  if(root==NULL)
   return NULL;
  if(temp->lchild==NULL && temp->rchild==NULL)
  {
    if(temp==root)
     root=NULL;
    free(temp);
    return NULL;
  }
  if(key < temp->data)
    temp->lchild=delete_node(temp->lchild,key);
  else if(key > temp->data)
    temp->rchild=delete_node(temp->rchild,key);
  else
  {
    if(height(temp->lchild) > height(temp->rchild))
    {
      q=Inpre(temp->lchild);
      temp->data=q->data;
      temp->lchild=delete_node(temp->lchild,q->data);
    }
    else
    {
      q=Insuc(temp->rchild);
      temp->data=q->data;
      temp->rchild=delete_node(temp->rchild,q->data);
    }
  }
  return temp;
}*/


/*NODE *delete_node(NODE *root, int key) {
    NODE *temp = root;
    NODE *q;

    if (root == NULL)
        return NULL;

    if (key < temp->data)
        temp->lchild = delete_node(temp->lchild, key);
    else if (key > temp->data)
        temp->rchild = delete_node(temp->rchild, key);
    else {
        if (temp->lchild != NULL && temp->rchild != NULL) {
            if (height(temp->lchild) > height(temp->rchild)) {
                q = Inpre(temp->lchild);
                temp->data = q->data;
                temp->lchild = delete_node(temp->lchild, q->data);
            } else {
                q = Insuc(temp->rchild);
                temp->data = q->data;
                temp->rchild = delete_node(temp->rchild, q->data);
            }
        } else {
            NODE *to_delete = temp;
            if (temp->lchild != NULL)
                temp = temp->lchild;
            else
                temp = temp->rchild;
            free(to_delete);
        }
    }
    return temp; // Add this line to return the updated root
}*/




void main()
{
    int ch,ele,key,C,H;
   // NODE *Search=NULL;
   // NODE *root=createnode();//for iterative
     NODE *root=NULL;
    printf("\n1.INSERT\n2.INORDER\n3.PREORDER\n4.POSTORDER\n5.SEARCH THE NODE\n6.COUNT ALL THE NODES\n7.HEIGHT OF THE TREE\n8.MAX NODE\n9.DELETION OF THE NODE\n10.EXIT FROM THE PROGRAM\n");

    while (1)
    {
        printf("\nEnter your choice\n");
         scanf("%d",&ch);
         switch (ch)
         {
         case 1:
            printf("Enter the value\n");
             scanf("%d",&ele);
            root=insert(root,ele);
            break;
         case 2:
            inorder(root);
            break;
         case 3:
            preorder(root);
            break;
         case 4:
            postorder(root);
            break;
         case 5:
            printf("Enter the key to be searched\n");
             scanf("%d",&key);
             Search(root,key);
             break;
           /* Search=R_SEARCH(root,key);
            if(Search!=NULL)
            {
              printf("%d key is found\n",Search->data);
            }   */
         case 6:
           C=count_nodes(root);
           printf("count=%d\n",C);
           break;
         case 7:
           H=height(root);
           printf("Height of the tree is %d\n",H);
           break;
         case 8:
           MAXNODE(root);
           break;
         case 9:
           printf("Enter the key to be deleted\n");
            scanf("%d",&key);
           root=delete_node(root,key);
           break;
         case 10:
           printf("Exiting from the program\n");
           exit(0);
         default:
            break;
         }
    }

}
