class Solution {
public:
    int strStr(string haystack, string needle) {
        int haystack_len = haystack.length(), needle_len = needle.length(), j;
        
        for (int i = 0; i < haystack_len - needle_len + 1; i++) {
            for (j = 0; j < needle_len; j++) {
                if (haystack[i + j] != needle[j])
                    break;
            }
            if (j == needle_len)
                return i;
        }
        return -1;
    }
};