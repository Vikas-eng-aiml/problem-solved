class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int maxi=INT_MIN;
        int prefix=1;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            prefix*=arr[i];
            maxi=max(prefix,maxi);
            if(prefix==0)
            prefix=1;
        }
       int sufix=1;
        for(int i=n-1;i>=0;i--)
        {
            sufix*=arr[i];

          maxi=max(sufix,maxi);
          if(sufix==0)
             sufix=1;
        }
        return maxi;
    }
};