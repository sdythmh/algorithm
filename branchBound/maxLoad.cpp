#include <bits/stdc++.h>
using namespace std;
typedef struct QNode        //QNode结点记录了每一种情况（即每一个物品到底装还是不装）
{
    QNode *parent;
    int lchild;
    int weight;
}QNode;
int n;
int c;
int bestw;
int w[100];
int bestx[100];

void EnQueue(queue<QNode *> &q, int wt, int i, QNode *E, QNode *&bestE, int ch)
{
    if(i == n)      //到了叶子结点
    {
        if(wt == bestw)
        {
            bestE = E;
            bestx[n] = ch;      //这里最后一个bestx已经在这里赋值
            return;
        }
    }
    QNode *b;
    b = new QNode;
    b->weight = wt;
    b->lchild = ch;
    b->parent = E;
    q.push(b);
}
int MaxLoading()
{
    queue<QNode *>q;
    q.push(0);          //用0来分层
    int i = 1;
    int Ew = 0, r = 0;
    bestw = 0;
    for(int j = 2; j <= n; ++j)
        r += w[j];
    QNode *E, *bestE; //bestE的作用是：结束while循环后，bestE指向最优解的叶子节点，然后通过bestE->parent找到装入了哪些物品。
    E = new QNode; //E这里作为一个中间量，连接parent和child
    E = 0;         //赋0是因为树的根的值是0，while刚开始的时候其代表root
    while(true)
    {
        int wt = Ew + w[i];
        if(wt <= c)         //左子树
        {
            if(wt > bestw)   //提前更新bestW,注意更新条件
                bestw = wt;
            EnQueue(q, wt, i, E, bestE, 1);
        }
        if(Ew + r >= bestw)   //右儿子剪枝，当前重量（不加入左子树）+剩余 ≥ 最好重量
        {
            EnQueue(q, Ew, i, E, bestE, 0);    
        }
        E = q.front();
        q.pop();
        if(!E)    //如果取得的数是0，代表该处理下一层
        {
            if(q.empty())   //如果队列为空，表示该循环结束了
                break;
            q.push(0);     //如果队列中还有数据，表示循环还没结束。在该层的末尾加一个0标识符
            E = q.front();
            q.pop();
            i++;     //下一层走起
            r -= w[i];   //计算剩余的重量
        }
        Ew = E->weight; //不要忘记更新最新节点的值
    }
    for(int j = n - 1; j > 0; --j)
    {
        bestx[j] = bestE->lchild;
        bestE = bestE->parent;
    }
    return 1;
}

int main()
{
    cout << "请输入物品数量：" << endl;
    cin >> n;
    cout << "请输入最大载重量：" << endl;
    cin >> c;
    cout << "请依次输入物品的重量：" << endl;
    for(int i=1;i<=n;i++){
        cin >> w[i];
    }
    MaxLoading();
    cout << "最优载重量为：" << bestw << endl;
    cout << "装载的方案为："<<endl;
    for(int i=1;i<=n;i++){
        cout << bestx[i] << " ";
    }
    cout << endl;
    
    system("pause");
    return 0;
}
