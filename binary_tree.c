#include <stdio.h>
#include <stdlib.h>

struct Nodes{
    int data;
    struct Nodes *left;
    struct Nodes *right;
};

struct Nodes* createMainRoot(int value){
    struct Nodes *new = (struct Nodes*)malloc(sizeof(struct Nodes));

    if(new != NULL){
        new->data = value;
        new->left = NULL;
        new->right = NULL;
    }
    return new;
}

struct Nodes* insertNode(struct Nodes* root, int value){
    if(root == NULL){
        return createMainRoot(value);
    }

    if(value < root->data){
        root->left = insertNode(root->left, value);
    }
    else if(value > root->data){
        root->right = insertNode(root->right, value);
    }

    return root;
}

void inOrder(struct Nodes* root){
    if(root != NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
void preOrder(struct Nodes* root){
    if(root != NULL){
        printf("%d ", root->data);
        inOrder(root->left);
        inOrder(root->right);
    }
}

void postOrder(struct Nodes* root){
    if(root != NULL){
        inOrder(root->left);
        inOrder(root->right);
        printf("%d ", root->data);
    }
}

void freeTree(struct Nodes* root){
    if(root != NULL){
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main(){
    struct Nodes* root = NULL;
    int value;
    int choice;


    do{
        printf("Enter the value to insert into the binary tree: ");
        scanf("%d",&value);

        root = insertNode(root, value);

        printf("Press 0 to exit.\n");
        printf("Press 1 or any other number to add more values.\n");
        printf("Want to enter new values : ");
        scanf("%d",&choice);
    }while(choice);

    printf("\n\nDisplaying the tree....\n\n");

    printf("In Order: ");
    inOrder(root);
    printf("\n\n");

    printf("Pre Order: ");
    preOrder(root);
    printf("\n\n");

    printf("Post Order: ");
    postOrder(root);
    printf("\n\n");

    freeTree(root);

    return 0;
}