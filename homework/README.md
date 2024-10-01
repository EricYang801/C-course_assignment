# Homework 1: 出國天數計算機  
**4112052024 生科二 楊捷壬**

## 簡介及設計思維 

這次作業的目的是撰寫一個程式，用來計算在不同城市旅遊時，依據預算、旅客人數、機票價格、匯率及每日花費，能夠旅遊的天數。  

這次程式我原本是想以字元陣列作為主要資料結構做編寫，但編寫途中發現，在 C 語言中，字元陣列（char array）需要先宣告容器大小，因為 C 語言無法動態調整陣列的大小，可以動態調整字元陣列的方法只能透過動態記憶體，其中指標這個概念再我多次閱讀之後還不是很理解，因此改用 **Struct 結構體** 作為主要的資料結構

## 程式概述
### 功能描述
- User輸入多組資料，每組資料包含：
  - 預算 (`budget`)
  - 人數 (`num_people`)
  - 城市代號 (`capital`)
- 根據所選擇的城市，計算可以旅遊的天數。

### 資料結構及變數說明
1. `TripGroup`: 儲存使用者輸入每組旅遊資訊的結構
    - `budget`: 旅遊預算（`int`）
    - `num_people`: 旅遊人數（`int`）
    - `capital`: 目的地城市代碼（`int`）

2. `TripCost`: 儲存每個城市的費用資訊的結構
    - `flight_price`: 機票價格（`int`）
    - `exchange_rate`: 匯率（`float`）
    - `daily_cost`: 每日開銷（`int`）

### `calculate_days` 函數內變數
此處local作為變數名稱命名前綴，一部分是因為 **當地** 一部分是因為 **區域變數（local variables）**
1. `local_budget`: 同時作為當前的旅遊預算以及扣除機票後所剩餘金額（`int`，來自 `TripGroup` 結構）
2. `local_num_people`: 旅遊人數（`int`，來自 `TripGroup` 結構）
3. `flight_price`: 機票價格（`int`，來自 `TripCost` 結構）
4. `exchange_rate`: 匯率，用於換算當地貨幣（`float`，來自 `TripCost` 結構）
5. `daily_cost`: 每日花費（`int`，來自 `TripCost` 結構）
6. `days`: 計算出的可旅遊天數，並回傳（`int`）

### 主程式變數

1. `data_count`: User輸入的資料組數（`int`）
2. `i`: 迴圈計數器，用於遍歷每組資料（`int`）
3. `group`: 儲存每組旅遊資料的結構陣列（`TripGroup[]`）
4. `cost_table`: 結構陣列，包含每個城市的費用資訊（`TripCost[]`）

#### cost_table城市對應表
cost_table 定義了多個城市的費用資訊，對應的索引為城市代號：
- 0: 東京 (Tokyo)
- 1: 首爾 (Seoul)
- 2: 曼谷 (Bangkok)
- 3: 倫敦 (London)
- 4: 巴黎 (Paris)
- 5: 紐約 (New York)
- 6: 雪梨 (Sydney)
- 7: 台北 (Taipei) 

## 程式說明

### calculate_days函式說明  

#### 傳入參數
- local_budget：User輸入該組總預算。
- local_num_people：User輸入該組旅行人數。
- flight_price：每張機票的價格。
- exchange_rate：匯率。
- daily_cost：每人每日的花費。

```c
int calculate_days(int local_budget, int local_num_people, int flight_price, float exchange_rate, int daily_cost) {
    if (local_budget - (local_num_people*flight_price) <= 0) {
        return -1; //若預算不夠支付所有人的機票，回傳 -1
    }
    local_budget = local_budget - (local_num_people*flight_price); //扣掉機票
    local_budget *= exchange_rate; // 乘以匯率 換匯
    int days = local_budget/(daily_cost*local_num_people); // 除以每日花費
    
    return days < 1 ? 0 : days; //假如days<1天，回傳0，否則回傳days值
}
```
### 主程式說明  

