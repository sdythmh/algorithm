#include <iostream>
#include <cstring>
using namespace std;

void LCS(int m, int n, char* x, char* y, int **c, int **b){      //c从0开始，b从1开始
    for(int i=1;i<=m;i++){
        c[i][0] = 0;        //第一个子序列长度为i，第二个子序列长度为0
    }
    for(int i=1;i<=n;i++){
        c[0][i] = 0;
    }
    c[0][0] = 0;        //初始化
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(x[i-1] == y[j-1]){       //注意这里字符串是从0开始的
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 1;
            }else if(c[i-1][j] >= c[i][j-1]){
                c[i][j] = c[i-1][j];
                b[i][j] = 2;
            }else{
                c[i][j] = c[i][j-1];
                b[i][j] = 3;
            }
        }
    }
}

void TraceBack(int i, int j, char* x, int **b){
    if(i ==0 || j==0){
        return;
    }
    if(b[i][j] == 1){
        TraceBack(i-1,j-1,x,b);
        cout << x[i-1];
    }else if(b[i][j] == 2){         //这里是==不是=         qaq
        TraceBack(i-1,j,x,b);
    }else{
        TraceBack(i,j-1,x,b);
    }
}

int main(){
    cout << "请输入两个字符串（中间用回车隔开）：" << endl;
    char x[100], y[100];            //这里不能直接赋值，因为x和y未分配合法的有用空间
    cin >> x;
    cin >> y;
    int m = strlen(x);
    int n = strlen(y);
    int **c = new int*[m+1];
    for(int i=0;i<=m;i++){
        c[i] = new int[n+1];
    }
    int **b = new int*[m+1];
    for(int i=0;i<=m;i++){
        b[i] = new int[n+1];
    }
    LCS(m,n,x,y,c,b);
    TraceBack(m,n,x,b);
    cout << endl;

    for(int i=0;i<=m;i++){
        delete[] c[i];
    }
    delete[] c;
    for(int i=0;i<=m;i++){
        delete[] b[i];
    }
    delete[] b;

    system("pause");
    return 0;
}