class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0, maxSum = INT_MIN, minSum = INT_MAX;
    int currentMax = 0, currentMin = 0;

    for (int num : nums) {
        totalSum += num;
        
        currentMax = max(num, currentMax + num);
        maxSum = max(maxSum, currentMax);
        
        currentMin = min(num, currentMin + num);
        minSum = min(minSum, currentMin);
    }
    if (maxSum < 0) return maxSum;
    
    return max(maxSum, totalSum - minSum);

        
    }
};