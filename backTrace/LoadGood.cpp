#include <iostream>
using namespace std;

int weight[6] = {0,2,4,6,8,10};     //从下标为1开始
int maxWeight = 7;      //能装载的最大重量
int maxNum = 5;         //最大货物数
int bestValue;          //最好的载重量
int bestWeight[6];      //最好载重量时对应的装载方案
int w[6]= {0};          //当前装载方案
int num = 0;            //当前装载数量
int bestNum;            //最优装载数量

void dfs(int i, int cw, int rw){        //cw对应为当前载重量，rw对应为剩余载重量
    if(i > maxNum){     //到达叶子节点
        if(cw > bestValue){
            for(int i=1;i<=5;i++){
                bestWeight[i] = w[i];
            }
            bestValue = cw;
            bestNum = num;
        }
    }

    rw -= weight[i];
    if(cw + weight[i] <= maxWeight){
        w[i] = 1;
        cw += weight[i];
        num++;
        dfs(i+1,cw,rw);
        num--;
        cw -= weight[i];
    }
    if(cw + rw > bestValue){
        w[i] = 0;
        dfs(i+1,cw,rw);
    }
    rw += weight[i];
}

int main(){
    dfs(1,0,30);
    cout << "最大值为：" << bestValue << endl;
    cout << "最好的方案是：";
    for(int i = 1;i<=5;i++){
        cout << bestWeight[i] << " ";
    }
    cout << endl << "共有" << bestNum << "种货物"<<endl;
    system("pause");
    return 0;
}