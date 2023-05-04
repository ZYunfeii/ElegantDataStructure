#include <bits/stdc++.h>
using namespace std;
// 给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
vector<int> res;

bool canPartition(vector<int>& nums) {
    int s = 0;
    for (auto n : nums) s += n;
    if (s % 2 != 0) return false;
    int n = s / 2;
    vector<int> dp(n + 1, 0);
    vector<vector<int>> path(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = dp.size() - 1; j >= nums[i]; --j) {
            if (dp[j - nums[i]] + nums[i] > dp[j]) {
                path[i][j] = 1;
                dp[j] = dp[j - nums[i]] + nums[i];
            }
        }
    }
    int j = n + 1;
    for (int i = n - 1; i > 0; --i) {
        if (path[i][j]) {
            j -= nums[i];
            res.push_back(nums[i]);
        }
    }
    reverse(res.begin(), res.end());
    for (auto n : res) {
        cout << n << " ";
    } cout << endl;
    return dp.back() == n;
}

int main() {

    vector<int> v = {1, 5, 11, 5};
    canPartition(v);

    return 0;
}