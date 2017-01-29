class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> char_map;
        int begin, scan, max_length = INT_MIN;
        
        if (s.empty())
            return 0;
        
        for (begin = 0, scan = 0; scan < s.length(); scan++) {
            if (char_map[s[scan]]) {
                begin = max(begin, char_map[s[scan]]);
            }
            char_map[s[scan]] = scan + 1;
            max_length = max(max_length, scan - begin + 1);
        }
        
        return max_length;
    }
};