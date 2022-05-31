#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct llist
{
    int data;
    struct llist *next;
};

typedef struct llist node;
node *head, *ptr, *new1;
int choice, count=0;

void countNodes()
{
    count = 0;
    ptr = head;
    while (ptr!=NULL)
    {
        ptr = ptr->next;
        count++;
    }
}

void displayMenu()
{
    system("cls");
    printf("LINKED LIST OPERATIONS\n\n");
    printf("1.\tDisplay and Insert\n2.\tDelete from beginning/end\n3.\tDelete a given element\n4.\tExit\n");
    printf("\nChoice: ");
}

void displayLL()
{
    printf("\nLinkedList elements:\n");
    ptr = head;
    while(ptr != NULL)
    {
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    }
    getch();
}

void insertNodeAtEnd()
{
    ptr = head;
    while(ptr != NULL)
    {
        ptr = ptr->next;
    }
    new1 = (node*)malloc(sizeof(node));
    printf("\nEnter data: ");
    scanf("%d",&ptr->data);
    ptr->next = new1;
    ptr = new1;
}

void insertNodeInBegin()
{
    new1 = (node*)malloc(sizeof(node));
    ptr = new1;
    printf("\nEnter data: ");
    scanf("%d",&ptr->data);
    ptr->next = head;
    head = new1;
}

void insertNodeAtN()
{
    int pos,i;
    node *new2,*loc;
    printf("Enter position: ");
    scanf("%d",&pos);
    countNodes();
    if(pos>count)
    {
        printf("\nInvalid position!");
        return;
    }
    else
    {
        new2=(node*)malloc(sizeof(node));
        printf("\nEnter data: ");
        scanf("%d",&new2->data);
        new2->next=NULL;
        if(pos==1)
        {
            new2->next=head;
            head=new2;
        }
        else
        {
            loc=head;
            for(i=2;i<pos;i++)
            {
                loc=loc->next;
            }
            new2->next=loc->next;
            loc->next=new2;
        }
    }
}

void insertNodeMenu()
{
    do
    {
        printf("\n\n1.\tInsert at beginning\n2.\tInsert at end\n3.\tInsert at Nth Position\n4.\tReturn to main menu\n");
        printf("Choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1: {
                insertNodeInBegin();break;
            }
            case 2: {
                insertNodeAtEnd();break;
            }
            case 3: {
                insertNodeAtN();break;
            }
            case 4 : {
                break;
            }
            default: printf("WrongInput!");break;
        }
    }while(choice != 4);
}

void deleteNodeBegin()
{
    ptr = head;
    if (ptr!= NULL)
    {
        new1 = head;
        head = head->next;
        printf("\nDeleted element: %d", ptr->data);
        getch();
        free(ptr);
    }
    else
    {
        printf("\nLinked List is empty\n");
        getch();
    }
}

void deleteNodeEnd()
{
    ptr = head;
    if(ptr!= NULL)
    {
        while(ptr->next!=NULL)
        {
            new1=ptr;
            ptr = ptr->next;
        }
        printf("\nDeleted element: %d", ptr->data);
        new1->next=NULL;
        getch();
        free(ptr);
    }
    else
    {
        printf("Linked List is empty!\n");
        getch();
    }
}
void deleteNodeMenu()
{
    do
    {
        system("cls");
        printf("1.\tDelete from beginning\n2.\tDelete from end\n3.\tReturn to main menu\n");
        printf("Choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1: {
                deleteNodeBegin();break;
            }
            case 2: {
                deleteNodeEnd();break;
            }
            case 3: {
                break;
            }
            default: printf("WrongInput!");break;
        }
    }while(choice != 3);
}

void deleteElement()
{
    int temp;
    printf("\nEnter the element to delete: ");
    scanf("%d", &temp);
    ptr = head;
    new1 = NULL;
    while (ptr!= NULL)
    {
        if(ptr->data == temp)
        {
            break;
        }
        new1 = ptr;
        ptr = ptr->next;
    }

        if(ptr == NULL)
        {
            printf("\nElement not found !\n");
            getch();
        }
        else if (new1 == NULL)
        {
            printf("\nDeleting element from firstNode: %d\n", ptr->data);
            head = ptr->next;
            getch();
        }
        else
        {
            printf("\nDeleting element: %d\n", ptr->data);
            getch();
            new1->next = ptr->next;
        }
        free(ptr);
}

void main()
{
    char ch;
    int op;
    head = (node*)malloc(sizeof(node));
    ptr = head;
    printf("Input Initial Linked List:\n");
    printf("\nEnter data: ");
    scanf("%d",&ptr->data);
    do
    {
        printf("\nContinue LinkedList? y or n");
        ch = getch();
        switch(ch)
        {
            case 'y': {
                new1 = (node*)malloc(sizeof(node));
                ptr->next = new1;
                ptr = new1;
                printf("\nEnter data: ");
                scanf("%d",&ptr->data);
                break;
            }
            case 'n': {
                ptr->next = NULL;
                break;
            }
            default: printf("\nPlease only input 'y' or 'n'\n");break;
        }
    }while (ch!='n');
    do
    {
        displayMenu();
        scanf("%d",&op);
        switch(op)
        {
            case 1 : displayLL();insertNodeMenu();break;
            case 2 : deleteNodeMenu();break;
            case 3 : deleteElement();break;
            case 4 : exit(1);
            default : system("cls");printf("Wrong Input!");
        }
    }while(op!=4);
}
