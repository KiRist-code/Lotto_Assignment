#include "algorism.h"

int isSame(int* list) {
    for (int i = 0; i < 6; i++) { //check some input number is same
        for (int j = i + 1; j < 6; j++) {
            if (list[i] == list[j]) {
                return 1;
            }
        }
    }
    return 0;
}

int isExtraSame(int* list, int extra) {
    for (int i = 0; i < 6; i++) { //check some input number is same
        if (list[i] == extra) {
            return 1;
        }
    }
    return 0;
}

void swap(int* a, int* b) {
    int* temp = *b;
    *b = *a;
    *a = temp;
}

int* bubble_sort(int len, int* arr) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j + 1]);
                // 교수가 착하다 -> 이런 과제를 내준 교수가 만악의 근원
            }
        }
    }

    return arr;
}
