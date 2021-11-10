#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void collatz(int num, int step) {
    //printf("%d", num);
    //printf("\n");
    if (num == 1) {
        printf("Number of steps: ");
        printf("%i \n",step);
    }
    else {
        if (num % 2 == 0) {
            collatz(num / 2, step+1);
        }
        else {
            collatz(num * 3 + 1, step+1);
        }
    }
}

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


int main() {
    
}
