#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

void isSubsetSum(int S[], int n, int M){
    bool subset[n+1][M+1];
    for(int i=0;i<=n;i++){
        subset[i][0] = TRUE;
    }
    for(int j=1;j<=M;j++){
        subset[0][j] = FALSE;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=M;j++){
            if(S[i-1] > j){
                subset[i][j] = subset[i-1][j];
            }else{
                subset[i][j] = subset[i-1][j] || subset[i-1][j-S[i-1]];
            }
        }
    }

    for(int i=0;i<=n;i++){
        for(int j = 0;j <= M;j++){
            printf("%d ",subset[i][j]);
        }
        printf("\n");
    }

    //利用回溯法确定子集中的元素
    if(subset[n][M]){
        printf("找到了一个子集！\n");
        int res[50];
        int index = 0;
        int i = n;
        while(i){
            if(subset[i][M] && !subset[i-1][M]){
                res[index++] = S[i-1];
                M -= S[i-1];
            }
            if(!M){
                break;
            }
            i--;
        }
        printf("结果是：");
        for(int j= index-1;j>=0;j--){
            printf("%d ",res[j]);
        }
        printf("\n");
    }else{
        printf("没有找到复合要求的子集！\n");
    }
}

int main(){
    int S[4] = {1,3,4,5};
    isSubsetSum(S,4,13);
    system("pause");
    return 0;
}