class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
         unordered_map<int, int> remainder_index;
    remainder_index[0] = -1; 

    int prefix_sum = 0;

    for (int i = 0; i < nums.size(); i++) {
        prefix_sum += nums[i];
        int remainder = prefix_sum % k;

        if (remainder < 0) 
            remainder += k;
        if (remainder_index.find(remainder) != remainder_index.end()) {
            if (i - remainder_index[remainder] >= 2) {
                return true;
            }
        } else {
            remainder_index[remainder] = i;
        }
    }
    
    return false;
}
    
};