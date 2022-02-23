#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
};


struct node* create(struct node **head, int key){

    struct node* ptr;

    ptr =  (struct node*)malloc(sizeof(struct node));

    ptr->data = key;
    ptr->next = NULL;

    *head = ptr;
    return (*head);
}

void insert(struct node **head, int key){
    struct node *ptr, *temp;
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = key;
    temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = ptr;
}

void sort(struct node **head){
    int swapped, i;
    struct node *ptr;
    struct node *temp = NULL;
    int key;

    if(*head == NULL){
        printf("nothing to sort");
    }

    do{
        swapped = 0;
        ptr = *head;

        while(ptr->next != temp){
            if(ptr->data > ptr->next->data){
                key = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = key;
                swapped = 1;
            }

            ptr = ptr->next;
        }

        temp = ptr;
    }while(swapped);
}


void reverse(struct node **head){
    struct node *prev=NULL, *next=NULL, *current;

    current = *head;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
    }
    *head = prev;
}

void display(struct node **head1, struct node **head2){
    struct node *temp;

    temp = *head1;
    printf("First list\n");
    while(temp->next != NULL){
        printf("%d \n", temp->data);
        temp = temp->next;
    }
    printf("%d \n", temp->data);


    temp = *head2;
    printf("Second list\n");
    while(temp->next != NULL){
        printf("%d \n", temp->data);
        temp = temp->next;
    }
    printf("%d \n", temp->data);

}

struct node *concat(struct node **head1, struct node **head2){
    if((*head1) == NULL)
        return *head2;
    else if((*head2) == NULL)
        return *head1;

    if(*head1 == NULL && *head2 == NULL){
        printf("Both the lists are empty");
    }

    else if(*head1 != NULL && *head2 != NULL){
        struct node *temp = *head1;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = *head2;
    }

    return *head1;
}


int main(){
    int response, rev;
    struct node *head1 = NULL, *head2 = NULL;

    head1 = create(&head1, 17);
    head2 = create(&head2, 9);

    insert(&head1, 42);
    insert(&head2, 35);
    insert(&head1, 20);
    insert(&head2, 25);
    insert(&head1, 30);
    insert(&head1, 34);
    insert(&head2, 43);

    while(1){
        printf("\nSort/Reverse/Concat/Display?");

        scanf("%d", &response);

        switch (response)
        {
        case 1:
            printf("sort which list?\n");
            scanf("%d", &rev);
            if(rev == 1){
                sort(&head1);
                break;}

            else if(rev == 2){
                sort(&head2);
                break;
            }
        
        case 2:
            printf("reverse which list?\n");
            scanf("%d", &rev);
            if(rev == 1){
            reverse(&head1);
            break;}

            else if(rev == 2){
                reverse(&head2);
                break;
            }

        case 3: 
            concat(&head1, &head2);
            break;

        case 4:
            display(&head1, &head2);
            break;

       
        
        default:
            printf("Enter a valid number.");
            break;
        }

    }
}