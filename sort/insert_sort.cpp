#include <bits/stdc++.h>
using namespace std;

void msort(vector<int>& arr) {
    for (int j = 1; j < arr.size(); ++j) {
        int t = arr[j];
        int i = j - 1;
        while (i >= 0 && arr[i] >= t) {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = t;
    }
}

int main()
{
    vector<int> arr = {3,1,2,3,5,7,0};
    msort(arr);
    for (int i = 0; i < arr.size(); ++i) {
        fprintf(stdout, "%d\n", arr[i]);
    }
    return 0;
}