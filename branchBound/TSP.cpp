#include <iostream>
#include <cstring>
#include<queue>
#define INF 1e7
using namespace std;

int m[100][100];        //从第i个城市到第j个城市的路径，从1开始
int bestx[100];
int bestl;
int n;      //城市数目

struct node
{
    int cl;     //当前路径长度
    int id;     //处理的第几个城市,即第几层结点
    int x[100];     //记录当前路径，x[i]表示第i步去的城市id

    //结构体中的构造函数
    node(){}
    node(int cl_, int id_){
        cl = cl_;
        id = id_;
        memset(x,0,sizeof(x));
    }
};
//用于构造最小堆
struct cl_cmp
{
    bool operator()(node n1, node n2){
        return n1.cl > n2.cl;
    }
};

void bfs(){
    //最小堆
    priority_queue<node, vector<node>, cl_cmp> q;
    //创建一个结点，因为1是固定的，从2开始
    node temp(0,2);
    //初始化
    for(int i=1;i<=n;i++){
        temp.x[i] = i;
    }
    q.push(temp);
    node cur;       //构造当前结点
    int t;
    while(!q.empty()){
        cur = q.top();
        q.pop();
        t = cur.id;     //t赋值为第几层结点
        if(t==n){       //到达了倒数第二层结点，后面的路径确定，不必再寻找
            if(m[cur.x[t-1]][cur.x[t]] != INF && m[cur.x[t]][1] != INF){
                if(cur.cl + m[cur.x[t-1]][cur.x[t]] + m[cur.x[t]][1] < bestl){
                    bestl = cur.cl + m[cur.x[t-1]][cur.x[t]] + m[cur.x[t]][1];
                    for(int i=1;i<=n;i++){
                        bestx[i] = cur.x[i];
                    }
                }
            }
            continue;       //如果回不到起点，则继续从堆中扩展
        }
        if(cur.cl > bestl){
            continue;           //如果当前长度已经比最好的长了，没有扩展这个结点的必要了
        }
        //从当前结点开始搜索t-1 -> t,t+1,...
        for(int j=t;j<=n;j++){
            if(m[cur.x[t-1]][cur.x[j]] != INF && cur.cl + m[cur.x[t-1]][cur.x[j]] < bestl){
                //构造为临时结点
                //这里注意为结构体的构造函数
                temp = {cur.cl + m[cur.x[t-1]][cur.x[j]], t+1};        //记录处理第t+1个城市
                //如果找到了下一级结点，这到该结点以上的所有路径和之前的同级路径相同，除了当前这一级不同
                for(int k=1;k<=n;k++){
                    temp.x[k] = cur.x[k];       //赋值时还是全部先赋值，但目前已知的只有t这一级之前的是正确的
                }
                swap(temp.x[t],temp.x[j]);  //如：1->2 交换完后 1->3
                q.push(temp);
            }
        }
    }
}

int main(){
    cout << "请输入城市的数目：" <<endl;
    cin >> n;
    //初始化，所有距离都为INF
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            m[i][j] = INF;
        }
    }
    memset(bestx,0,n);
    bestl = INF;

    for(int i=1;i<=n;i++){
        cout << "请输入第" << i << "个城市的路径信息(不通请输入-1):"<<endl;
        for(int j=1;j<=n;j++){
            int temp;
            cin >> temp;
            if(temp == -1){
                continue;
            }
            m[i][j] = temp;
        }
    }
    bfs();
    cout << "最有值为：" << bestl << endl;
    cout << "最优解为：" << endl;
    for(int i=1;i<=n;i++){
        cout << bestx[i] << " ";
    }
    cout << bestx[1] << endl;   //回到起点

    system("pause");
    return 0;
}

/*
输入:
4
-1 30 6 4
30 -1 5 10
6 5 -1 20
4 10 20 -1

输出
最优值为:25
最优解为:13241
*/

/*
#include <stdio.h>
//使用默认构造函数 
struct student {
	int id;
	char gender;
        student(){} //默认构造函数一般不可见，此处专门写出
}pig;  //能不经初始化就定义变量 

int main(){
	pig = {23,'F'};//使用该语句必须整体赋值，不能单独赋值
	printf("pig ID = %d\npig Gender = %c",pig.id,pig.gender);
	return 0;
}
*/