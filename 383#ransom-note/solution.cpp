class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int str[256];
        
        if (ransomNote.empty())
            return true;
        
        fill(str, str + 256, 0);
        
        for (char c : magazine)
            str[c] += 1;
        
        for (char c : ransomNote) {
            if (!str[c]--)
                return false;
        }
        
        return true;
    }
};