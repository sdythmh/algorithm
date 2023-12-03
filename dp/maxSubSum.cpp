#include <iostream>
using namespace std;

int maxSubSum(int a[], int n, int& maxBegin, int& maxEnd){
    int b = 0, s = 0;
    int sum = 0;
    for(int i=0 ;i<n;i++){
        if(b > 0){
            b += a[i];
        }else{
            b = a[i];
            s = i;
        }
        if(b > sum){
            sum = b;
            maxBegin = s;
            maxEnd = i;
        }
    }
    return sum;
}


int maxMSubSum(int m, int n, int *a){
    int i,j,k,sum;
    if(n < m || m <1){
        return 0;
    }
    int b[m+1][n+1];        //前n个数分为m段，均从1开始
    for(i = 0;i<=m;i++){        //初始化
        for(j = 0;j<=n;j++){
            b[i][j] = 0;
        }
    }
    for(i = 1;i<=m;i++){        //划分为的段数进行遍历
        for(j = i;j <= n-m+i;j++){      //j >= i，并且要保证后面的元素也能划分成n-m+i段
            if(j == i){
                b[i][j] = b[i-1][j-1] + a[j];
            }else{
                b[i][j] = b[i][j-1] + a[j];
                for(k = i-1;k<j;k++){       //i-1 <= k <= j-1，对前面的k个元素划分为i-1段求出最大值，这时候前面的信息已知
                    if(b[i][j] < b[i-1][k] + a[j]){
                        b[i][j] = b[i-1][k] + a[j];
                    }
                }
            }
        }
    }
    sum = 0;
    //最后求出结果是只需在第m行即划分为m个字段中寻找即可
    for(j = m;j<=n;j++){
        if(sum < b[m][j]){
            sum = b[m][j];
        }
    }
    return sum;
}


int main(){
    int a[6] = {-2,11,-4,13,-5,-2};
    int begin = 0, end = 0;
    cout << "最大子段和为：" << maxSubSum(a,6,begin,end) << endl;
    cout << "起始索引为：" << begin << endl;
    cout << "终止索引为：" << end << endl;

    int b[8] = {0,1,-3,2,-9,2,5,10};
    cout << "最大子段和为：" << maxMSubSum(6,7,b) << endl;

    system("pause");
    return 0;
}