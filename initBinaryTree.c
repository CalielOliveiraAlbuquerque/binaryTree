#include <stdbool.h>
#include <stdlib.h>
#include "binaryTree.h"
#include "sort.h"

static bool validateLeaf(int branchIndex,int indexes[],int size){
    if(branchIndex<0||branchIndex>=size){
        return false;
    }
    for(int i=0;i<size;i++){
        if(branchIndex==indexes[i]){
            return false;
        }
    }
    return true;
}
static node* createLeaf(int array[],int branchIndex){
    node* branchNode= malloc(sizeof(node));
    branchNode->value=array[branchIndex];
    branchNode->left=NULL;
    branchNode->right=NULL;
    return branchNode;
}

int initTree(int array[], int size, node* first){
    enum side{
        left=-1,
        right=1
    };
    struct address{
        node* pointer;
        int index;
        int side;
    };

    easySort(array,size);
    struct address fQueue[size],sQueue[size];
    int create=1,demand=0;
    int indexes[size],indexHead=0;
    int factor = 2;
    unsigned int count=1;
    int shift = size/factor;

    first->value = array[shift];
    struct address firstAdress = {first,shift};
    fQueue[0]=firstAdress;
    indexes[0] =shift;
    indexHead++;

    factor*=2;
    if(size%factor==0){
        shift = size/factor;
    }else{
        shift=size/factor+1;
    }

    while(shift>=1){
        //This code sets both branches of a node
        for(int i=0;i<create;i++){
            int curIndex=fQueue[i].index;
            node* lNode = malloc(sizeof(node)); 
            node* rNode = malloc(sizeof(node)); 
            if(lNode==NULL||rNode==NULL)return count;
            int lIndex = curIndex-shift;
            int rIndex = curIndex+shift;
            lNode->value = array[lIndex];
            rNode->value = array[rIndex];
            fQueue[i].pointer->left = lNode;
            fQueue[i].pointer->right= rNode;
            struct address lAddress = {lNode,lIndex,left};
            struct address rAddress = {rNode,rIndex,right};
            sQueue[demand]=lAddress;
            demand++;
            sQueue[demand]=rAddress;
            demand++;
            count++;
            indexes[indexHead]=lIndex;
            indexHead++;
            indexes[indexHead]=rIndex;
            indexHead++;
        }
        for(int i=0;i<demand;i++){
            fQueue[i] = sQueue[i];
        }
        create=demand;
        demand=0;
        factor*=2;
        shift = size/factor;
        if((float)size/factor-shift>=0.5&&size/factor>0){
            shift++;
        }
    }
    //Now we have to treat the edge cases.
    for(int i=0;i<create;i++){
        int index = fQueue[i].index;
        enum side side=fQueue[i].side;
        if(side==left){
            int branchIndex= index-1;
            bool isValid=validateLeaf(branchIndex,indexes,indexHead);
            if(!isValid)continue;
            node* leaf = createLeaf(array,branchIndex);
            fQueue[i].pointer->left= leaf;
        }
        if(side==right){
            int branchIndex= index+1;
            bool isValid=validateLeaf(branchIndex,indexes,indexHead);
            if(!isValid)continue;
            node* leaf = createLeaf(array,branchIndex);
            fQueue[i].pointer->right = leaf;
        }
    }
    return count;
}
