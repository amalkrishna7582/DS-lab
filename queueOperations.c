#include<stdio.h>
#include<stdlib.h>
# define SIZE 100
void enqueue();
void dequeue();
void show();
int input_arr[SIZE];
int REAR = -1;
int FRONT = -1;
void main()
{
int ch;
while(1)
{
printf("1.Queue Operation\n");
printf("2.Dequeue Operation\n");
printf("3.Display the Queue\n");
printf("4.EXIT\n");
printf("Enter the choice of operations:");
scanf("%d",&ch);
switch(ch)
{
case 1:
enqueue();
break;
case 2:
dequeue();
break;
case 3:
show();
break;
case 4:
exit(0);
default:
printf("Incorrect choice  : \n");

}
}
}

void enqueue()
{
int insert_item;
if (REAR == SIZE-1)
printf("Overflow...!\n");
else
{
if (FRONT == -1)
FRONT = 0;
printf("Element to be inserted in the queue  :  \n");
scanf("%d",&insert_item);
REAR = REAR + 1;
input_arr[REAR] = insert_item;
}
}

void dequeue()
{
if (FRONT == -1 || REAR == -1)
{
printf("Underflow...! \n");
return;
}
else
{
printf("Element deleted from the queue : %d\n",input_arr[FRONT]);
FRONT = FRONT +1;
}
}

void show()
{
if (FRONT == -1)
printf("Empty Queue...\n");
else
{
printf("Queue \n");
for(int i=FRONT; i<=REAR; i++)
printf("%d\n",input_arr[i]);
printf("\n");
}
}
