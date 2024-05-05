#include "header.h"

static void swap(node** a, node** b){
    node* temp = *a;
    *a = *b;
    *b = temp;
}

void invertTree(node* start){
    int startingSize = 50;
    node* queue[startingSize], *waitQueue[startingSize];
    int create=0,demand=0;
    queue[create]=start;
    create++;
    do{
        for(int i=0;i<create;i++){
            node** left = &queue[i]->left;
            node** right = &queue[i]->right;
            swap(left,right);
            if(*left!=NULL){
                waitQueue[demand]=*left;
                demand++;
            }
            if(*right!=NULL){
                waitQueue[demand]=*right;
                demand++;
            }
        }
        for(int i=0;i<demand;i++){
            queue[i]=waitQueue[i];
        }
        create=demand;
        demand=0;
    }while(create!=0);
}
