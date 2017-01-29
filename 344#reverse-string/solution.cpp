class Solution {
public:
    string reverseString(string s) {
        int start = 0, end = s.size() - 1;
        
        if (s.empty())
            return s;
        
        while(start < end)
            swap(s[start++], s[end--]);
            
        return s;
    }
};