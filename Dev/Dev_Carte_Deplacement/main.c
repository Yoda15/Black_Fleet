#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <time.h>

#define MAX 100000
#define SIZE 100
#define NUMS_TO_GENERATE 10

int main() {
    srand(time(NULL));
    for (int i = 0; i < NUMS_TO_GENERATE; i++){
        printf("%d\n", rand() % MAX);
    }

    exit(EXIT_SUCCESS);
}
