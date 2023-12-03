#include <iostream>
using namespace std;

int quickExp(double a, int n){
    if(a==0){
        return 0;
    }
    if(n<=0){
        return 1;
    }else{
        int x = quickExp(a,n/2);
        if(n%2){
            return x*x*a;
        }else{
            return x*x;
        }
    }
}

double quickExp2(double a, int n){
    int i = n;
    double b =a;
    double s = 1.0;
    while(i>0){
        if(i%2){
            s *= b;
        }
        i /=2;
        b *=b;
    }
    return s;
}

int main(){
    int a,n;
    cout << "请输入底数和指数：" << endl;
    cin >> a >> n;
    cout << "quickExp结果为：" << quickExp(a,n) << endl;
    cout << "quickExp2结果为：" << quickExp2(a,n) << endl;

    system("pause");
    return 0;
}