class Solution {
public:

    int climbStairsRecurse(int n, unordered_map<int, int> &no_of_ways) {
        
        if (no_of_ways[n])
            return no_of_ways[n];

        if (n == 0)
            return 1;
            
        if (n < 0)
            return 0;
            
        no_of_ways[n] = climbStairsRecurse(n - 1, no_of_ways) + climbStairsRecurse(n - 2, no_of_ways);
        
        return no_of_ways[n];
    }

    int climbStairs(int n) {
        unordered_map<int, int> no_of_ways;
        if (n <= 1)
            return n;
        return climbStairsRecurse(n, no_of_ways);
    }
};