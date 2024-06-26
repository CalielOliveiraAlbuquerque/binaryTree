#include <stdio.h>
#include "binaryTree.h"
#include "binaryTreeInverter.h"
#include "initBinaryTree.h"


//void commands(){
    //printf("origin: Gets you to the first word in the binary tree.\n");
    //printf("back: Gets you to the parent node.\n");
    //printf("contents: display the node content.\n");
//}

int main(){
    int intarray[]= {8,1,4,2,3,4,5,6,7,8};
    int size = sizeof(intarray)/sizeof(intarray[0]);
    node start;
    int count = initTree(intarray,size,&start);
    char continuar='\0';
    printf("Normal binary tree: \n");
    display(&start);
    invertTree(&start);
    continuar='\0';
    printf("\nInverted binary tree: \n");
    display(&start);
    return 0;
}
