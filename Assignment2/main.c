//
//  main.c
//  C-course_assignment
//
//  Created by Eric Yang on 10/22/24.
//

#include <stdio.h>
//加法函式
void add(int num1[], int num2[], int result[]) {
    int carry = 0;
    for (int i = 9; i >= 0; i--) {
        int sum = num1[i] + num2[i] + carry;
        if (sum >= 10){
            result[i + 1] = sum - 10;
            carry = 1;
        } else {
            result[i + 1] = sum;
            carry = 0;
        }
    }
    result[0] = carry; //用於處理進位
}
//減法函式
void sub(int num1[], int num2[], int result[]) {
    int borrow = 0;
    for (int i = 9; i >= 0; i--) {
        int diff = num1[i] - num2[i] - borrow;
        if (diff < 0) {
            result[i] = diff + 10;
            borrow = 1;
        } else {
            result[i] = diff;
            borrow = 0;
        }
    }
}

int main(void) {
    int mode, i = 0;
    int num1[10], num2[10], result[11] = {0};
    
    printf("請選擇模式。0 是加法，1 是減法:");
    scanf("%d", &mode);
    
    if (mode != 0 && mode != 1) {
        printf("輸入錯誤，請重新執行程式\n");
        return 0;
    }
    
    printf("請輸入第一組10位大數: ");
    for (i = 0; i < 10; i++) {
        scanf("%1d", &num1[i]);  // 輸入第一組大數
    }

    printf("請輸入第二組10位大數: ");
    for (i = 0; i < 10; i++) {
        scanf("%1d", &num2[i]);  // 輸入第二組大數
    }

    if (mode == 0) {  // 加法模式
        add(num1, num2, result);
        printf("加法結果: ");
        int start = result[0] == 0 ? 1 : 0; //判斷是否有進位，如果沒有那從第一位開始輸出
        for (i = start; i < 11; i++) {
            printf("%d", result[i]);
        }
        printf("\n");
    } else if (mode == 1) {  // 減法模式
        sub(num1, num2, result);
        printf("減法結果: ");
        for (i = 0; i < 10; i++) {
            printf("%d", result[i]);
        }
        printf("\n");
    }
    return 0;
}
