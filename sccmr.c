#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

//Creating a structure for each node in our linked list
struct node
{
    int data;//data that each node would hold
    struct node *next; //part that stores the address
};

void beg_insert(struct node**head){ 

    if(*head == NULL){
        struct node *new_node; //initializing the new node as a type struct node
        new_node = (struct node*)malloc(sizeof(struct node)); //allocating space in memory for the new node 


        printf("Enter the data");
        scanf("%d", &new_node->data); 

        new_node->next = NULL;
        *head = new_node;

       }


    else{struct node *new_node; //initializing the new node as a type struct node
    new_node = (struct node*)malloc(sizeof(struct node)); //allocating space in memory for the new node 

    printf("Enter the data");
    scanf("%d", &new_node->data); 

    new_node -> next = *head;
    *head = new_node;
    }
}

void end_insert(struct node**head){
   
    if(*head == NULL){
        struct node *new_node; //initializing the new node as a type struct node
        new_node = (struct node*)malloc(sizeof(struct node)); //allocating space in memory for the new node 


        printf("Enter the data");
        scanf("%d", &new_node->data); 

        new_node->next = NULL;
        *head = new_node;

       }

    else{
        struct node *new_node, *temp;
        new_node = (struct node*)malloc(sizeof(struct node));

        temp = *head;
        printf("Enter the data");
        scanf("%d", &new_node->data); 

        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = new_node;
        new_node->next = NULL;
    }
}

void before_insert(struct node**head){
    if(*head == NULL){
            struct node *new_node; //initializing the new node as a type struct node
            new_node = (struct node*)malloc(sizeof(struct node)); //allocating space in memory for the new node 


            printf("Enter the data");
            scanf("%d", &new_node->data); 

            new_node->next = NULL;
            *head = new_node;

        }

    else{
    struct node *new_node, *temp, *prev;
    int trigger;
    new_node = (struct node*)malloc(sizeof(struct node));

    temp = *head;
    printf("Enter the data");
    scanf("%d", &new_node->data); 

    printf("Enter the data before which you want to insert this");
    scanf("%d", &trigger); 
    

    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
        if(temp->data == trigger){  //stop the loop if the desired data entry was found
            break;
        }
    }
    
    prev->next = new_node;
    new_node->next = temp;
}

}

void search(struct node**head){
    struct node *temp;
    int pos=0, trigger;

    printf("Enter the data whose pos you wish to find");
    scanf("%d", &trigger);

    temp = *head;

    while(temp->next!=NULL){
        temp = temp->next;
        pos++;
        if(temp->data == trigger){
            break;
        }
    } 

    printf("Element found at pos %d", pos+1);
}

void create(struct node **head){

    struct node *new_node;

    new_node = (struct node*)malloc(sizeof(struct node));

    printf("Enter the data");
    scanf("%d", &new_node->data); 

    new_node->next = NULL;
    *head = new_node;
}

void display(struct node**head){
     struct node *temp;

     temp=*head;
     printf("%d \n", temp->data);
     while(temp->next!=NULL){
         temp = temp->next;
         printf("%d \n", temp->data);
     }
}

void beg_del(struct node **head){
    struct node *temp;
    temp = *head;
    *head = temp->next; 
    free(temp); 
}

void end_del(struct node **head){
    struct node *temp, *prev;

    temp = *head;

    while(temp->next!=NULL){
        prev = temp;
        temp = temp->next;
    }

    free(temp);
    prev->next = NULL;
}


void this_del(struct node **head){
    int trigger;
    printf("Enter the entry you want to delete.");
    scanf("%d", &trigger);

    struct node *temp, *prev;

    temp = *head;
    while (temp->next!=NULL)
    {   
        prev = temp;
        temp = temp->next;
        if(temp->data == trigger){
            break;
        }
    }

    prev->next = temp->next;
    free(temp);
}


void after_del(struct node **head){
    struct node *temp, *tobedel;

    int trigger;
    printf("Enter the entry you want to delete.");
    scanf("%d", &trigger);

    while(temp->next != NULL){
        temp = temp->next;
        if(temp->data == trigger){
            break;
        }
    }
    tobedel = temp->next;
    temp->next = temp->next->next;

    free(tobedel);
}

int main(){
    int option;//for switch case implementation

    struct node *head = NULL;
    while(1){
        printf("\nWhat do you wish to do?");
        printf("\n1.Insert new node at the beg");
        printf("\n2.Insert new node at the end");
        printf("\n3.Insert new node before a specific node");
        printf("\n4.Search for a node with a particular entry");
        printf("\n5.Delete at the beginning");
        printf("\n6.Delete at the end");
        printf("\n7.Delete a particular node");
        printf("\n8.Delete node after a given node");
        printf("\n9.Create a linked list");
        printf("\n-1.Display");
        printf("\n TO EXIT PRESS 0\n");

        scanf("%d", &option);
        switch(option)
        {
        case 1:
            beg_insert(&head);
            break;

        case 2:
            end_insert(&head);
            break;

        case 3:
            before_insert(&head);
            break;
        
        case 4:
            search(&head);
            break;

        case 5:
            beg_del(&head);
            break;

        case 6:
            end_del(&head);
            break;

        case 7:
            this_del(&head);
            break;

        case 8:
            after_del(&head);
            break;

        case 9:
            create(&head);
            break;
        
        case -1:
            display(&head);
            break;
            
        case 0:
            exit(0);

        default:
            printf("Enter valid number");
            break;
        }
}

}







