#include <stdio.h>
#include <stdlib.h>

typedef struct element{
    int data;
    int swaps;
} element;

void swap(element * e, int index1, int index2){
    if(index1 != index2){
        int tempData = e[index1].data;
        e[index1].data = e[index2].data;
        e[index2].data = tempData;

        int tempSwap = e[index1].swaps;
        e[index1].swaps = e[index2].swaps + 1;
        e[index2].swaps = tempSwap + 1;
    }
}

void bubbleSort(element * e, int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(e[j].data > e[j+1].data){
                swap(e,j, j+1);
            }
        }
    }
}
void selectionSort(element * e, int n){
    int i, j, minIndex;
    for(i = 0; i < n-1; i++){
        minIndex = i;
        for(j = i+1; j<n; j++){
            if(e[j].data < e[minIndex].data){
                minIndex = j;
            }
        }
        swap(e,minIndex,i);
    }
}

void printSort(element * e, int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        printf("%d: %d\n", e[i].data,e[i].swaps);
        sum += e[i].swaps;
    }
    printf("%d\n\n", sum/2);
}

int main(){
    int arr1[9] = {97,16,45,63,13,22,7,58,72};
    int arr2[9] = {90,80,70,60,50,40,30,20,10};

    printf("%d\n", arr1[0]);
    element * arr1Bubble = (element*) malloc(sizeof(element)*9);
    if(arr1Bubble == NULL) return 0;

    element * arr2Bubble = (element*) malloc(sizeof(element)*9);
    if(arr2Bubble == NULL) return 0;

    element * arr1Selection = (element*) malloc(sizeof(element)*9);
    if(arr1Selection == NULL) return 0;

    element * arr2Selection = (element*) malloc(sizeof(element)*9);
    if(arr2Selection == NULL) return 0;

    for(int i = 0; i < 9; i++){
        arr1Bubble[i].data = arr1[i];
        arr1Selection[i].data = arr1[i];
        arr2Bubble[i].data = arr2[i];
        arr2Selection[i].data = arr2[i];
        arr1Bubble[i].swaps = 0;
        arr1Selection[i].swaps = 0;
        arr2Bubble[i].swaps = 0;
        arr2Selection[i].swaps = 0;
    }

    bubbleSort(arr1Bubble,9);
    printf("array1 bubble sort:\n");
    printSort(arr1Bubble,9);

    bubbleSort(arr2Bubble,9);
    printf("array2 bubble sort:\n");
    printSort(arr2Bubble,9);

    selectionSort(arr1Selection,9);
    printf("array1 selection sort:\n");
    printSort(arr1Selection,9);

    selectionSort(arr2Selection,9);
    printf("array2 selection sort:\n");
    printSort(arr2Selection,9);

    free(arr1Bubble);
    free(arr2Bubble);
    free(arr1Selection);
    free(arr2Selection);
    return 0;
}