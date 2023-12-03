#include <stdio.h>
#include <stdlib.h>
//https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/?envType=study-plan-v2&envId=top-interview-150
int maxProfit2(int* price, int size){
    int buy1 = -price[0];
    int sell1 = 0;
    int buy2 = -price[0];
    int sell2 = 0;

    for(int i=1;i<size;i++){
        buy1 = buy1 > (-price[i]) ? buy1 : -price[i];
        sell1 = sell1 > (buy1 + price[i]) ? sell1 : (buy1 + price[i]);
        buy2 = buy2 > (sell1 - price[i]) ? buy2 : (sell1 - price[i]);
        sell2 = sell2 > (buy2 + price[i]) ? sell2 : (buy2 + price[i]);
    }

    return sell2;
}

int main(){
    int price[8] = {3,3,5,0,0,3,1,4};
    printf("%d\n",maxProfit2(price,8));
    system("pause");
    return 0;
}