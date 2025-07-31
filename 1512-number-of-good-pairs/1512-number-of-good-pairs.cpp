class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
       vector<int> count(101, 0); 
        int result = 0;
        for (int num : nums) {
            result =result +  count[num];
            count[num]++;           
        }
        return result;
    }
};