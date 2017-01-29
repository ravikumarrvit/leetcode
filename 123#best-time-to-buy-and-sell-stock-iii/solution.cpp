class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buying_price1 = INT_MIN, buying_price2 = INT_MIN;
        int profit1 = 0, profit2 = 0;
        
        for (int price : prices) {
            profit2 = max(profit2, buying_price2 + price);
            buying_price2 = max(buying_price2, profit1 - price);
            profit1 = max(profit1, buying_price1 + price);
            buying_price1 = max(buying_price1, -price);
        }
        
        return profit2;
    }
    
    // DP Solution:
    // [7, 1, 5, 3, 6, 2]
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size(), num = 2;
    //     if (n <= 1) return 0;
    //     vector<vector<int> > dp(num + 1, vector<int>(n, 0));
    //     // dp[3][n]
    //     for (int k = 1; k <= num; k++) {
    //         int temp = dp[k - 1][0] - prices[0]; // -prices[0] ??
    //         for (int i = 1; i < n; i++) {
    //             dp[k][i] = max(dp[k][i - 1], prices[i] + temp);
    //             temp = max(temp, dp[k - 1][i] - prices[i]);
    //         }
    //         // dp[1][i] = {0, 0, 4, 4, 5, 5}
    //         // dp[2][i] = {0, 0, 4, 4, 7, 7}
    //     }
    //     return dp[num][n - 1];
    // }
};