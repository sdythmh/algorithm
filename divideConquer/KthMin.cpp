#include<iostream>
#include<ctime>
#include<algorithm>
using namespace std;

int myPartition(int nums[], int left, int right){
    srand((unsigned)time(NULL));
    int random = (rand() % (right- left + 1)) + left;
    swap(nums[left],nums[random]);

    int le = left+1;
    int ge = right;
    while(1){
        while(le <= ge && nums[le] < nums[left]){
            le++;
        }
        while(le <= ge && nums[ge] > nums[left]){
            ge--;
        }
        if(le > ge){
            break;
        }
        swap(nums[le],nums[ge]);
        le++;
        ge--;
    }
    swap(nums[left],nums[ge]);
    return ge;
}

int mySelect(int nums[], int left, int right, int k){
    if(left == right){
        return nums[left];
    }
    int pivotIndex = myPartition(nums,left,right);
    int j = pivotIndex - left + 1;      //j表示pivotIndex左边长度，如果小于k，则不需要比较前面的元素
    if(k <= j){
        return mySelect(nums,left,pivotIndex,k);        //这里的右边界设置为PivotIndex而不是PivotIndex-1，因为可能PivotIndex位置处的值刚好为所求
    }else{
        return mySelect(nums,pivotIndex+1,right,k-j);     //这里是k-j小，因为前面j个元素不再比较
    }
}

int main(){
    cout << "请输入数组的大小：" << endl;
    int n;
    cin >> n;
    int *a = new int[n];
    cout << "请输入元素：" << endl;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int b;
    cout << "查找第几小元素？" << endl;
    cin >> b;
    cout << "第" << b << "小的元素为：" << mySelect(a,0,n-1,b) << endl;
    delete[] a;

    system("pause");
    return 0;
}

/*
input
6
7 3 1 2 5 4
3
output
3
*/