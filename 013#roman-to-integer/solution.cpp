class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman_to_numeric({ 
                                                     {'I', 1},  {'V', 5},   {'X', 10}, 
                                                     {'L', 50}, {'C', 100}, {'D', 500}, 
                                                     {'M', 1000}
        });
        
        int sum, n = s.length();
        if (n == 0)
            return 0;
        sum = roman_to_numeric[s[n - 1]];
        if (n == 1)
            return sum;
        for (int i = n - 2; i >= 0; i--) {
            if (roman_to_numeric[s[i]] < roman_to_numeric[s[i + 1]])
                sum -= roman_to_numeric[s[i]];
            else
                sum += roman_to_numeric[s[i]];
        }
        
        return sum;
    }
};