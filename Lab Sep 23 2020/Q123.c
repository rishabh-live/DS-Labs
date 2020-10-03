/*
*Name = Rishabh
*Reg No = 201800631
*Dept = IT
*Lab Date = 23 Sep 2020
*Lab Work : 7
*
*AIM :  C program to "Create, Traverse, Search and Count Nodes" on a singly linked list
*/

#include <stdio.h>
#include <stdlib.h>


/*
 * Basic structure of Node
 */
struct node {
    int data;
    struct node * next;
}*head;


/*
 * Functions used in this program
 */
void createList(int n);
void displayList();



/**
 * Creates a Singly linked list of n nodes.
 * @n Number of nodes to be created
 */
void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));

    /*
     * If unable to allocate memory for head node
     */
    if(head == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        /*
         * Read data of node from the user
         */
        printf("Enter the data of node 1: ");
        scanf("%d", &data);

        head->data = data; // Link data field with data
        head->next = NULL; // Link address field to NULL

        temp = head;

        /*
         * Create n nodes and adds to linked list
         */
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            /* If memory is not allocated for newNode */
            if(newNode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);
                printf("\r");

                newNode->data = data; // Link the data field of newNode with data
                newNode->next = NULL; // Link the address field of newNode with NULL

                temp->next = newNode; // Link previous node i.e. temp to the newNode
                temp = temp->next;
            }
        }

        printf("SINGLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}

/**
 * Display the content of the list
 */
void displayList()
{
    struct node *temp;

    /*
     * If the list is empty i.e. head = NULL,
     * dont perform any action and return.
     */
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    
    temp = head;
    while (temp != NULL)
    {
        printf("%d, ", temp->data);
        temp = temp->next;  // Move to next node
    }
    printf("\n");
}

int countNodes()
{
    int count = 0;
    struct node *temp;

    temp = head;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    printf("There are %d elements in the list.\n",count);
    return 0;
}

/*
 * Search Element in the Linked List
 */

int search(int key)
{
    int index;
    struct node *curNode;

    index = 0;
    curNode = head;

    // Iterate till last element until key is not found
    while (curNode != NULL && curNode->data != key)
    {
        index++;
        curNode = curNode->next;
    }


    return (curNode != NULL) ? index : 0;
}

void checkPresent(int valueOffset){
    if (valueOffset != 0){
        printf("Element Found in Linked List at index %d.",valueOffset);
    }
    else
    {
        printf("No such element found in the list");
    }
    
}

int main()
{
    int n, data, choice=1;

    head = NULL;

    /*
     * Run forever until user chooses 0
     */
        printf("============================================\n");
        printf("CIRCULAR LINKED LIST PROGRAM\n");
        printf("============================================\n");
        printf("1. Create List\n");
        printf("2. Traverse the list\n");
        printf("3. Count Elements in list\n");
        printf("4. Search Elements in list\n");
        printf("0. Exit\n");
        printf("--------------------------------------------\n");

    while(choice != 0)
    {
       
        printf("Enter your choice \n>>> ");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter the total number of nodes in list: ");
                scanf("%d", &n);
                createList(n);
                break;
            case 2:
                displayList();
                break;
            case 3:
                countNodes();
                break;
            case 4:
                printf("Enter the element to be searched in list: ");
                scanf("%d", &n);
                int out = search(n);
                checkPresent(out);
                break;
            case 0:
                break;
            default:
                printf("Error! Invalid choice. Please choose between 0-2");
        }

        printf("\n\n\n");
    }

    return 0;
}

