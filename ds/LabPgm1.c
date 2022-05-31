#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
	int i, n, ch;
	printf("IMPLEMENTATION OF SEARCHING TECHNIQUES\n");
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	int *arr=(int*)malloc(sizeof(int)*n);
	printf("Enter the array elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	int searchKey;
	printf("Enter the search Element: ");
	scanf("%d", &searchKey);
//	system("cls");
	printf("IMPLEMENTATION OF SEARCHING TECHNIQUES\n");
	printf("\n1.\tLinearSearch\n2.\tBinarySearch\n3.\tExit\n");
	printf("Choose the searching technique: ");
	scanf("%d", &ch);
	switch(ch)
	{
		case 1: {
		    for(i=0;i<n;i++)
            {
                if(searchKey==arr[i])
                {
                    printf("\nElement found at %d position",i+1);
                    break;
                }
            }
            if(i>=n)
            {
                printf("Element not found in the given array!\n");
            }
            getch();
            exit(1);
		}
		case 2: {
		    int first = 0, last = n-1, middle=(first+last)/2;
		    while(first<=last)
            {
                if(arr[middle]<searchKey)
                {
                    first=middle+1;
                }
                else if(arr[middle]==searchKey)
                {
                    printf("Element found at %d position",middle+1);
                    getch();
                    break;
                }
                else
                    last=middle-1;
                middle=(first+last)/2;
                if(first>last)
                {
                    printf("Element not found!");
                    getch();
                }
            }
		}
		case 3: exit(1);
		default: printf("\nInvalid Choice");break;
	}
}
