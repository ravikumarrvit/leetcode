#define DEBUG 0

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length() , begin, end;
        if (s.empty())
            return true;
        begin = 0, end = n - 1;
        
        while (begin < end) {
            while ((s[begin] < 48 || s[begin] > 57) && (s[begin] < 65 || s[begin] > 90) && (s[begin] < 97 || s[begin] > 122))
                begin++;
            while ((s[end] < 48 || s[end] > 57) && (s[end] < 65 || s[end] > 90) && (s[end] < 97 || s[end] > 122))
                end--;
            if (begin >= end)
                return true;
            if (DEBUG)
                cout << "begin: " << begin << ", end: " << end << endl;
            if (tolower(s[begin++]) != tolower(s[end--]))
                return false;
        }
        
        return true;
    }
};