#ifndef binaryTree
#define binaryTree

typedef struct node{
    struct node* left;
    struct node* right;
    int value;
}node;
void mknull(node* arr[],int size);
void display(node* start);
node* search(node* start, int target);

#endif 
