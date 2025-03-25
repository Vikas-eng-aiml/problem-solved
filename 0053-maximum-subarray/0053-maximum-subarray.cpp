class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int maxi=INT_MIN;
        int prefix=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            prefix+=arr[i];
            maxi=max(prefix,maxi);
            if(prefix<0)
            prefix=0;
        }
        return maxi;
    }
};