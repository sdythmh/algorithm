#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 1000000000;
int dp[1005][1005];       

int myMin(int x, int y, int z){
    int temp = x < y ? x : y;
    int res = temp < z ? temp : z;
    return res;
}

int EditDis(char* a, char* b){
    int len1 = strlen(a+1);          //字符串从下标为1处开始算起
    int len2 = strlen(b+1);

    for(int i=1;i<=len1;i++){
        for(int j=1;j<=len2;j++){
            dp[i][j] = INF;
        }
    }

    for(int i=1;i<=len1;i++){
        dp[i][0] = i;
    }

    for(int j=1;j<=len2;j++){
        dp[0][j] = j;
    }

    for(int i=1;i<=len1;i++){
        for(int j=1;j<=len2;j++){
            int flag = a[i] == b[j] ? 1: 0;
            dp[i][j] = myMin(dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1] + flag);
        }
    }

    return dp[len1][len2];
}

int main(){
    char a[6] = "@cafe";
    char b[8] = "@coffee";
    printf("Edit Distance is %d\n",EditDis(a,b));
    system("pause");
    return 0;
}