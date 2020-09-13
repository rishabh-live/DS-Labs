/*
*Name = Rishabh
*Reg No = 201800631
*Dept = IT
*Lab Date = 9 Sep 2020
*Lab Work : 5
*
*AIM : C program to insert an element in a sorted linked list.
*/

#include <stdio.h> 
#include <stdlib.h> 
  

struct Node { 
    int data; 
    struct Node* next; 
}; 
  

void sortedInsert(struct Node** head_ref, 
                  struct Node* new_node) 
{ 
    struct Node* current; 
    /* Special case for the head end */
    if (*head_ref == NULL 
        || (*head_ref)->data 
               >= new_node->data) { 
        new_node->next = *head_ref; 
        *head_ref = new_node; 
    } 
    else { 
        
        current = *head_ref; 
        while (current->next != NULL 
               && current->next->data < new_node->data) { 
            current = current->next; 
        } 
        new_node->next = current->next; 
        current->next = new_node; 
    } 
} 
  

  
/* A utility function to create a new node */
struct Node* newNode(int new_data) 
{ 
    /* allocate node */
    struct Node* new_node  
= (struct Node*)malloc( 
sizeof(struct Node)); 
  
    /* puting in the data  */
    new_node->data = new_data; 
    new_node->next = NULL; 
  
    return new_node; 
} 
  
/* Function to print linked list */
void printList(struct Node* head) 
{ 
    struct Node* temp = head; 
    while (temp != NULL) { 
        printf("%d  ", temp->data); 
        temp = temp->next; 
    } 
} 
  
/* Driver program to test count function*/
void main() 
{ 
    
    struct Node* head = NULL; 
    struct Node* new_node = newNode(5); 
    sortedInsert(&head, new_node); 
    new_node = newNode(10); 
    sortedInsert(&head, new_node); 
    new_node = newNode(7); 
    sortedInsert(&head, new_node); 
    new_node = newNode(3); 
    sortedInsert(&head, new_node); 
    new_node = newNode(1); 
    sortedInsert(&head, new_node); 
    new_node = newNode(9); 
    sortedInsert(&head, new_node); 
    printf("\n Created Linked List\n"); 
    printList(head); 
    printf("\n");
} 