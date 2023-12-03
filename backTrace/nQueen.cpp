#include <iostream>
#include <cmath>
using namespace std;

class Queen{
    public:
    int n;      //皇后的个数
    int *x;     //第n个皇后所在的位置
    int sum;        //所有可能的情况
    bool Place(int k);
    void BackTrack(int t);
};

bool Queen::Place(int k){
    for(int j= 1;j<k;j++){
        if(abs(k-j) == abs(x[k] - x[j]) || x[j] == x[k]){
            return false;
        }
    }
    return true;
}

void Queen::BackTrack(int t){
    if(t > n){
        sum++;
    }else{
        for(int i=1;i<=n;i++){
            x[t] = i;
            if(Place(t)){
                BackTrack(t+1);
            }
        }
    }
}

int main(){
    Queen q;
    cout << "请输入皇后的个数：" << endl;
    cin >> q.n;
    q.x = new int[q.n + 1];
    for(int i=0;i<=q.n;i++){
        q.x[i] = 0;
    }
    q.sum = 0;
    q.BackTrack(1);
    cout << "共有" << q.sum << "种情况满足"<<endl;
    delete[] q.x;

    system("pause");
    return 0;
}