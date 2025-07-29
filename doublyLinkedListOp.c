//Operations using doubly linkedlist


#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node *prev;
struct Node *next;
};
struct Node *head = NULL;
void create(int n) {
struct Node *newNode, *temp;
int data, i;
for (i = 0; i< n; i++) {
newNode = (struct Node *)malloc(sizeof(struct Node));
if (newNode == NULL) {
printf("Memory allocation failed!\n");
return;
}
printf("Enter data for node %d: ", i + 1);
scanf("%d", &data);
newNode->data = data;
newNode->prev = NULL;
newNode->next = NULL;
if (head == NULL) {
head = newNode;
} else {
temp = head;
while (temp->next != NULL) {
temp = temp->next;
}
temp->next = newNode;
newNode->prev = temp;
}
}
}
void insertFirst(int data) {
struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
if (newNode == NULL) {
printf("List is Empty!\n");
}
newNode->data = data;
newNode->prev = NULL;
newNode->next = head;
if (head != NULL) {
head->prev = newNode;
}
head = newNode;
printf("Node inserted at the beginning.\n");
}
void insertLast(int data) {
struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
struct Node *temp;
if (newNode == NULL) {
printf("List is Empty!\n"); }
newNode->data = data;
newNode->next = NULL;
if (head == NULL) {
newNode->prev = NULL;
head = newNode;
} else {
temp = head;
while (temp->next != NULL) {

temp = temp->next;
}
temp->next = newNode;
newNode->prev = temp;
}
printf("Node inserted at the end.\n");
}
void deleteFirst() {
struct Node *temp;
if (head == NULL) {
printf("List is empty!\n");
}else{
temp = head;
head = head->next;
if (head != NULL) {
head->prev = NULL;
}
printf("Node deleted from the beginning: \n");
free(temp); }
}
void deleteLast() {
struct Node *temp;
if (head == NULL) {
printf("List is empty!\n");
return; }
temp = head;
while (temp->next != NULL) {
temp = temp->next;
}
if (temp->prev != NULL)
temp->prev->next = NULL;
else
head = NULL;
printf("Node deleted from the end: \n");
free(temp);
}
void traverseList() {
struct Node *temp;
if (head == NULL) {
printf("List is empty!\n");
return;
}
temp = head;
printf("Doubly Linked List: ");
while (temp != NULL) {
printf("%d <-> ", temp->data);
temp = temp->next;
}
printf("NULL\n");
}
int main() {
int choice, n, data;
printf("1. Create \n2. Insert at First \n3. Insert at Last \n4. Delete from First \n5. Delete from Last \n6. Traverse List\n7. Exit\n");
do{
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter the number of nodes: ");
scanf("%d", &n);
create(n);
break;
case 2:
printf("Enter the data to insert: ");
scanf("%d", &data);
insertFirst(data);
break;
case 3:
printf("Enter the data to insert: ");
scanf("%d", &data);
insertLast(data);
break;
case 4:
deleteFirst();
break;
case 5:
deleteLast();
break;
case 6:
traverseList();
break;
case 7:
printf("Exiting program.\n");
break;
default:
printf("Invalid choice! Please try again.\n");
}
} while (choice != 7);
return 0;
}