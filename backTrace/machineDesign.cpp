#include<iostream>
using namespace std; 
#define maxn 110
 
int w[maxn][maxn];
int c[maxn][maxn];
int bestx[maxn];
int x[maxn];
int n, m, d;
int cw = 0, cc = 0, bestw = 0x3f3f3f3f;
 
void Backtrack(int t) {
    if (t > n) 
	{
        bestw = cw;
        for (int i = 1; i <= n; i++)
            bestx[i] = x[i];
    }
	else 
	{
        for (int i = 1; i <= m; i++) 
		{
            if (cc + c[t][i] <= d && cw + w[t][i] < bestw) 
			{
                x[t] = i;
                cc += c[t][i];
                cw += w[t][i];
                Backtrack(t + 1);
                cc -= c[t][i];
                cw -= w[t][i];
            }
        }
    }
}
 
int main() {
    cout<<"请依次输入部件数，供应商数，限定价格：" << endl;
    cin>> n >> m >> d;
    
    cout<<"请输入各部件的在不同供应商的重量：" << endl;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin>>w[i][j];
            
    cout<<"请输入各部件的在不同供应商的价格：" << endl;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin>>c[i][j];
            
    Backtrack(1);
    cout<<"最小重量为：" << bestw << endl;
    cout<<"每个部件的供应商：" << endl;
    for (int i = 1; i <= n; i++)
    {
    	if(i==1) cout<<bestx[i]<<" "; 
        else cout<<bestx[i]<<" ";
	}
        
    return 0;
}
