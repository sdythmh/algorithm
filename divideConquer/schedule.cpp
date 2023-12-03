#include <iostream>
using namespace std;

void myCopy(int **a, int fromx, int fromy, int tox, int toy, int k){
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            a[tox + i][toy+j] = a[fromx + i][fromy+j];
        }
    }
}

void Table(int **a, int r, int l, int k){
    if(k==1){
        return;
    }
    //左上角
    Table(a,r,l,k/2);
    //左下角
    Table(a,r+(k/2),l,(k/2));
    //从左上角拷贝到右下角
    myCopy(a,r,l,r+(k/2),l+(k/2),(k/2));
    //从左下角拷贝到右上角
    myCopy(a,r+(k/2),l,r,l+(k/2),(k/2));
}

int main(){
    cout << "请输入选手的个数（必须是2的幂）：" << endl;
    int n;
    cin >> n;
    int **a = new int*[n];
    for(int i=0;i<n;i++){
        a[i] = new int[n];
        a[i][0] = i+1;
        a[0][i] = i+1;
    }
    Table(a,0,0,n);
    cout << "结果为：" << endl;
    for(int i = 0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    for(int i=0;i<n;i++){
        delete[] a[i];
    }
    delete[] a;

    system("pause");
    return 0;
}