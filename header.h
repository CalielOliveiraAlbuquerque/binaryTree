#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node* left;
    struct node* right;
    int value;
}node;
void mknull(node* arr[],int size);
void invertTree(node* start);
void display(node* start);
node* search(node* start, int target);
int initTree(int array[], int size, node* first);
