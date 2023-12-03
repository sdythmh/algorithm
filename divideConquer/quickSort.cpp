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

void quickSort(int nums[], int left, int right){
    if(left >= right){
        return;
    }
    int pivotIndex = myPartition(nums,left,right);
    quickSort(nums,left,pivotIndex-1);
    quickSort(nums,pivotIndex+1,right);
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
    quickSort(a,0,n-1);
    for(int i = 0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
    delete[] a;

    system("pause");
    return 0;
}