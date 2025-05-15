class Solution {
public:
    bool canPartition(vector<int>& nums) {
    int total = 0;
    for (int num : nums) {
        total += num;
    }
    if (total % 2 != 0) return false;

    int target = total / 2;
    int n = nums.size();
    vector<bool> dp(target + 1, false);
    dp[0] = true; 

    for (int num : nums) {
        for (int j = target; j >= num; --j) {
            dp[j] = dp[j] || dp[j - num];
        }
    }

    return dp[target];
    }
};