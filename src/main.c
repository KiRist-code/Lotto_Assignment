#include<stdio.h>
#include<stdlib.h> // malloc from "stdlib.h" header
#include"game.h"
#include"algorism.h"

void input(int index, int** input_list, int* extra, int loop); //return extra number;

int main(void) { 
    Lotto_struct **lotto_ptr;
    int index = 0;
    int **input_num;
    int *input_extra;
    int result = -1;

    printf("How many do you want to try? : ");
    scanf("%d", &index);
    lotto_ptr = (Lotto_struct*) malloc(index * sizeof(struct Lotto_struct)); //set pointer of Lotto_struct
    input_num = malloc(index * sizeof(int)); //set length of 1st-dimension array
    *input_num =  malloc(6 * sizeof(int)); // set length of 2nd-dimension array
    input_extra = malloc(index * sizeof(int));

    input(0, input_num, input_extra, index);

    for(int i;i<index;i++){
       lotto_ptr[i] = newGame(); //generate Lotto Game
    }

    for(int i=0;i<index;i++){
        result = compareNumber(input_num[i],input_extra,lotto_ptr); //check what prize player get

        bubble_sort(6, lotto_ptr[i]->number);

        printf("No.%d: Lotto Number List\n",i); //print Lotto number List
        for(int j=0;j<6;j++){
            printf("%d ", lotto_ptr[i]->number[j]);
        }
        printf("%d\n", lotto_ptr[i]->extra_num);

        printf("No.%d 's Game Result is. . .", i);
        switch (result) //print result(like 1st, 2nd, 3rd. . .)
        {
        case 1: //1st
            printf("1st!!\n");
            break;
        case 2: //2nd
            printf("2nd!!\n");
            break;
        case 3: //3rd
            printf("3rd!!\n");
            break;
        case 4: //4th
            printf("4th :P\n");
            break;
        case 5: //5th
            printf("5th :<\n");
            break;
        default: //other
            printf("Sry. . . You don't get a prize in this game. . .\n");
            break;
        }
    }

    freeAllGame(lotto_ptr);
    free(input_num);
    free(input_extra);

    return 0;
}

void input(int index, int** input_list, int* extra, int loop){
    int idx = 0; //index
    printf("%d : Input your lucky NUMBER\n", idx);
    scanf("%d %d %d %d %d %d %d", &input_list[idx][0], &input_list[idx][1], &input_list[idx][2], &input_list[idx][3], &input_list[idx][4], &input_list[idx][5], &extra); //input number

    //check all number in array "isSame" || check extra number is same with input nubmers array
    if(isSame(input_list[idx]) ||  isExtraSame(input_list[idx], extra)) { 
        printf("Do not input the same numbe\n");
        input(idx, input_list, extra, loop); //run function again
    }

    idx++;
    if(idx != index) input(idx, input_list, extra, loop);
    else return;
}