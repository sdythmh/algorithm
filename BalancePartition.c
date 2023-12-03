#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

void miniDiff(int S[], int size){
    int diff = 0;
    int sum = 0;
    for(int i=0;i<size;i++){
        sum += S[i];
    }

    bool dp[size+1][sum+1];

    for(int i = 0; i<= size;i++){
        dp[i][0] = TRUE;
    }

    for (int j = 1;j <=sum;j++){
        dp[0][j] = FALSE;
    }

    for(int i=1;i<=size;i++){
        for(int j= 1;j<=sum;j++){
            if(S[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j] || dp[i-1][j-S[i-1]];
            }
        }
    }

    int index = 0;
    int res[50];

    for(int i=size;i>=1;i--){
        for(int j = sum/2 + 1;j>=1;j--){
            if(dp[i][j]){
                diff = abs(sum - 2*j);
                int k = i;
                int temp = j;
                while(k){
                    if(dp[k][temp] && !dp[k-1][temp]){
                        res[index++] = S[k-1];
                        temp -= S[k-1];
                    }
                    if(!temp){
                        break;
                    }
                    k--;
                }
                goto Label1;
            }
        }
    }
Label1:
    printf("最小偏差为：%d\n",diff);
    
    int other[50];
    int index2 = 0;
    int x = 0;
    for(x ;x < size;x++){
        int flag = 1;
        for(int y = 0; y < index ;y++){
            if(S[x] == res[y]){
                flag = 0;
            }
        }
        if(flag){
            other[index2++] = S[x];
        }
    }

    for(int j= index-1;j>=0;j--){
        printf("%d ",res[j]);
    }
    printf(" and ");

    for(int j= 0;j < index2 ;j++){
        printf("%d ",other[j]);
    }
    printf("\n");
}

int main(){
    int S[4] = {1,2,2,7};
    miniDiff(S,4);
    system("pause");
    return 0;
}