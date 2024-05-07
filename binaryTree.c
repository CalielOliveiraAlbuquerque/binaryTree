#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    struct node* left;
    struct node* right;
    int value;
}node;

void mknull(node* arr[],int size){
    for(int i=0;i<size;i++){
        arr[i]=NULL;
    }
}

void display(node* start){
    int initialSize=50;
    // node** fQueue = malloc(sizeof(node*)*initialSize);
    // node** sQueue = malloc(sizeof(node*)*initialSize);
    node* fQueue[initialSize];
    node* sQueue[initialSize];
    mknull(fQueue,initialSize);
    mknull(sQueue,initialSize);
    printf("%d\n",start->value);
    printf("|\\\n");
    fQueue[0]=start->left;
    fQueue[1]=start->right;
    int demand=0;
    int display=2;
    do{
        demand=0;
        for(int i=0;i<display;i++){
            if(fQueue[i]==NULL){
                printf("X|");
            }else{
                printf("%d|",fQueue[i]->value);
                sQueue[demand]=fQueue[i]->left;
                demand++;
                sQueue[demand]=fQueue[i]->right;
                demand++;
            }
        }
        printf("\n");
        for(int i=0;i<demand;i++){
            fQueue[i]=sQueue[i];
        }
        display=demand;
    }
    while(demand!=0);
}

node* search(node* start, int target){
    node* currentNode = start;
    while(currentNode!=NULL){
        if(currentNode->value==target){
            return currentNode;
        }
        if(currentNode->value>target){
            currentNode = currentNode->left;
            continue;
        }
        if(currentNode->value<target){
            currentNode = currentNode->right;
            continue;
        }
    }
    return NULL;
}

