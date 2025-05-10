class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
    int left = 0, maxLength = 0;

    for (int right = 0; right < nums.size(); ++right) {
        freq[nums[right]]++;

        while (freq[nums[right]] > k) {
            freq[nums[left]]--;
            left++;
        }

        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
    }
};