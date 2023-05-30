#pragma once
#if _WIN32 || _WIN64
#include<windows.h>
#define sleep(time) Sleep((time*1000))
#else
#include<unistd.h>
#endif

int isSame(int* list); //check "is Same?"
int isExtraSame(int* list, int extra); //check extra number "is Same?"

void swap(int* a, int* b);
int* bubble_sort(int len, int* arr);
