#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left, *right;
};

struct node *create(){
    struct node *temp;
    printf("\nEnter data");
    temp = (struct node *)malloc(sizeof(struct node));

    scanf("%d", &temp->data);
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}


void insert(struct node *root, struct node *temp){
    if(temp->data < root->data){
        if(root->left != NULL)
        {
            insert(root->left, temp);
        }

        else{
            root->left = temp;
        }
    }

    else if(temp->data > root->data){
        if(root->right != NULL)
        {
            insert(root->right, temp);
        }

        else{
            root->right = temp;
        }
    }
}


void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root){
    if(root!=NULL){
        printf("%d", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root){
        if(root!=NULL){
            postorder(root->left);
            postorder(root->right);
            printf("%d", root->data);
        }
    }

void display(){

}

int main(){
    char ch;
    struct node *root=NULL, *temp;
    do{
        temp = create();
        if(root == NULL){
            root = temp;
        }

        else{
            insert(root, temp);
        }

        printf("Do you wish to enter more?");
        getchar();
        scanf("%c", &ch);
    }while(ch == 'y' | ch == 'Y');

    printf("\nin-order:\n");
    inorder(root);
    printf("\npre-order:\n");
    preorder(root);
    printf("\npost-order:\n");
    postorder(root);
}

