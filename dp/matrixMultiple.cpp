#include<iostream>
using namespace std;

int n;      //矩阵的个数
int p[100];         //第i个矩阵的规模为p[i-1]*p[i]，从0开始
int m[100][100];    //m[i][j]为第i个矩阵到第j个矩阵的连乘次数，从1开始
int s[100][100];    //辅助数组s记录第i个矩阵到第j个矩阵的分割策略，从1开始

void matrixChain(int *p, int n, int (*m)[100], int (*s)[100]){
    for(int i=1;i<=n;i++){          //一个矩阵不需要相乘，所以次数为0
        m[i][i] = 0;
    }
    for(int r = 2;r<=n;r++){
        for(int i = 1;i<= n -r +1;i++){             //i是左边界，j是右边界
            int j = r+i-1;                    //j-i+1 = r
            m[i][j] = m[i][i] + m[i+1][j] + p[i-1]*p[i]*p[j];       //先假定切分点是从第一个（i）开始的，然后从i+1开始遍历后面的切分点
            s[i][j] = i;
            for(int k= i+1;k<j;k++){
                int t = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(t < m[i][j]){
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        }
    }
}

void TraceBack(int i, int j, int (*s)[100]){
    if(i==j){
        return;
    }
    TraceBack(i,s[i][j],s);
    TraceBack(s[i][j]+1,j,s);
    cout << i << " , " << s[i][j];
    cout << " and " << s[i][j]+1 << " , " << j << endl;
}

int main(){
    cout << "请输入矩阵的个数：" << endl;
    cin >> n;
    cout << "请依次输入矩阵的长和宽（矩阵个数+1的数据）：" << endl;
    for(int i=0;i<=n;i++){
        cin >> p[i];
    }
    matrixChain(p,n,m,s);
    TraceBack(1,n,s);

    system("pause");
    return 0;
}