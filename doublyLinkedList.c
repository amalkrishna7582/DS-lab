
//To implement the following operations on a Doubly linked list. i. Creation , ii. Count the number of nodes, iii. Searching , iv. Traversal

#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
struct node *prev;
};
struct node* createnode(struct node* head)
{
struct node *p;
int value,n;
printf("Enter size : \n");
scanf("%d",&n);
if(n <= 0) {
printf("List size must be greater than 0.\n");
return 0;
}
for(int i=1;i<=n;i++)
{
struct node* temp = (struct node*)malloc(sizeof(struct node));
printf("Enter value to insert : \n");
scanf("%d",&value);
temp->data=value;
temp->prev=NULL;
temp->next=NULL;
if (head==NULL)
{
head=temp;
}
else
{
p=head;
while(p->next!=NULL)
{
p=p->next;
}
p->next=temp;

temp->prev=p;
}
}
return head;
}
void searchnode(struct node* head);
void noofnodes(struct node* head);
void traverse(struct node* head);
void main()
{
int ch,val;
struct node *head=NULL;
printf("Creating a linked list:\n");
head=createnode(head);
do
{
printf("Linked List Operations\n 1.Count No Of Nodes\n 2.Searching a node\n 3.Traversal\n 4.Exit\n");
printf("choose an operation:\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
{
printf("Node Count\n");
noofnodes(head);
break;
}
case 2:
{
printf("searching :\n");
searchnode(head);
break;
}
case 3:
{
printf("traversing :\n");
traverse(head);
break;
}
case 4:printf("exit\n");
break;
default:printf("Enter correct value : \n");
break;
}
}
while(ch!=4);
}

void searchnode(struct node* head)
{
struct node *ptr;
ptr=head;
int flag=0,pos=1,val;
printf("Enter value to search : \n");
scanf("%d",&val);
while(ptr!=NULL)
{
if(ptr->data==val)
{
flag=1;
printf("Item Present at position %d\n",pos);
break;
}
else
{
ptr=ptr->next;
pos=pos+1;
}
}
if(flag==0)
{
printf("Item Not Found\n");
}
}
void noofnodes(struct node* head)
{
struct node *ptr;
ptr=head;
int count=0;
while(ptr!=NULL)
{
ptr=ptr->next;
count=count+1;
}
printf("No of nodes is %d\n",count);
}
void traverse(struct node* head)
{
struct node *ptr;
ptr=head;
if(head==NULL)
{
printf("List empty...\n");
}

else
{
while(ptr!=NULL)
{
printf("%d<->",ptr->data);
ptr=ptr->next;
}
printf("NULL\n");
}
}