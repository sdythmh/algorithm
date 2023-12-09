#include <iostream>
#include <cmath>
using namespace std;

class circle{
    public:
    int n;      //圆的个数
    float *r;     //每一个圆的半径，从1开始
    float *x;     //每一个圆的圆心坐标，从1开始
    float min;        //所有情况中最小的长度，即所有结果
    void backTrack(int t);
    float center(int t);
    void compute();
    void mySwap(float *a, float *b);
};

void circle::mySwap(float* a, float* b){
    float temp = *a;
    *a = *b;
    *b = temp;
}

float circle::center(int t){
    float temp = 0;
    float valueX;
    for(int i = 1;i<t;i++){
        valueX = x[i] + 2*sqrt(r[i]*r[t]);      //sqrt((r[i] + r[t])^2 - (r[i]-r[t])^2)
        if(valueX > temp){
            temp = valueX;
        }
    }
    return temp;
}

void circle::compute(){
    float low = 0, high = 0;        //low和high分别代表左边界和右边界
    for(int i=1;i<=n;i++){
        if((x[i] - r[i]) < low){
            low = x[i] - r[i];
        }
        if((x[i]+r[i])>high){
            high = x[i] + r[i];
        }
    }
    if(high - low < min){       //如果区间长度比min还小，则把min赋值为区间长度
        min = high-low;
    }
}

void circle::backTrack(int t){
    if(t > n){
        compute();
    }else{
        for(int j=t;j<=n;j++){
            mySwap(&r[t],&r[j]);
            float centerX = center(t);
            if(centerX + r[t] +r[1] < min){         //centerX + r[t] - (x[1] - r[1])，这种限界较为粗糙
                x[t] = centerX;
                backTrack(t+1);
            }
            mySwap(&r[t],&r[j]);
        }
    }
}

int main(){
    circle c;
    cout << "请输入圆的个数："<<endl;
    cin >> c.n;
    if(c.n == 0){
        system("pause");
        return 0;
    }
    c.r = new float[c.n+1];
    cout << "请依次输入圆的半径："<<endl;
    for(int i=1;i<=c.n;i++){
        cin >> c.r[i];
    }
    c.x = new float[c.n+1];
    for(int i=1;i<=c.n;i++){
        c.x[i] = 0;
    }
    c.min = 1000000;
    c.backTrack(1);
    cout << "最小长度为：" << c.min << endl;

    system("pause");
    return 0;
}

/*测试用例
3
1 1 2
结果：7.65685
4
2 4 1 1
结果：13.8284
*/