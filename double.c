#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next, *prev;
};


void create(struct node **head){

    if(*head != NULL){
        printf("already created");
    }

    else{
        int key;
        printf("enter data");
        scanf("%d", &key);
        struct node *new;
        new = (struct node*)malloc(sizeof(struct node));

        new->prev = NULL;
        new->next = NULL;
        new->data = key;
        *head = new;
    }
}

void insert_left(struct node **head){
    int key;
        printf("enter data");
        scanf("%d", &key);
        struct node *new;
        new = (struct node*)malloc(sizeof(struct node));

        new->prev = NULL;
        new->next = *head;
        (*head)->prev = new;
        new->data = key;
        *head = new;

}

void del_node(struct node **head){
    if(*head == NULL){
        printf("underflow");
    }

    else{
        int key;
        printf("Delete what element");
        scanf("%d", &key);
        struct node *temp;
        temp = *head;

        while(temp->next != NULL){
            
            if(temp->data == key){
                break;
            }

            temp = temp->next;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        free(temp);
        
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
int response;

struct node *head = NULL;
while(1){
    printf("\nWhat do you wish to do?");
    printf("\n1.Create");
    printf("\n2.Insert on the left");
    printf("\n3.Delete a particular node");
    printf("\n4. Display");
    scanf("%d", &response);
    switch (response)
    {
    case 1:
        create(&head);
        break;

    case 2:
        insert_left(&head);
        break;

    case 3:     
        del_node(&head);
        break;

    case 4:
        display(&head);
        break;

    default:
        exit(1);
        break;
    }       

}

}