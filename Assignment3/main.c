//
//  main.c
//  C-course_assignment
//
//  Created by Eric Yang on 11/20/24.
//
#include <stdio.h>

// 驗證輸入的數字是否有效
void check_input(int *num) {
    while (scanf("%d", num) != 1 || *num <= 0) {
        printf("輸入無效，請重新輸入\n");
        printf("請輸入數列的數字個數: ");

        // 清除輸入緩衝區
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
}

// 找出兩個數列的交集及其出現次數
int find_intersection_with_count(int *arr1, int n1, int *arr2, int n2, int *result, int *count) {
    int record1[10] = {0}, record2[10] = {0};
    int index = 0;

    // 記錄第一個數列中每個數字的出現次數
    for (int *p1 = arr1; p1 < arr1 + n1; p1++) {
        record1[*p1]++;
    }

    // 記錄第二個數列中每個數字的出現次數
    for (int *p2 = arr2; p2 < arr2 + n2; p2++) {
        record2[*p2]++;
    }

    // 找出交集並記錄每個數字的共同出現次數
    for (int i = 0; i < 10; i++) {
        if (record1[i] > 0 && record2[i] > 0) {
            result[index] = i; // 儲存交集數字
            count[index] = record1[i] < record2[i] ? record1[i] : record2[i]; // 儲存次數的較小值
            index++;
        }
    }

    return index;
}

void bubble_sort(int *arr1, int *arr2, int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        // 因為每次比較都會將最大值放到最後，所以每次比較的範圍會縮小
        for (int j = 0; j < n - i - 1; j++) {
            if (*(arr1 + j) < *(arr1 + j + 1)) {
                // bubble sort count
                temp = *(arr1 + j);
                *(arr1 + j) = *(arr1 + j + 1);
                *(arr1 + j + 1) = temp;

                // bubble sort result
                temp = *(arr2 + j);
                *(arr2 + j) = *(arr2 + j + 1);
                *(arr2 + j + 1) = temp;
            }
        }
    }
}

int main(void) {
    int n_group1, n_group2;
    int result[10], count[10];

    // 輸入第一組數列
    printf("請輸入第一組數列有多少數字: ");
    check_input(&n_group1);

    int group1[n_group1];
    printf("請輸入第一組數列: ");
    for (int i = 0; i < n_group1; i++) {
        scanf("%d", &group1[i]);
    }

    // 輸入第二組數列
    printf("請輸入第二組數列有多少數字: ");
    check_input(&n_group2);

    int group2[n_group2];
    printf("請輸入第二組數列: ");
    for (int i = 0; i < n_group2; i++) {
        scanf("%d", &group2[i]);
    }

    // 找出交集並輸出
    int index = find_intersection_with_count(group1, n_group1, group2, n_group2, result, count);
    if (index == 0) {
        printf("-1\n");
        return 0;
    }

    // 輸出交集及其次數
    for (int i = 0; i < index; i++) {
        printf("%d (%d) ", result[i], count[i]);
    }
    printf("\n");

    printf("bonus（排序次數從大到小）: ");

    bubble_sort(count, result, index);
    for (int i = 0; i < index; i++) {
        printf("%d (%d) ", result[i], count[i]);
    }
    printf("\n");

    return 0;
}
