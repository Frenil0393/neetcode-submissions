class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<string> palindromes;
        int n = s.size();
        
        for (char c = 'a'; c <= 'z'; c++) {
            int left = s.find(c);
            int right = s.rfind(c);
            
            if (left != string::npos && right != string::npos && left < right) {
                unordered_set<char> mids;
                for (int i = left + 1; i < right; i++) {
                    mids.insert(s[i]);
                }
                for (char m : mids) {
                    string p = "";
                    p += c;
                    p += m;
                    p += c;
                    palindromes.insert(p);
                }
            }
        }
        
        return palindromes.size();
    }
};
