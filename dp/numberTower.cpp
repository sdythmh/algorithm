#include <iostream>
using namespace std;

int dtower(int **a, int **s, int n){        //用a来表示数字塔，用s来存储结果
    for(int i = 1; i<=n;i++){
        s[n][i] = a[n][i];
    }
    for(int i=n-1;i>=1;i--){        //从倒数第二行开始
        for(int j=1;j<=i;j++){
            s[i][j] = a[i][j] + ((s[i+1][j] > s[i+1][j+1]) ? s[i+1][j] : s[i+1][j+1]);//+的优先级大于三目运算符qaq
        }
    }
    return s[1][1];
}

int main(){
    int n;
    cout << "请输入数字塔的层数：" << endl;
    cin >> n;
    int **a = new int*[n+1];
    for(int i=0;i<=n;i++){
        a[i] = new int[n+1];
    }
    int **s = new int*[n+1];
    for(int i=0;i<=n;i++){
        s[i] = new int[n+1];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            s[i][j] = 0;
        }
    }
    for(int i=1;i<=n;i++){
        cout << "请输入第" << i << "层的数据：" << endl;
        for(int j=1;j<=i;j++){
            cin >> a[i][j];
        }
    }
    cout << "最小值为：" << dtower(a,s,n) << endl;
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout << s[i][j] << " ";
        }
        cout << endl;
    }*/
    for(int i=0;i<=n;i++){
        delete[] a[i];
    }
    for(int i=0;i<=n;i++){
        delete[] s[i];
    }
    delete[] a;
    delete[] s;

    system("pause");
    return 0;
}