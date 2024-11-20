# Homework 3: Find intersection of two 1D arrays
**4112052024 生科二 楊捷壬**

## 簡介及設計思維 

接受兩個數列作為輸入。  
找出這兩個數列的交集，並計算交集中每個數字的共同出現次數。  
將結果排序後輸出。

## 流程圖

以下是程式執行流程的簡化示意圖：


## 程式概述
### 功能描述
User輸入四筆資料，資料包含：
- 第一組數列有多少數字:
- 第一組數列
- 第二組數列有多少數字
- 第二組數列
### 資料結構及變數說明
#### 數列 (Array)

1. **整數型數列 `group1[]` 與 `group2[]`**  
   - 兩數列分別用來儲存User輸入的兩組數字。  
   - `group1[]` 儲存第一組數列，`group2[]` 儲存第二組數列。

2. **整數型數列 `result[]`**  
   - 這個數列用來儲存兩個數列的有交集的數字。  

3. **整數型數列 `count[]`**  
   - 這個數列用來儲存交集中每個數字出現的次數。
   - `count[]` 和 `result[]` 的索引對應。

### 整數變數

1. **`n_group1` 與 `n_group2`**  
   - 這兩個變數分別儲存第一組數列 (`group1[]`) 和第二組數列 (`group2[]`) 的數字個數。  
   - 這些變數由User輸入，確定數列的長度。

2. **`index`**  
   - 這個變數用來記錄交集中數字的數量。  

3. **`temp`**  
   - 這個變數是用來bubble_sort函式中交換 `result[]` 和 `count[]` 數列元素時的臨時存儲空間。

### 函式參數

1. **`arr1` 與 `arr2`**  
   - 這兩個參數分別是兩個整數型數列的指標，指向用戶輸入的兩組數列。  
   - `arr1` 代表第一組數列，`arr2` 代表第二組數列。

2. **`n1` 與 `n2`**  
   - 這兩個變數分別代表 `arr1` 和 `arr2` 數列的長度，對應於 `n_group1` 和 `n_group2`。

3. **`result[]` 與 `count[]`**  
   - 這兩個數列儲存交集數字及其出現次數，並由函式進行處理和返回。

---
## 程式說明
## 程式架構與主要函式

### 驗證輸入的數字是否有效 (`check_input`)

此函式負責檢查用戶輸入的數字是否有效，例如是否為正整數。  
如果輸入無效，程式會要求用戶重新輸入，直到輸入正確。

```c
void check_input(int *num) {
    while (scanf("%d", num) != 1 || *num <= 0) {
        printf("輸入無效，請重新輸入\n");
        printf("請輸入數列的數字個數: ");

        // 清除輸入緩衝區
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
}
```
### 找出兩個數列的交集及其出現次數 `(find_intersection_with_count)` 
此函式通過記錄兩個數列中每個數字的出現次數，找出交集數字，並計算交集中每個數字的共同出現次數（取兩數列中較小的次數）。
```c
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
```

### 使用氣泡排序法 `(bubble_sort)`，將交集中數字的次數降冪排列，並根據次數重新排列數字。
```c
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
```
### 主程式 `(main)`
主程式負責：

接收兩組數列的輸入。  
呼叫相關函式找出交集及其次數。  
輸出交集結果及次數，並按次數降冪排列後再次輸出。
```c
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
```