#include<stdlib.h>
#include<stdio.h>

int inputArr[25], size, i, j;

void bubbleSort(int a[], int n)
{
    int temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("\nArray sorted in Ascending Order using Bubble Sort: \n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}

void selectionSort(int d[], int n)
{
    int least,temp;
    for(i=0;i<n;i++)
    {
        least=i;
        for(j=i+1;j<n;j++)
        {
            if(d[j]<d[least])
            {
                least=j;
            }
        }
        temp=d[least];
        d[i]=d[least];
        d[least]=temp;
    }
    printf("\nArray sorted in Descending Order using Selection Sort: \n");
    for(i=n-1;i>=0;i--)
    {
        printf("%d\t",d[i]);
    }
}

void main()
{
    system("cls");
    printf("Enter the number of elements: ");
    scanf("%d",&size);
    printf("Enter %d elements: \n",size);
    for(i=0;i<size;i++)
    {
        scanf("%d",&inputArr[i]);
    }
    bubbleSort(inputArr,size);
    selectionSort(inputArr,size);
}
