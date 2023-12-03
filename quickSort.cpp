#include <iostream>
#include <ctime>
using namespace std;
int* sortArray(int nums[], int len);
void quickSort(int nums[], int left, int right);
int partition(int nums[], int left, int right);
void swap(int nums[], int x, int y);

int main()
{
    int a[5] = { 5,6,3,1,2 };
    sortArray(a, 5);
    for (int i = 0; i < 5; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
int* sortArray(int nums[],int len) {
    quickSort(nums, 0, len - 1);
    return nums;
}
void quickSort(int nums[], int left, int right) {
    if (left >= right) {
        return;
    }
    int pivotIndex = partition(nums, left, right);
    quickSort(nums, left, pivotIndex - 1);
    quickSort(nums, pivotIndex + 1, right);
}
int partition(int nums[], int left, int right) {
    srand((unsigned)time(NULL));        //产生随机数获得Pivot
    int random = (rand() % (right - left + 1)) + left;
    swap(nums, left, random);

    int pivot = nums[left];
    int j = left;
    for (int i = left + 1; i <= right; i++) {
        if (nums[i] < pivot) {
            j++;
            swap(nums, i, j);
        }
    }
    swap(nums, left, j);
    return j;
}
void swap(int nums[], int x, int y) {
    int temp = nums[x];
    nums[x] = nums[y];
    nums[y] = temp;
}