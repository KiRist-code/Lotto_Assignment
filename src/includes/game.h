#pragma once

typedef struct Lotto_struct Lotto_struct;

/*
Lotto_struct: struct about lotto number
-> number: lotto number, this can store 5 numbers
-> extra_number: meaning as literally.
*/

struct Lotto_struct{
    int number[6];
    int extra_num;
};

struct Lotto_struct *newGame();
int* compareNumber(int* numbers, int extra, Lotto_struct* lotto);
void freeAllGame(Lotto_struct** lotto_ptr, int index);