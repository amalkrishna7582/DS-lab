#include <stdio.h>
int max = 100;
int stack[100];
int top = -1;  
void push();
void pop();
void display();
int main() {
    int choice;
    do {
        printf("1. Insertion (Push) 2. Deletion (Pop) 3. Display 4. Exit \n");
        printf("\nEnter the choice:\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    return 0;
}
void push() {
    if (top == max - 1) {
        printf("Stack Overflow! Cannot push more elements.\n");
        return;
    }
    int value;
    printf("Enter element to insert: ");
    scanf("%d", &value);
    top++;                
    stack[top] = value;    
    printf("%d pushed onto stack.\n", value);
}
void pop() {
    if (top == -1) {
        printf("Stack Underflow! Nothing to pop.\n");
        return;
    }
    int value = stack[top]; 
    printf("%d popped from stack.\n", value);
    top--;                    
}

void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]); 
    }
}