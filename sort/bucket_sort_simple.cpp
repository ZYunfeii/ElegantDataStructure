#include<iostream>
using namespace std;
// 这不是真正的桶排序，简化版本
void bucket_sort(int arr[], int N) {
    int tmp[1024] = {0}; // 默认arr中数据小于1024
    for (int i = 0; i < N; ++i) {
        tmp[arr[i]]++;
    }
    int idx = 0;
    for (int i = 0; i < sizeof tmp / sizeof tmp[0]; ++i) {
        if (tmp[i] == 0) continue;
        for (int j = 0; j < tmp[i]; ++j) {
            arr[idx++] = i;
        }
    }
}

int main(int argc, char** argv) {
    int arr[] = {5,5,7,6,1,10};
    bucket_sort(arr, sizeof arr / sizeof arr[0]); 
    for (int i = 0; i < sizeof arr / sizeof arr[0]; ++i) {
        cout << arr[i] << endl;
    }   
    return 0;
}