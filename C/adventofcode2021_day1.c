// adventofcode 2021 day 1: https://adventofcode.com/2021/day/1
// references: https://stackoverflow.com/questions/20378430/reading-numbers-from-a-text-file-into-an-array-in-c

#include <stdio.h>
int main(){

    FILE *myFile;
    myFile = fopen("input.txt", "r");

    if (myFile == NULL)
    {
        printf("Could not open file %s", "input.txt");
        return 0;
    }

    //read file into array
    int arr[2001];
    int i;
    int counter = 0;

    for (i = 0; i < 2001; i++){
        fscanf(myFile, "%d", &arr[i]);
    }

    for (i = 0; i < 2001; i++){
        if(arr[i] < arr[i+1]) counter++;
    }
    printf("%d", counter);
    return 0;
}
