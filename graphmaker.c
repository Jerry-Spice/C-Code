#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

int input_i(char * msg) { //returns the number value of whatever the user inputs
    int num;
    malloc(sizeof(int));
    printf("%s", msg);
    scanf("%d", &num);
    return num;
}
char * input_s(char* msg) { // returs the string that the user inputs
    char * chars;
    chars = malloc(sizeof(chars));
    printf("%s", msg);
    scanf("%s", chars);
    return chars;
}

struct Node {
    int index;
    char* info;
    struct Node* child;
} Node;

int main() {
    //init for the random function
    time_t t;
    srand((unsigned)time(&t));

    struct Node nodes[10];
    int indexes[9] = { 1,2,3,4,5,6,7,8,9 };
    char* names[10] = { "Josh","Jerry","Spice","Jim","Makayla","Rebbecca","Ella","Justin","Fiona", "Jake"};
    int indexSize = 9;
    //assigning node values
    for (int index = 0; index < 10; index++) {
        nodes[index].index = index;
        nodes[index].info = names[index];
    }
    //assigning child values
    for (int index = 0; index < 10; index++) {
        if (index + 1 < 10) {
            int TIndex = indexes[rand() % indexSize];
            while (indexes[TIndex] == index || indexes[TIndex] == -1) {
                TIndex = rand() % indexSize;
            }
            //printf()
            nodes[index].child = &nodes[indexes[TIndex]];
            //removing the index from the list of available indexes
            for (int i = TIndex; i < indexSize-1; i++) {
                indexes[i] = indexes[i + 1];
            }
            indexes[indexSize - 1] = -1;
            indexSize--;
        }
        else {
            nodes[index].child = &nodes[0];
        }
    }
    //displaying node values
    printf("-----------------------\n");
    for (int index = 0; index < 10; index++) {
        printf("%i",nodes[index].index);
        printf(" | ");
        printf("%s", nodes[index].info);
        printf(" --> ");
        printf("%i", nodes[index].child->index);
        printf("\n");
    }






    return 0;
}