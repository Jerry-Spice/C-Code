#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>


/*
TODO: Fix max value bug - with the current system the graph will occassionally return a child index of the max value of the array which shouldn't be possible.
*/

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

void sortIndexesList(int indexes[], int indexSize) {
    for (int i = 1; i < indexSize; i++) {
        for (int g = 1; g < indexSize; g++) {
            if (indexes[i] < indexes[g]) {
                int saved = indexes[i];
                indexes[i] = indexes[g];
                indexes[g] = saved;
            }
        }
    }
}

void assignNodesList(int indexSize, struct Node nodes[], char* names[], int indexes[]) {
    //assigning node values
    for (int index = 0; index < indexSize; index++) {
        nodes[index].index = index;
        nodes[index].info = names[index];
    }
    //assigning child values
    ///<summary>
    /// steps for algorithm
    /// 1. chooose random index + buffer for indexes value
    /// 2. set indexes[index] = -1 & increase buffer by 1
    /// 3. sort indexes array to ensure -1's are at the front
    /// 4. repeat 
    ///</summary>
    int indexesLeft = indexSize;
    int buffer = 0;
    int targetIndex;
    int actualID;
    for (int index = 0; index < indexSize; index++) {
        // debug | printf("\n------%i-------\n", index);
        if (indexesLeft > 1) {
            // debug | for (int a = 0; a < indexSize; a++) {
            // debug |     printf("%i:", a);
            // debug |     printf("%i\n", indexes[a]);
            // debug | }
            //step 1
            targetIndex = (rand() % indexesLeft) + buffer;
            actualID = indexes[targetIndex];
            nodes[index].child = &nodes[actualID];
            //step 2
            // debug | printf("\n%i", targetIndex);
            indexes[targetIndex] = -1;
            buffer++; 
            indexesLeft--;

            //step 3
            sortIndexesList(indexes, indexSize);
            //for (int a = 0; a < indexSize; a++) {
            //    printf("%i:", a);
            //    printf("%i\n", indexes[a]);
            //}

            //step 4
            //repeat
            
        }
        else {
            nodes[index].child = &nodes[0];
        }
    }
}



int main() {
    //init for the random function
    time_t t;
    srand((unsigned)time(&t));

    
    int indexSize = 20;
    struct Node nodes[20];
    int indexes[20];
    char* names[20];
    for (int i = 0; i < indexSize; i++) {
        indexes[i] = i;
        names[i] = "empty";
    }
    assignNodesList(indexSize, nodes, names, indexes);
    //displaying node values
    printf("-----------------------\n");
    for (int index = 0; index < indexSize; index++) {
        printf("%i",nodes[index].index);
        printf(" | ");
        printf("%s", nodes[index].info);
        printf(" --> ");
        printf("%i", nodes[index].child->index);
        printf("\n");
    }

    return 0;
}
