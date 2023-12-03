#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int maxPro(int *num,int len){
    int sum = 0;
    for(int i=1;i<len;i++){
        if(num[i]-num[i-1] > 0){
            sum += num[i]-num[i-1];
        }
    }
    return sum;
}

//0表示现金，1表示股票
int maxProfit(int *num, int len){
    int dp[len][2];
    dp[0][0] = 0;
    dp[0][1] = (-1)*num[0];
    for(int i=1;i<len;i++){
        dp[i][0] = fmax(dp[i-1][0], dp[i-1][1] + num[i]);
        dp[i][1] = fmax(dp[i-1][1], dp[i-1][0] - num[i]);
    }
    return dp[len-1][0];
}

int main(){
    int nums1[6] = {7,1,5,3,6,4};
    printf("%d\n",maxProfit(nums1,6));
    int nums2[5] = {1,2,3,4,5};
    printf("%d\n",maxProfit(nums2,5));
    int nums3[5] = {7,6,4,3,1};
    printf("%d\n",maxProfit(nums3,5));
    system("pause");
    return 1;
}