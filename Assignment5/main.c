//
//  main.c
//  C-course_assignment
//
//  Created by Eric Yang on 12/30/24.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void sortArray(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main(void) {
    const char *file1 = "/Users/ericyang/Github/C-course_assignment/Assignment5/file1.bin";
    const char *file2 = "/Users/ericyang/Github/C-course_assignment/Assignment5/file2.bin";
    const char *outputFile = "/Users/ericyang/Github/C-course_assignment/Assignment5/sorted_output.bin";

    int numbers1[MAX];
    int numbers2[MAX];
    int merged[MAX * 2];
    size_t size1, size2;
    int totalSize;

    // read files to the arrays
    FILE *readFile1 = fopen(file1, "rb");
    FILE *readFile2 = fopen(file2, "rb");
    size1 = fread(numbers1, sizeof(int), MAX, readFile1);
    size2 = fread(numbers2, sizeof(int), MAX, readFile2);
    
    for (int i = 0; i < size1; i++) {
        printf("%d ", numbers1[i]);
    }
    printf("\n");
    for (int i = 0; i < size2; i++) {
        printf("%d ", numbers2[i]);
    }
    printf("\n");

    fclose(readFile1);
    fclose(readFile2);

    // Merge the arrays
    for (int i = 0; i < size1; i++) {
        merged[i] = numbers1[i];
    }
    for (int i = 0; i < size2; i++) {
        merged[size1 + i] = numbers2[i];
    }
    totalSize = (int)size1 + (int)size2;
    sortArray(merged, totalSize);

    // Write the sorted array to the output file
    FILE *writeFile = fopen(outputFile, "wb");
    if (writeFile == NULL) {
        perror("Error creating sorted_output.bin");
        return EXIT_FAILURE;
    }

    fwrite(merged, sizeof(int), totalSize, writeFile);
    fclose(writeFile);

    printf("Merged and sorted integers written to %s\n", outputFile);
    
    for (int i = 0; i < totalSize; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");
    return EXIT_SUCCESS;
}
