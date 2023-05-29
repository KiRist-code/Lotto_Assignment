#include "algorism.h"

int isSame(int* list){
    for(int i=0;i<6;i++){ //check some input number is same
        for(int j=0;j<6;j++){
            if(list[i] == list[j]) { 
                return 1;
            }
        }
    }
    return 0;
}

int isExtraSame(int* list, int extra){
    for(int i=0;i<6;i++){ //check some input number is same
        if(list[i] == extra) { 
            return 1;
        }
    }
    return 0;
}

void swap(int* a, int* b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

void bubble_sort(int len, int* arr){
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            if(arr[j] > arr[j]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

