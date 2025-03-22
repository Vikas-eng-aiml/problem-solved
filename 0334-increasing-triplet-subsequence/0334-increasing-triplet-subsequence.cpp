class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int J=INT_MAX;
        int K=INT_MAX;
        if(n<3){
            return false;
        }
        for(int i:nums){
            if(i<=J) J=i;
            else if (i<=K) K = i;
            else 
            return true;
           
        }
        return false;
    }
};