class Solution {
public:

    bool isPalindrome(string &s, int begin, int end) {
        if (begin < 0)
            return false;
        while(begin < end) {
            if (s[begin++] != s[end--])
                return false;
        }
        
        return true;
    }
    
    string longestPalindrome(string s) {
        int i, j, max_length = 0;
        string result;
        
        if (s.length() <= 1)
            return s;
        for (i = 0; i < s.length(); i++) {
            if (isPalindrome(s, i - max_length - 1, i)) {
                result = s.substr(i - max_length - 1, max_length + 2);
                max_length = max_length + 2;
            } else if (isPalindrome(s, i - max_length, i)) {
                result = s.substr(i - max_length, max_length + 1);
                max_length = max_length + 1;
            }
        }
        return result;
    }
};