//Contribution by yashneet-kalra

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*rear, *front, *temp;

void create_queue();
void insert_queue();
void delete_queue();
void traverse_front();
void traverse_rear();

int main()
{
    int select;
    char retry;


    printf("\t|--->QUEUE using LINKED LIST<---|\n");

    do
    {
        printf("\nChoose one of the following operations :- ");
        printf("\n1. Create Queue \n2. Insert Element \n3. Delete Element \n4. View Front Element \n5. View REAR Element \n-> ");
        scanf("%d",&select);

        switch(select)
        {
            case 1 : create_queue();
                     break;

            case 2 : insert_queue();
                     break;

            case 3 : delete_queue();
                     break;

            case 4 : traverse_front();
                     break;

            case 5 : traverse_rear();
                     break;
        }

        printf("\nWanna try another operation? (Y/N) -> ");
        fflush(stdin);
        scanf("%c",&retry);

    }while(retry == 'y' || retry == 'Y');

    printf("\n\nThe Program Has Ended.\n");
}

void create_queue()
{
    char choice;

    do
    {
        if(front == NULL)
        {
            temp = (struct node *)malloc(sizeof(struct node));
            printf("\nEnter the Element -> ");
            scanf("%d",&temp->data);


            temp->next = NULL;

            front = temp;
            rear = front;
        }
        else
        {
            temp = (struct node *)malloc(sizeof(struct node));
            printf("\nEnter the Element -> ");
            scanf("%d",&temp->data);

            temp->next = NULL;
            rear->next = temp;
            rear = temp;
        }

        printf("Wanna insert another element? (Y/N) -> ");
        fflush(stdin);
        scanf("%c",&choice);

    }while(choice == 'y' || choice == 'Y');
}

void insert_queue()
{
    if(front == NULL)
    {
        printf("\nThe LIST has NOT been created yet. First CREATE a List");
    }
    else
    {
        temp = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter the Element -> ");
        scanf("%d",&temp->data);

        temp->next = front;

        rear->next = temp;
        rear = temp;

        printf("Element inserted successfully.");
    }
}

void delete_queue()
{
    struct node *pred;
    if(front == NULL)
    {
        printf("\nThe Queue is EMPTY. First CREATE a Queue.");
    }
    else if(front->next == front)
    {
        temp = front;
        rear = NULL;
        front = NULL;
        free(temp);

        printf("Element DELETED successfully and List is EMPTY now.\n");
    }
    else
    {
        pred = front;

        while(pred->next != rear)
            pred = pred->next;

        temp = rear;
        pred->next = front;
        rear = pred;

        free(temp);

        printf("Element has been DELETED successfully.");

    }
}

void traverse_front()
{

    if(front == NULL)
    {
        printf("\nThe List is EMPTY.\n");
    }
    else
    {
        printf("\nThe FRONT element is -> \'%d\'\n",front->data);
    }
}

void traverse_rear()
{
    if(front == NULL)
        printf("\nThe List is EMPTY.\n");
    else
    {
        printf("\nThe REAR element is -> \'%d\'\n",rear->data);
    }
}
