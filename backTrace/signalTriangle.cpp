#include <iostream>
using namespace std;
class Triangle{
    friend int compute(int n);
    private:
    void BackTrack(int i);
    int half,
        **p,
        n,
        count;  //0为+，1为-，count记录-的个数
    long sum;   //符合要求的的三角形个数
};      //类声明完后要加;

void Triangle::BackTrack(int t){
    if(count > half || t*(t-1)/2 - count > half){
        return;
    }
    if(t > n){//找到了叶子结点
        sum++;
    }else{      //不是叶子结点
        for(int i=0;i<=1;i++){
            p[1][t] = i;            //这个代表第一行的符号是+（0）还是-（1）
            count +=i;
            for(int j=2;j<=t;j++){
                p[j][t-j+1] = p[j-1][t-j+1] ^ p[j-1][t-j+2];
                count += p[j][t-j+1];
            }
            BackTrack(t+1);
            for(int j = 2;j<=t;j++){
                count -= p[j][t-j+1];
            }
            count -= i;
        }
    }
}
int compute(int n){
    Triangle X;
    X.n = n;
    X.half = n*(n+1)/2;
    X.sum = 0;
    if(X.half %2 == 1){
        return 0;
    }
    X.half /= 2;
    X.count = 0;
    int **p = new int*[n+1];
    for(int i=0;i<=n;i++){
        p[i] = new int[n+1];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            p[i][j] = 0;
        }
    }
    X.p = p;
    X.BackTrack(1);
    for(int i=0;i<=n;i++){
        delete[] p[i];
    }
    delete[] p;
    return X.sum;
}

int main(){
    int n;
    cout << "请输入三角形第一行符号的个数："<< endl;
    cin >> n;
    cout << "找到了" << compute(n) << "种三角形"<<endl;

    system("pause");
    return 0;
}