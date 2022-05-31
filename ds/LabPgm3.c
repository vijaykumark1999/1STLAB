#include<stdio.h>
#include<conio.h>

void main()
{
    int i,n,ch;
    printf("IMPLEMENTATION OF STACK OPERATIONS\n");
	printf("Enter the number of elements in the stack: ");
	scanf("%d", &n);
	int *stk=(int*)malloc(sizeof(int)*n);
	int top=-1;
	do
	{
	    printf("1.\tPUSH\n2.\tPOP\n3.\tDISPLAY\n4.\tEXIT");
	    printf("\nChoice: ");
	    scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            {
                if(top==n-1)
                {
                    printf("Stack is full!Overflow!\n");
                    getch();
                    break;
                }
                else
                {
                    printf("Enter the element: ");
                    top++;
                    scanf("%d",&stk[top]);
                }
                break;
            }
        case 2:
            {
                if(top==-1)
                {
                    printf("Stack is empty!Underflow!\n");
                    getch();
                    break;
                }
                else
                {
                    printf("Element Popped: %d \n",stk[top]);
                    top--;
                }
                break;
            }
        case 3:
            {
                if(top==-1)
                {
                    printf("Empty Stack!\n");
                    getch();
                    break;
                }
                else
                {
                    for(i=0;i<=top;i++)
                    {
                        printf("%d\t",stk[i]);
                    }
                    getch();
                }
                break;
            }
            case 4: exit(1);
            default: printf("Invalid Choice\n");
        }
	}while(ch!=4);
}
