#include <iostream>
using namespace std;
const int NoEdge = 0x3f3f3f3f;      //没有边，定义为无穷大

class Traveling{
    public:     //不声明public默认为private
    int n;      //总城市的个数
    int *x;     //大小为n+1,为第i步去x[i]城市，注意因为是最后要形成环，所以从0开始
    int **a;    //邻接矩阵，下标都是从1开始
    int cc;     //当前路径长度
    int bestc;  //最好路径长度
    int *bestx; //最好路径方案
    void mySwap(int *a, int *b);
    void backTrack(int t);
};

void Traveling::mySwap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Traveling::backTrack(int t){       //注意t-1才是当前的边
    if(t == n){
        if(a[x[t-1]][x[t]] != NoEdge && a[x[t]][1] != NoEdge && cc+a[x[t-1]][x[t]]+a[x[t]][1] < bestc){
            for(int i=1;i<=n;i++){
                bestx[i] = x[i];
            }
            bestc = cc+a[x[t-1]][x[t]]+a[x[t]][1];
        }
    }else{
        for(int j=t;j<=n;j++){
            if(a[x[t-1]][x[j]] != NoEdge && cc+ a[x[t-1]][x[j]] < bestc){   //判断是否能进入子树
                mySwap(&x[t],&x[j]);
                cc += a[x[t-1]][x[j]];
                backTrack(t+1);
                cc -= a[x[t-1]][x[j]];
                mySwap(&x[t],&x[j]);
            }
        }
    }
}

int main(){
    Traveling tv;
    cout << "请输入城市的个数：" << endl;
    cin >> tv.n;
    tv.x = new int[tv.n+1];
    for(int i = 0;i<tv.n;i++){
        tv.x[i] = i+1;
    }
    tv.x[tv.n] = 1;     //最后回到起点
    cout << "请依次输入两个城市之间边的距离：" << endl;
    tv.a = new int*[tv.n+1];
    for(int i=0;i<=tv.n;i++){
        tv.a[i] = new int[tv.n+1];
    }
    for(int i=1;i<=tv.n;i++){          //初始化
        for(int j=1;j<=tv.n;j++){
            tv.a[i][j] = 0;
        }
    }
    for(int i=1;i<=tv.n;i++){
        for(int j=i+1;j<=tv.n;j++){
            cout << "请输入第" << i << "个城市和第" << j << "个城市之间的距离"<<endl;
            cin >> tv.a[i][j];
        }
    }
    for(int i=1;i <= tv.n;i++){      //对称化
        for(int j=i+1;j<=tv.n;j++){
            tv.a[j][i] = tv.a[i][j];
        }
    }
    tv.cc = 0;
    tv.bestc = NoEdge;
    tv.bestx = new int[tv.n+1];
    for(int i=0;i<tv.n;i++){
        tv.bestx[i] = i+1;
    }
    tv.bestx[tv.n] = 1;     //回到起点
    tv.backTrack(1);
    cout << "最短路径为：" << tv.bestc << endl;
    cout << "方案为：";
    for(int i=0;i<=tv.n;i++){
        cout << tv.bestx[i] << " ";
    }
    cout << endl;
    delete[] tv.x;
    delete[] tv.bestx;
    for(int i=0;i<=tv.n;i++){
        delete[] tv.a[i];
    }
    delete[] tv.a;

    system("pause");
    return 0;
}

/*测试用例
4
30 6 4 5 10 20
最短路径为：49
方案为：1 3 2 4 1
*/