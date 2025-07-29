#include<stdio.h>
void main()
{
    int n,i,j,temp;
    int a[10];
    printf("Enter the limit:");
    scanf("%d",&n);
    printf("Enter the elements:");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
            }
        }
    }
    printf("Sorted array is:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
}