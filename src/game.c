#include"game.h"
#include"algorism.h"
#include<stdlib.h>

struct Lotto_struct* newGame(struct Lotto_struct* lotto) {
    srand((unsigned int)time(NULL)); //set Seed based on time

    lotto = (Lotto_struct*)calloc(1, sizeof(Lotto_struct)); //initialized new Lotto_struct

    for (int i = 0; i < 6; i++) {
        lotto->number[i] = rand() % 45 + 1; //set random number
    }
    lotto->extra_num = rand() % 45 + 1; //set extra number

    if (isSame(lotto->number)) {
        sleep(1);
        lotto = newGame(lotto); //re-generate Lotto Game
    }

    return lotto;
}

int compareNumber(int* numbers, int extra, Lotto_struct* lotto) {
    int count = 0;
    for (int i = 0; i < 6; i++) {
        if (numbers[i] == lotto->number[i]) { //check user input is same with lotto number
            count++;
        }
    }
    switch (count)
    {
    case 6: // 6 numbers correct
        return 1;
    case 5: // 5 numbers correct
        if (extra == lotto->extra_num) { //correct extra_number?
            return 2;
        }
        else {
            return 3;
        }
    case 4: // 4 numbers correct
        return 4;
    case 3: // 3 numbers correct
        return 5;
    default: // else
        return -1;
    }
}

void freeAllGame(Lotto_struct** lotto_ptr, int index) {
    for (int i = 0; i < index; i++) {
        free(lotto_ptr[i]);
    }
    free(lotto_ptr);
}
