#include <stdio.h>
#include <stdlib.h>
#include "Test.h"

typedef struct node{
    char data;
    struct node *nextNodePtr;
} node_t;
typedef node_t *ListNodePtr;

void insert(ListNodePtr *head,char value);
void insertAtEnd(ListNodePtr *head,char value);
void insertAtBeginning(ListNodePtr *head,char value);
char delete(ListNodePtr *head,char value);
void deleteAtBeginning(ListNodePtr *head);
int isEmpty(ListNodePtr head);
void printList(ListNodePtr currentPtr);

int main() {
    //printAliveMessage();
    ListNodePtr head = NULL;
    int choice = 0;
    char item = '\0';
    printf("Enter your choice: \n "
           "1: Insert an element into the list\n"
           "2: Insert an element at beginning of the list\n"
           "3: Insert an element at the end of the list\n"
           "4: Deletes an element in the list\n"
           "5: Deletes the first element in the list\n"
           "6: Quits the program");
    printf("::");
    scanf("%d",&choice);

    while (choice != 6){
        switch (choice) {
            case 1:
                printf("Enter a character: ");
                scanf("\n%c",&item);
                insert(&head,item);
                printList(head);
                break;
            case 2:
                printf("Enter a character: ");
                scanf("\n%c",&item);
                insertAtBeginning(&head,item);
                printList(head);
                break;
            case 3:
                printf("Enter a character: ");
                scanf("\n%c",&item);
                insertAtEnd(&head,item);
                printList(head);
                break;
            case 4:
                if (!isEmpty(head)){
                    printf("Enter the char you'd like to be deleted:");
                    scanf("\n%c", &item);
                    if (delete(&head,item)){
                        printf("%c deleted.\n");
                        printList(head);
                    } else {
                        printf("ERROR: %c WAS NOT FOUND IN LIST!",item);
                    }
                } else
                    printf("List is empty!");
                break;
            case 5:
                if (!isEmpty(head)){
                    deleteAtBeginning(&head);
                    printf("%c deleted.\n",item);
                    printList(head);
                } else{
                    printf("List is empty!");
                }
                break;
            case 6:
                exit(1);
                break;
            default:
                printf("That wasn't a option try again");
                break;
        }
    }
    return 0;
}
void insertAtBeginning(ListNodePtr *head,char value){
    ListNodePtr new_node = malloc(sizeof(node_t));
    new_node->data =value;
    new_node->nextNodePtr =*head;
    *head = new_node;
}
void insertAtEnd(ListNodePtr *head,char value){
    ListNodePtr current = *head;

    if (current != NULL){
        while (current->nextNodePtr != NULL){
            current = current->nextNodePtr;
        }
        current->nextNodePtr = malloc(sizeof(node_t));
        current->nextNodePtr->data = value;
        current->nextNodePtr->nextNodePtr = NULL;
    } else{
        current = malloc(sizeof(node_t));
        current->data = value;
        current->nextNodePtr = NULL;
        *head = current;
    }
}
void insert(ListNodePtr *head,char value){
    ListNodePtr newPtr,prevPtr,curPtr;

    newPtr = malloc(sizeof(node_t));

    if (newPtr != NULL) {
        newPtr->data = value;
        newPtr->nextNodePtr = NULL;

        prevPtr = NULL;
        curPtr = *head;

        while (curPtr != NULL && value > curPtr->data) {
            prevPtr = curPtr;
            curPtr = curPtr->nextNodePtr;
        }
        if (prevPtr == NULL) {
            newPtr->nextNodePtr = *head;
            *head = newPtr;
        } else {
            prevPtr->nextNodePtr = newPtr;
            newPtr->nextNodePtr = curPtr;
        }
    } else{
        printf("%c Not inserted. No memory available",value);
    }

}
void deleteAtBeginning(ListNodePtr *head){
    ListNodePtr tempPtr = NULL;
    if (head == NULL){
        return;
    } else{
        tempPtr = *head;
        *head = (*head)->nextNodePtr;
        free(tempPtr);
    }
}
char delete(ListNodePtr *head, char value){
    ListNodePtr prevPtr,curPtr,tempPtr;
    if (value == (*head)->data){
        tempPtr = *head;
        *head = (*head)-> nextNodePtr;
        free(tempPtr);
        return value;
    } else {
        prevPtr = *head;
        curPtr = (*head) ->nextNodePtr;

        while (curPtr != NULL && curPtr->data != value){
            prevPtr = curPtr;
            curPtr = curPtr->nextNodePtr;
        }
        if (curPtr != NULL){
            tempPtr = curPtr;
            prevPtr->nextNodePtr = curPtr->nextNodePtr;
            return value;
        }
    }
    return '\0';
}
void printList(ListNodePtr currentPtr){
    if (currentPtr == NULL){
        printf("List is empty");
    } else {
        printf("List contains:");

        while (currentPtr != NULL){
            printf("\n%c",currentPtr->data);
            currentPtr = currentPtr->nextNodePtr;
        }
    }

}
int isEmpty(ListNodePtr head){
    return head == NULL;
}