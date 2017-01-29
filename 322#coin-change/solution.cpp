#define DEBUG 0

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int coins_for_amount[amount + 1];
        
        if (!amount)
            return amount;
            
        if (!coins.size())
            return -1;
        
        fill (coins_for_amount, coins_for_amount + amount + 1, INT_MAX);
        coins_for_amount[0] = 0;
        
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (coin <= i && coins_for_amount[i - coin] != INT_MAX && 
                        coins_for_amount[i - coin] + 1 < coins_for_amount[i]) {
                    coins_for_amount[i] = coins_for_amount[i - coin] + 1;
                }
            }
        }
        
        return (coins_for_amount[amount] == INT_MAX) ? -1 : coins_for_amount[amount];
    }
};