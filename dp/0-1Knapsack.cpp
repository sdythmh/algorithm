#include<iostream>
#include<cmath>
using namespace std;

int Knapsack(int n, int c, int w[], int v[], int x[]){      //w,v,x均从下标1开始
    int m[n+1][c+1];        //表示n个物品装入容量为c的背包的最大价值
    for(int i = 0;i<=c;i++){
        m[0][i] = 0;            //没有物品装入
    }
    for(int i=1;i<=n;i++){
        for(int j = 0;j<=c;j++){
            if(w[i] <= j){      //可以装下：①装入②不装入
                m[i][j] = max(m[i-1][j],m[i-1][j-w[i]]+v[i]);
            }else{
                m[i][j] = m[i-1][j];
            }
        }
    }
    //求出最优解数组
    int j = c;
    for(int i=n;i>=1;i--){
        if(m[i][j] == m[i-1][j]){
            x[i] = 0;
        }else{
            x[i] = 1;
            j -= w[i];
        }
    }
    return m[n][c];
}

int main(){
    int n,c;
    cout << "请分别输入货物总数和容量："<<endl;
    cin >> n >>c;
    int *w = new int[n+1];
    int *v = new int[n+1];
    int *x = new int[n+1];
    cout << "请依次输入每个货物的价值和重量："<<endl;
    for(int i = 1;i<=n;i++){
        cin >> v[i] >> w[i];
    }
    cout << "价值最大为：" << Knapsack(n,c,w,v,x) << endl;
    cout << "方案为：" << endl;
    for(int i=1;i<=n;i++){
        cout << x[i] << " ";
    }
    cout << endl;

    delete[] w;
    delete[] v;
    delete[] x;

    system("pause");
    return 0;
}

/*测试用例同branchBound里的0-1背包问题*/