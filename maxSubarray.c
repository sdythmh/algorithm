#include <stdio.h>
#include <stdlib.h>

int findMax(int* num, int len){
    int *dp = (int *)malloc(len*sizeof(int));
    dp[0] = num[0];
    for(int i=1;i<len;i++){
        if(dp[i-1] > 0){
            dp[i] = dp[i-1] + num[i];
        }else{
            dp[i] = num[i];
        }
    }
    int myMax = dp[0];
    for(int i=1;i<len;i++){
        if(dp[i] > myMax){
            myMax = dp[i];
        }
    }
    free(dp);
    return myMax;
}

int main(){
    
    int num[9] = {-2,1,-3,4,-1,2,1,-5,4};
    printf("%d\n",findMax(num,9));
    int num2[1] = {1};
    printf("%d\n",findMax(num2,1));
    int num3[5] = {5,4,-1,7,8};
    printf("%d\n",findMax(num3,5));
    system("pause");
    return 1;
}