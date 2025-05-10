class Solution {
public:
   long long countSubarrays(vector<int>& nums, int k) {
        
       int n = nums.size();
       int cnt=0;
       long long ans =0;
       int maxElement = *max_element(nums.begin(), nums.end());
       int left =0;
       for(int right =0; right<n; ++right){
        if(nums[right]==maxElement) cnt++;
        while(cnt>=k){
            ans +=n-right;
            if(nums[left]==maxElement) cnt--;
            left++;
        }
       }
       return ans;
       
        

    }
};