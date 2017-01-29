#define DEBUG 0

class Solution {
public:
    
    string get_n_append(string str, int count) {
        string result = "";
        while(count--)
            result += str;
        return result;
    }

    bool repeatedSubstringPattern(string str) {
        int size = str.size();
        
        if (size == 1)
            return false;
        else if (size % 2 == 0 && (size / 2) % 2 == 0)
            return get_n_append(str.substr(0, size/2), 2) == str;
        else {
            for (int i = 0; i < size/2; i++)
                if (get_n_append(str.substr(0, i + 1), (size / (i + 1))) == str)
                    return true;
        }
        
        return false;
    }
};