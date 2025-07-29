#include <stdio.h>
#define MAX 100

int queue[MAX], count = 0;
int front = -1, rear = -1;

void enqueue();
void dequeue();
void display();

int main() {
    int choice;
    do {
        printf("Enter your choice\n");
        printf("1. Enqueue 2. Dequeue 3. Display 4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);
    return 0;
}

void enqueue() {
    if (count == MAX) {
        printf("Circular queue is full\n");
        return;
    }
    
    int data;
    printf("The element to be inserted:\n");
    scanf("%d", &data);
    
    if (front == -1) { 
        front = 0;
    }
    
    rear = (rear + 1) % MAX; 
    queue[rear] = data;
    count++;
}

void dequeue() {
    if (count == 0) {
        printf("Circular queue is empty\n");
        return;
    }
    int data = queue[front];
    printf("Deleted element: %d\n", data);
    front = (front + 1) % MAX; 
    count--;
    
    if (count == 0) { 
        front = -1;
        rear = -1;
    }
}

void display() {
    if (count == 0) {
        printf("Queue is empty:\n");
        return;
    }
    
    printf("Queue elements are:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", queue[(front + i) % MAX]); 
    }
    printf("\n");
}