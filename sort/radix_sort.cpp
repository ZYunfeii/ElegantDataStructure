#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int get(int val, int pos) {
    for (int i = 0; i < pos - 1; ++i) {
        val /= 10;
    }
    return val % 10;
}

void radix_sort(int arr[], int N) {
    int max_val = INT32_MIN;
    for (int i = 0; i < N; ++i) {
        if (max_val < arr[i]) max_val = arr[i];
    }
    // 找到最大数，并得到它的位数
    int bit = 0;
    while (max_val != 0) {
        bit++;
        max_val /= 10;
    }
    vector<queue<int>> bucket(10, queue<int>());
    vector<int> tmp;
    for (int i = 1; i <= bit; ++i) {
        for (int j = 0; j < N; ++j) {
            bucket[get(arr[j], i)].push(arr[j]);
        }
        int idx = 0;
        for (int j = 0; j < bucket.size(); ++j) {
            while (!bucket[j].empty()) {
                arr[idx++] = bucket[j].front();
                bucket[j].pop();
            }
        }
    }
}


int main(int argc, char** argv) {
    int arr[] = {53, 22, 78, 3, 69, 19, 100};
    radix_sort(arr, sizeof arr / sizeof arr[0]);
    for (auto &i : arr) {
        cout << i << endl;
    }
    return 0;
}