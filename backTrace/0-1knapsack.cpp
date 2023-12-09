#include <iostream>
using namespace std;

class Knapsack{
    public:
    int n;//物品数量
    double c;//背包容量
    double *v;//各个物品的价值　value       从1开始
    double *w;//各个物品的重量　weight      从1开始
    double cw;//当前背包重量　current weight
    double cp;//当前背包中物品总价值　current value
    double bestp;//当前最优价值best price

    void sortByValue(Knapsack k);
    void BackTrack(int i);
    double bound(int i);
};

void Knapsack::sortByValue(Knapsack k){         //采用类似选择排序的方法
    int s;
    double temp1, temp2;
    for(int i=1;i<k.n;i++){
        s = i;
        for(int j=i+1;j<=k.n;j++){
            if(k.v[j]/k.w[j] > k.v[s]/k.w[s]){
                s = j;
            }
        }
        if(s != i){
            temp1 = k.v[s];
            k.v[s] = k.v[i];
            k.v[i] = temp1;
            temp2 = k.w[s];
            k.w[s] = k.w[i];
            k.w[i] = temp2;
        }
    }
}

void Knapsack::BackTrack(int i){
    if(i > n){
        bestp = cp;
        return;
    }
    if(cw + w[i] <= c){
        cw += w[i];
        cp += v[i];
        BackTrack(i+1);
        cw -= w[i];
        cp -= v[i];
        if(bound(i+1) > bestp){
            BackTrack(i+1);
        }
    }
}

double Knapsack::bound(int i){
    double cleft = c - cw;
    double b = cp;
    while(i <=n && w[i] <= cleft){
        cleft -= w[i];
        b += v[i];
        i++;
    }
    //装满背包
    if(i <= n){
        b += v[i]/w[i]*cleft;
    }
    return b;
}

int main(){
    Knapsack bag;
    cout << "请输入背包中所有物品总数："<<endl;
    cin >> bag.n;
    cout << "请输入背包容量：" << endl;
    cin >> bag.c;
    bag.w = new double[bag.n+1];
    cout << "请依次输入物品的重量：" << endl;
    for(int i=1;i<=bag.n;i++){
        cin >> bag.w[i];
    }
    bag.v = new double[bag.n+1];
    cout << "请依次输入物品的价值：" << endl;
    for(int i=1;i<=bag.n;i++){
        cin >> bag.v[i];
    }
    bag.cw = bag.cp = bag.bestp = 0;
    bag.sortByValue(bag);
    bag.BackTrack(1);
    cout << "背包最多能装价值为" << bag.bestp << "的物品" << endl;
    delete[] bag.w;
    delete[] bag.v;

    system("pause");
    return 0;
}