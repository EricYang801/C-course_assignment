//
//  main.c
//  homework
//
//  Created by Eric Yang on 9/29/24.
//

#include <stdio.h>

int main(void) {
    
    int data_count, i;
    
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
         return 1;  // 結束程式
    }
    
    struct TripGroup group[data_count];
    
    for (i=0; i<data_count; i++) {
        printf("現在輸入的是第 %d 組的資料,", i+1);
        scanf("%d %d %d",
              &group[i].budget,
              &group[i].num_people,
              &group[i].capital);
    }
    
    int local_flight_price, local_daily_cost;
    float local_exchange_rate;
    int local_budget, local_num_people, days;
    
    for (i=0; i<data_count; i++) {
        switch (group[i].capital) {
            case 0: //Tokyo
                local_flight_price = cost_table[data_count].flight_price;
                local_exchange_rate = cost_table[data_count].exchange_rate;
                local_daily_cost = cost_table[data_count].daily_cost;
                
                local_budget = group[i].budget;
                local_num_people = group[i].num_people;
                
                if (local_budget - (local_num_people*local_flight_price) <= 0) {
                    printf("-1\n");
                    continue;
                }
                
                local_budget -= (local_num_people*local_flight_price); //扣掉機票
                local_budget *= local_exchange_rate; // 乘以匯率 換匯
                days = local_budget/(local_daily_cost*local_num_people); // 除以每日花費
                
                if (days < 1) {
                    printf("0");
                } else {
                    printf("%d", days);
                }
                break;
            case 1: //Seoul

            case 2: //Bangkok
                <#statements#>
                break;

            case 3: //London
                <#statements#>
                break;

            case 4: //Paris
                <#statements#>
                break;

            case 5: //New York
                <#statements#>
                break;

            case 6: //Sydney
                <#statements#>
                break;

            case 7: //Taipei
                <#statements#>
                break;

            default:
                printf("-2\n");
                continue;
        }
        if (i < data_count - 1) {
            printf(" ");
        }
    }
    
    
    return 0;
}
