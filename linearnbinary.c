#include <stdio.h>

void linear(int a[], int size, int num);
void binary(int a[], int size, int num);
void sort(int a[], int size);

int main() {
    int a[100], size, choice, num;

    printf("Enter size of the array : ");
    scanf("%d", &size);

    printf("Enter values to the array:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }

    do {
        printf("\nSelect any one of the choices:\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to search (Linear Search): ");
                scanf("%d", &num);
                linear(a, size, num);
                break;
            case 2:
                sort(a, size);
                printf("Enter element to search (Binary Search): ");
                scanf("%d", &num);
                binary(a, size, num);
                break;
            case 3:
             
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

void linear(int a[], int size, int num)
{
    int found = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] == num)
        {
            found = 1;
            printf("Number %d found at index %d (Linear Search)\n", num, i);
            break;
        }
    }
    if (!found)
    {
        printf("Number %d not found (Linear Search)\n", num);
    }
}

void binary(int a[], int size, int num)
{
    int low = 0, high = size - 1, mid;
    int found = 0;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == num)
        {
            found = 1;
            printf("Number %d found at index %d (Binary Search)\n", num, mid);
            break;
        }
        else if (a[mid] < num)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (found==0)
    {
        printf("Number %d not found (Binary Search)\n", num);
    }
}

void sort(int a[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
