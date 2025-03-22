class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int i = 0;
        int by = prices[i];
        int profit = 0;
        for(int i =1;i<prices.size();i++){
            if(prices[i]<by){
                by = prices[i];

            }
            else if(prices[i]-by >profit){
                profit = prices[i]-by;
            }
        }
        return profit;
        
    }
};