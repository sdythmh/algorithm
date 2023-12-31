#include<iostream>
using namespace std;

int maxSubSum(int a[], int left, int right){
    int sum = 0;
    if(left == right){
        sum = a[left] > 0 ? a[left] : 0;        //当区间长度为1的时候，返回这个数和0中的较大值
    }else{
        int mid = (left + right)/2;
        int leftSum = maxSubSum(a,left,mid);
        int rightSum = maxSubSum(a,mid+1,right);
        int s1 = 0, lefts = 0;
        for(int i = mid;i>=left;i--){       //left求出左边每次相加的结果，s1记录其中最大的情况
            lefts += a[i];
            if(lefts > s1){
                s1 = lefts;
            }
        }
        int s2 =0, rights = 0;
        for(int i = mid+1;i<=right;i++){        //right求出右边每次相加的结果，s2记录其中最大的情况
            rights += a[i];
            if(rights > s2){
                s2 = rights;
            }
        }
        sum = s1+s2;
        if(sum < rightSum){
            sum = rightSum;
        }
        if(sum < leftSum){
            sum = leftSum;
        }
    }
    return sum;
}

int main(){
    int a[6] = {-2,11,-4,13,-5,-2};
    cout << "最大子段和为：" << maxSubSum(a,0,5) << endl;

    system("pause");
    return 0;
}