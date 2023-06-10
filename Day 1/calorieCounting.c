#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void checkMax(int maxThree[], int currCount) {
    int minIndex = 0;
    int min = maxThree[0];
    for (int i = 0; i < 3; i++) {
        if (maxThree[i] < min) {
            min = maxThree[i];
            minIndex = i;
        }
    }

    if (currCount > maxThree[minIndex]) {
        maxThree[minIndex] = currCount;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Please specifiy an input file name.\n");
        exit(1);
    }
    char *fileName = argv[1];

    FILE *file = fopen(fileName, "r");

    char calories[64];
    int currCount = 0;
    int maxThree[3] = {0, 0, 0};
    //char *getReturn = fgets(calories, 64, file);
    while (fgets(calories, 64, file) != NULL) {
        currCount += atoi(calories);
        if (isspace(calories[0])) {
            checkMax(maxThree, currCount);
            currCount = 0;
        }

        //printf("%d %d %d\n", maxThree[0], maxThree[1], maxThree[2]);
    }
    checkMax(maxThree, currCount);

    int maxThreeSum = maxThree[0] + maxThree[1] + maxThree[2];
    printf("Max Three Sum Calories: %d\n", maxThreeSum);
}