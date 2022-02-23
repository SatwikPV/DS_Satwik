#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};


void enqueue(struct node **head){
    int key;
    printf("Enter data");
    scanf("%d", &key);
    
    if(*head == NULL){
        struct node *new;
        new = (struct node*)malloc(sizeof(struct node));
        new->data = key;
        new->next = NULL;
        (*head) = new;
        
    }
    
    else{
        struct node *new, *temp;
        new = (struct node*)malloc(sizeof(struct node));

        temp = *head;

        while(temp->next != NULL){
            temp = temp->next;
        }
        new->data = key;
        temp->next = new;
    }
}

void dequeue(struct node **head){
    if(*head == NULL){
        printf("underflow");
    }
    
    else if((*head)->next == NULL){
        free(*head);
    }

    else{
        struct node *ptr;

        ptr = (*head);
        (*head) = (*head)->next;
        free(ptr);
    }
}

void display(struct node **head){
    struct node *temp;

    temp = *head;

    while(temp->next != NULL){
        printf("%d \n", temp->data);
        temp = temp->next;
    }
    printf("%d \n", temp->data);
}

int main(){
    struct node *head = NULL;

    int resp;

    while(1){
        printf("enqueue/dequeue/Display/Exit?");
        scanf("%d", &resp);

        switch (resp)
        {
        case 1:
            enqueue(&head);
            break;
        
        case 2:
            dequeue(&head);
            break;

        case 3:
            display(&head);
            break;

        case 4:
            exit(1);

        default:
            printf("Enter a valid number");
            break;
        }
    }
}