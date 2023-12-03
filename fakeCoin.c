#include <stdio.h>
#include <stdlib.h>
#define N 16
int array[N];
int ResA=0, ResB=0;
int getSum(int[] arr, int p, int q){
    int sum = 0;
    for(i = p;i<=q;i++){
        sum += arr[i];
    }
    return sum;
}
int findFake(int[] arr, int fir, int las){
    if(fir == las){return fir};
    int mid = (fir + las)/2;
    ResA = getSum(arr, fir, mid);
    ResB = getSum(arr, mid+1,las);
    if(ResA == ResB){
        printf("不存在假币\n");
    }
    if(ResA < ResB){
        findFake(arr, fir, mid);
    }else{
        findFake(arr, mid+1, las);
    }
}
int main(){
    printf("假币的个数为%d",findFake(array,0,15));
    return 1;
}