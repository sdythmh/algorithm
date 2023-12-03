#include <iostream>
using namespace std;

void mergeTwoSortedArray(int nums[], int left, int right, int temp[], int mid){
    for(int i=left;i<=right;i++){
        temp[i] = nums[i];
    }
    int i = left;
    int j = mid+1;
    for(int k = left;k<=right;k++){
        if(i == mid+1){
            nums[k] = temp[j];      //注意这里是nums[k]
            j++;
        }else if(j == right+1){
            nums[k] = temp[i];
            i++;
        }else if(temp[i] <= temp[j]){
            nums[k] = temp[i];
            i++;
        }else{
            nums[k] = temp[j];
            j++;
        }
    }
}


void mergeSort(int nums[], int left, int right, int temp[]){
    if(left == right){
        return;
    }
    int mid = left + (right-left)/2;
    mergeSort(nums,left,mid,temp);
    mergeSort(nums,mid+1,right,temp);
    if(nums[mid] <= nums[mid+1]){
        return;
    }
    mergeTwoSortedArray(nums,left,right,temp,mid);
}

int main(){
    cout << "请输入数组大小："<<endl;
    int n;
    cin >> n;
    int *a = new int[n];
    cout << "请依次输入数组中的元素：" << endl;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int *temp = new int[n];
    mergeSort(a,0,n-1,temp);
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
    delete[] a;
    delete[] temp;

    system("pause");
    return 0;
}