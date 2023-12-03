#include <bits/stdc++.h>
using namespace std;
class Object{
    public:
    int id;     //物品编号
    int weight;
    int price;
    float d;        //单位重量价值
};

class MaxHeapQNode{
    public:
    MaxHeapQNode* parent;
    int lchild;     //为1则代表左孩子，0代表右孩子
    int upprofit;   //最大利润
    int profit;
    int weight;
    int lev;        //当前所在层数
};
//以下不太了解
struct cmp
{
    bool operator()(MaxHeapQNode *&a, MaxHeapQNode *&b) const
    {
        return a->upprofit < b->upprofit;
    }
};
bool compare(const Object &a, const Object &b)
{
    return a.d >= b.d;
}

int n;
int c;
int cw;
int cp;
int bestp;
Object obj[100];
int bestx[100];     //最佳方案

//计算从第i层开始，后面价值的最大值
int Bound(int i){
    int tmp_cleft = c- cw;
    int tmp_cp = cp;
    while(tmp_cleft >= obj[i].weight && i<=n){
        tmp_cleft -= obj[i].weight;
        tmp_cp += obj[i].price;
        i++;
    }
    if(i<=n){
        tmp_cp += tmp_cleft*obj[i].d;
    }
    return tmp_cp;
}
//其中up是优先级
void addAliveNode(priority_queue<MaxHeapQNode *, vector<MaxHeapQNode *>, cmp> &q, MaxHeapQNode *E, int up, int wt, int curp, int i, int ch){
    MaxHeapQNode *p = new MaxHeapQNode;
    p->parent = E;      //新建立一个结点，父节点为E
    p->lchild = ch;
    p->weight = wt;
    p->upprofit = up;
    p->profit = curp;
    p->lev = i+1;       //下一层扩展的结点
    q.push(p);
}

void MaxKnapsack(){
    priority_queue<MaxHeapQNode *, vector<MaxHeapQNode *>, cmp> q;  //大顶堆
    MaxHeapQNode *E = NULL;
    cw = cp = bestp = 0;
    int i=1;
    int up = Bound(i);
    while(i != n+1){    //i为下一层扩展结点，当下一层扩展结点为n+1时说明已经到了叶子结点
        int wt = cw + obj[i].weight;
        if(wt <= c){        //左子树
            if(bestp < cp + obj[i].price){
                bestp = cp + obj[i].price;
            }
            addAliveNode(q,E,up,cw + obj[i].weight,cp+obj[i].price,i,1);
        }
        //右子树
        up = Bound(i+1);
        if(up >= bestp){
            addAliveNode(q,E,up,cw,cp,i,0);
        }
        //更新E，取出下一个活结点
        E = q.top();
        q.pop();
        cw = E->weight;
        cp = E->profit;
        up = E->upprofit;
        i = E->lev;
    }
    //到达叶子结点
    for(int j=n;j>0;j--){
        bestx[obj[E->lev-1].id] = E->lchild;
        E = E->parent;
    }
}

int main(){
    cout << "请输入货物总数和最大承重："<<endl;
    cin >> n >> c;
    cout << "请依次输入每个货物的价值和重量："<<endl;
    for(int i=1;i<=n;i++){
        cin >> obj[i].price >> obj[i].weight;
        obj[i].id = i;      //这里一开始粗心的写出1了
        obj[i].d = 1.0*obj[i].price / obj[i].weight;    //单位重量的价值
    }
    //排序
    sort(obj+1,obj+n+1,compare);

    MaxKnapsack();

    cout << "最佳装入量为：" << bestp << endl;
    cout << "装入的方案为：" <<endl;
    for(int i=1;i<=n;i++){
        cout << bestx[i] << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}

/*
4 10
40 4
42 7
25 5
12 3

65
1 0 1 0
*/