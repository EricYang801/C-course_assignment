//
//  main.c
//  homework
//
//  Created by Eric Yang.
//

#include <stdio.h>

int calculate_days(int local_budget, int local_num_people, int flight_price, float exchange_rate, int daily_cost) {
    if (local_budget - (local_num_people*flight_price) < 0) {
        return -1;  //若預算不夠支付所有人的機票，回傳 -1
    }
    local_budget = local_budget - (local_num_people*flight_price); //扣掉機票
    local_budget *= exchange_rate; // 乘以匯率 換匯
    int days = local_budget/(daily_cost*local_num_people); // 除以每日花費
    
    return days < 1 ? 0 : days;
}
int main(void) {
    
    int data_count, i, days;
    
    struct TripGroup{
        int budget;
        int num_people;
        int capital;
    };
    
    struct TripCost {
        int flight_price;
        float exchange_rate;
        int daily_cost;
    };
    
    const struct TripCost cost_table[] = {
        { 15000, 4, 15000},     // 0: Tokyo
        { 10000, 40, 60000},    // 1: Seoul
        { 12000, 1.1, 2000},    // 2: Bangkok
        { 35000, 0.025, 200},   // 3: London
        { 33000, 0.03, 180},    // 4: Paris
        { 40000, 0.032, 220},   // 5: New York
        { 32000, 0.048, 250},   // 6: Sydney
        { 0, 1, 3000}           // 7: Taipei
    };
    
    printf("請輸入資料數量: ");
    if (scanf("%d", &data_count) != 1 || data_count <= 0) {
         printf("輸入無效，請輸入一個正整數。\n");
         return 1;
    }
    
    struct TripGroup group[data_count];
    
    printf("請輸入每組資料(預算 人數 城市代碼):\n");
    printf("城市代碼: 0.Tokyo 1.Seoul 2.Bangkok 3.London 4.Paris 5.New York 6.Sydney 7.Taipei\n");
    
    for (i=0; i<data_count; i++) {
        printf("現在輸入的是第 %d 組的資料:", i+1);
        scanf("%d %d %d",
              &group[i].budget,
              &group[i].num_people,
              &group[i].capital);
        if (group[i].budget <= 0 || group[i].num_people <= 0 ) {
            printf("輸入無效，請重新輸入。\n");
            while (getchar() != '\n');  // 清除輸入緩衝區 ChatGPT生成的一行程式
            i--;
        }
    }
    
    for (i=0; i<data_count; i++) {
        switch (group[i].capital) {
            case 0: //Tokyo
                days = calculate_days(group[i].budget,
                                      group[i].num_people,
                                      cost_table[group[i].capital].flight_price,
                                      cost_table[group[i].capital].exchange_rate,
                                      cost_table[group[i].capital].daily_cost);
                if (days == -1) {
                    printf("-1");
                } else {
                    printf("%d", days);
                }
                
                break;
            case 1: //Seoul
                days = calculate_days(group[i].budget,
                                      group[i].num_people,
                                      cost_table[group[i].capital].flight_price,
                                      cost_table[group[i].capital].exchange_rate,
                                      cost_table[group[i].capital].daily_cost);
                if (days == -1) {
                    printf("-1");
                } else {
                    printf("%d", days);
                }

                break;
            case 2: //Bangkok
                days = calculate_days(group[i].budget,
                                      group[i].num_people,
                                      cost_table[group[i].capital].flight_price,
                                      cost_table[group[i].capital].exchange_rate,
                                      cost_table[group[i].capital].daily_cost);
                if (days == -1) {
                    printf("-1");
                } else {
                    printf("%d", days);
                }

                break;

            case 3: //London
                days = calculate_days(group[i].budget,
                                      group[i].num_people,
                                      cost_table[group[i].capital].flight_price,
                                      cost_table[group[i].capital].exchange_rate,
                                      cost_table[group[i].capital].daily_cost);
                if (days == -1) {
                    printf("-1");
                } else {
                    printf("%d", days);
                }

                break;

            case 4: //Paris
                days = calculate_days(group[i].budget,
                                      group[i].num_people,
                                      cost_table[group[i].capital].flight_price,
                                      cost_table[group[i].capital].exchange_rate,
                                      cost_table[group[i].capital].daily_cost);
                if (days == -1) {
                    printf("-1");
                } else {
                    printf("%d", days);
                }

                break;

            case 5: //New York
                days = calculate_days(group[i].budget,
                                      group[i].num_people,
                                      cost_table[group[i].capital].flight_price,
                                      cost_table[group[i].capital].exchange_rate,
                                      cost_table[group[i].capital].daily_cost);
                if (days == -1) {
                    printf("-1");
                } else {
                    printf("%d", days);
                }

                break;

            case 6: //Sydney
                days = calculate_days(group[i].budget,
                                      group[i].num_people,
                                      cost_table[group[i].capital].flight_price,
                                      cost_table[group[i].capital].exchange_rate,
                                      cost_table[group[i].capital].daily_cost);
                if (days == -1) {
                    printf("-1");
                } else {
                    printf("%d", days);
                }

                break;

            case 7: //Taipei
                days = calculate_days(group[i].budget,
                                      group[i].num_people,
                                      cost_table[group[i].capital].flight_price,
                                      cost_table[group[i].capital].exchange_rate,
                                      cost_table[group[i].capital].daily_cost);
                if (days == -1) {
                    printf("-1");
                } else {
                    printf("%d", days);
                }

                break;

            default:
                printf("-2");
                break;
        }
        if (i < data_count - 1) {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}
