#include <iostream>
using namespace std;

class Clique{
    public:
    int n;      //总顶点数
    int cn;     //当前结点数
    int **a;    //邻接矩阵
    int *x;     //大小为n+1，下标为0的不计入，记录从1到n个顶点是否加入最大团中
    int bestn;  //最多顶点数
    int *bestx; //记录所有x中最好的情况
    void backtrack(int t);
};

void Clique::backtrack(int t){      //t代表当前扩展结点的下一层编号
    if(t > n){//叶子结点
        if(cn > bestn){
            for(int i=1;i<=n;i++){
                bestx[i] = x[i];
            }
            bestn = cn;
            return;
        }
    }
    bool ok = true;
    for(int i=1;i<t;i++){
        if(x[i] == 1 && !a[i][t]){      //如果第i个结点已经放入，并且和当前遍历的t个结点不相邻（如果第t个顶点和之前加入的顶点都相连，则可以加入）
            ok = false;
            break;
        }
    }
    if(ok){
        x[t] = 1;       //加入第t个顶点
        cn++;
        backtrack(t+1);
        cn--;
    }
    if(cn + n-t > bestn){       //当前结点数 + 剩余结点数 > 最好情况下的结点数
        x[t] = 0;
        backtrack(t+1);
    }
}

int main(){
    Clique c;
    cout << "请输入总顶点数：" << endl;
    cin >> c.n;
    c.cn = c.bestn = 0;
    c.x = new int[c.n+1];
    c.bestx = new int[c.n+1];
    for(int i=0;i<=c.n;i++){
        c.x[i] = 0;
        c.bestx[i] = 0;
    }
    cout << "请依次输入两个顶点之间边的关系（0代表没有边相连，1代表有边相连）：" << endl;
    c.a = new int*[c.n+1];
    for(int i=0;i<=c.n;i++){
        c.a[i] = new int[c.n+1];
    }
    for(int i=1;i<=c.n;i++){          //初始化
        for(int j=1;j<=c.n;j++){
            c.a[i][j] = 0;
        }
    }
    for(int i=1;i<=c.n;i++){
        for(int j=i+1;j<=c.n;j++){
            cout << "请输入第" << i << "个顶点和第" << j << "个顶点之间是否有边相连"<<endl;
            cin >> c.a[i][j];
        }
    }
    for(int i=1;i <= c.n;i++){      //对称化
        for(int j=i+1;j<=c.n;j++){
            c.a[j][i] = c.a[i][j];
        }
    }
    c.backtrack(1);
    cout << "最大可以有" << c.bestn << "个顶点" << endl;
    cout << "最优情况（之一）为：" << endl;
    for(int i=1;i<=c.n;i++){
        cout << c.bestx[i] << " ";
    }
    cout << endl;
    delete[] c.x;
    for(int i=0;i<=c.n;i++){
        delete[] c.a[i];
    }
    delete[] c.a;

    system("pause");
    return 0;
}

/* 测试用例
4
1 1 1 0 1 1
结果为3
1 1 0 1
*/