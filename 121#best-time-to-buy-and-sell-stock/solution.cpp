class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0, temp_max = 0;
        for (int i = 1; i < prices.size(); i++) {
            temp_max = max(0, temp_max += (prices[i] - prices[i - 1]));
            max_profit = max(temp_max, max_profit);
        }
        
        return max_profit;
    }
};