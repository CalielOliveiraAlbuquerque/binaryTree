#include <stdio.h>
static void swap(int *a,int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}
void easySort(int arr[],int size){
    printf("printf from easySort: ");
    for(int i=0;i<size;i++){
        printf("%d",arr[i]);
    }
    printf("\n");
    for(int i=0;i<size;i++){
        int* smaller=&arr[i];
        for(int j=i+1;j<size;j++){
            if(*smaller>=arr[j]){
                smaller=&arr[j];
            }
        }
        swap(&arr[i],smaller);
    }
}

