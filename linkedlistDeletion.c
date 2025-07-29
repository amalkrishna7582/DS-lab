//deletion of linkedlist 

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;

void create();
void traverse();
void deletefromBeg();
void deletefromEnd();
void deletefromPos();

int main() {
    int choice;
    create(); // Create the linked list first

    do {
        printf("\nMenu:\n");
        printf("1. Delete from the beginning\n");
        printf("2. Delete from the end\n");
        printf("3. Delete from any position\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                deletefromBeg();
                break;
            case 2:
                deletefromEnd();
                break;
            case 3:
                deletefromPos();
                break;
            case 4:
                traverse();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    // Free the allocated memory
    struct node *current = start;
    struct node *next_node;
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }

    return 0;
}

void create() {
    int n, item, i = 0;
    struct node *ptr, *temp;

    printf("Enter the number of nodes to insert: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("\nInvalid count\n");
        return;
    }

    while (i < n) {
        printf("Enter the value to insert: ");
        scanf("%d", &item);
        ptr = (struct node *)malloc(sizeof(struct node));
        ptr->data = item;
        ptr->next = NULL;

        if (start == NULL) {
            start = ptr; // First node
        } else {
            temp = start;
            while (temp->next != NULL) {
                temp = temp->next; 
            }
            temp->next = ptr;
        }
        i++;
    }
}

void traverse() {
    struct node *ptr = start;
    if (ptr == NULL) {
        printf("Linked list is empty\n");
    } else {
        printf("\nList is: ");
        while (ptr != NULL) {
            printf("%d", ptr->data);
            ptr = ptr->next;
            if (ptr != NULL) {
                printf(" -> ");
            }
        }
        printf(" -> NULL\n");
    }
}

void deletefromBeg() {
    if (start == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    struct node *temp = start;
    start = start->next;
    free(temp); 
    printf("Node deleted from the beginning.\n");
}

void deletefromEnd() {
    if (start == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    struct node *temp = start;
    if (temp->next == NULL) { 
        free(temp);
        start = NULL;
    } else {
        while (temp->next->next != NULL) {
            temp = temp->next; 
        }
        free(temp->next); 
        temp->next = NULL; 
    }
    printf("Node deleted from the end.\n");
}

void deletefromPos() {
    if (start == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    int pos, i;
    printf("Enter position to be deleted: ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }

    struct node *temp = start;

    if (pos == 1) { 
        start = start->next;
        free(temp);
        printf("Node deleted from position %d.\n", pos);
        return;
    }

    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next ; 
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position does not exist.\n");
        return;
    }

    struct node *node_to_delete = temp->next; 
    temp->next = node_to_delete->next; 
    free(node_to_delete); 
    printf("Node deleted from position %d.\n", pos);
}