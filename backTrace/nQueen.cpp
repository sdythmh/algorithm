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
        if(abs(k-j) == abs(x[k] - x[j]) || x[j] == x[k]){       //和之前的皇后位置不能重叠也不能在对角线上
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
            x[t] = i;           //假定先把第t个皇后放在i位置
            if(Place(t)){       //如果能放
                BackTrack(t+1); //则继续放第t+1个皇后
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