#include <iostream>
using namespace std;

class Graph{
    public:
    int n;      //总顶点数
    int **a;    //邻接矩阵
    int *x;     //大小为i+1,从1开始，代表第i个顶点用什么颜色
    int m;      //总颜色数
    void backTrack(int t);
    bool ok(int k);
    int sum;    //可行解个数
};

void Graph::backTrack(int t){
    if(t > n){
        sum++;
    }else{
        for(int i=1;i<=m;i++){
            x[t] = i;       //第t个顶点位置为颜色i
            if(ok(t)){
                backTrack(t+1);
            }
        }
    }
}

bool Graph::ok(int k){
    for(int i=1;i<k;i++){           //在顶点k之前的所有结点
        if(a[i][k] && (x[i] == x[k])){  //如果相邻且着色一样
            return false;
        }
    }
    return true;
}

int main(){
    Graph g;
    cout << "请输入总顶点数：" << endl;
    cin >> g.n;
    cout << "请依次输入两个顶点之间边的关系（0代表没有边相连，1代表有边相连）：" << endl;
    g.a = new int*[g.n+1];
    for(int i=0;i<=g.n;i++){
        g.a[i] = new int[g.n+1];
    }
    for(int i=1;i<=g.n;i++){          //初始化
        for(int j=1;j<=g.n;j++){
            g.a[i][j] = 0;
        }
    }
    for(int i=1;i<=g.n;i++){
        for(int j=i+1;j<=g.n;j++){
            cout << "请输入第" << i << "个顶点和第" << j << "个顶点之间是否有边相连"<<endl;
            cin >> g.a[i][j];
        }
    }
    for(int i=1;i <= g.n;i++){      //对称化
        for(int j=i+1;j<=g.n;j++){
            g.a[j][i] = g.a[i][j];
        }
    }
    cout << "请输入所有颜色的个数："<<endl;
    cin >> g.m;
    g.x = new int[g.n+1];
    for(int i=0;i<=g.n;i++){
        g.x[i] = 0;
    }
    g.sum = 0;
    g.backTrack(1);
    cout << "可行解可数为：" << g.sum << endl;

    system("pause");
    return 0;
}