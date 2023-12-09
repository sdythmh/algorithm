#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include<time.h>
using namespace std;
// Shift+Alt+F
 
// ComputingPairwiseSums_2D
vector<pair<int, int>> CPS2(vector<pair<int, int>> A, vector<pair<int, int>> B, int u);
// ComputingPairwiseSums
vector<int> CPS(vector<int> A, vector<int> B, int u);
// AllSubsetSums_2D
vector<pair<int, int>> AllSubsetSums_2D(vector<int> S, int u);
// AllSubsetSums
vector<int> AllSubsetSums(vector<int> S, int u);
 
int main()
{
    clock_t start, end;
    int n;         // size of S
    vector<int> S; // set S
    int u;         // upper bound u
    cout << "请传入集合中元素数量" << endl;
    cin >> n;
    cout << "请传入元素" << endl;
    while (n > 0)
    {
        int temp;
        cin >> temp;
        S.push_back(temp);
        n--;
    }
    cout << "请传入上界" << endl;
    cin >> u;
    start = clock();
    vector<int> ret1 = AllSubsetSums(S, u);//有序的
    end = clock();
    cout << "the time cost is " << end - start << endl;
    double temp = ret1.back();
    if (temp == u)
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}
 
vector<pair<int, int>> AllSubsetSums_2D(vector<int> S, int u)
{
    int size = S.size();
    if (size == 1) // S={x}
    {
        vector<pair<int, int>> ret{ make_pair(0, 0), make_pair(S[0], 1) };//（0，0）相当于不要，后者是要（1保存余数），S[0]是除法的最终结果
        return ret; // return{(0, 0), (x, 1)}
    }
    vector<int>::const_iterator first1 = S.begin();
    vector<int>::const_iterator last1 = S.begin() + (size / 2);
    vector<int>::const_iterator first2 = S.begin() + (size / 2);
    vector<int>::const_iterator last2 = S.end();
    vector<int> T(first1, last1); // T = an arbitrary subset of S of size n/2
    vector<int> L(first2, last2); // L = another arbitrary subset of S of size n/2
    return CPS2(AllSubsetSums_2D(T, u), AllSubsetSums_2D(L, u), u);
}
 
vector<pair<int, int>> CPS2(vector<pair<int, int>> A, vector<pair<int, int>> B, int u)
{
    vector<pair<int, int>> ret;
    int sizeA = A.size(), sizeB = B.size();
    for (int i = 0; i < sizeA; i++)
    {
        for (int j = 0; j < sizeB; j++)//遍历
        {
            int fir = A[i].first + B[j].first;   // first num of the pair
            int sec = A[i].second + B[j].second; // second num of the pair
            if (fir <= u && sec <= u)
            {
                pair<int, int> p(fir, sec);
                ret.push_back(p);//弄一块
            }
        }
    }
    sort(ret.begin(), ret.end());
    vector<pair<int, int>>::iterator pos = unique(ret.begin(), ret.end());
    ret.erase(pos, ret.end());
    return ret;
}
 
vector<int> AllSubsetSums(vector<int> S, int u)
{
    int n = S.size();
    int b = sqrt(n * log2(n));//定义了一个奇怪的东西，为什么是2？分的均乎？
    vector<int> ret;
    vector<vector<int>> R;
    for (int i = 0; i < b; i++)//分成b个类
    {
        vector<int> Si, Qi, Ri;
        // get Si
        for (int j = 0; j < S.size(); j++)
        {
            if (S[j] % b == i)//分类器
                Si.push_back(S[j]);
        }
 
        // get Qi
        for (int j = 0; j < Si.size(); j++)
        {
            Qi.push_back((Si[j] - i) / b);//k
        }
 
        // get SQi
        vector<pair<int, int>> SQi = AllSubsetSums_2D(Qi, u / b);//k的上界      segment fault
 
        // get Ri
        for (int j = 0; j < SQi.size(); j++)
        {
            Ri.push_back(SQi[j].first * b + i * SQi[j].second);
        }
        sort(Ri.begin(), Ri.end());
        //排列去重
        vector<int>::iterator pos = unique(Ri.begin(), Ri.end());
        Ri.erase(pos, Ri.end());
        R.push_back(Ri);
    }
    ret = R[0];
    for (int i = 1; i < R.size(); i++)
    {
        vector<int> temp = R[i];
        ret = CPS(ret, temp, u);
    }
    return ret;
}
 
vector<int> CPS(vector<int> A, vector<int> B, int u)
{
    vector<int> ret;
    int sizeA = A.size(), sizeB = B.size();
    for (int i = 0; i < sizeA; i++)
    {
        for (int j = 0; j < sizeB; j++)
        {
            int p = A[i] + B[j];
            if (p <= u)
                ret.push_back(p);
        }
    }
    sort(ret.begin(), ret.end());
    vector<int>::iterator pos = unique(ret.begin(), ret.end());
    ret.erase(pos, ret.end());
    return ret;
}