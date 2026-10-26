#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(string s) {
        int n = s.size();
        int totalMasks = 1 << n;
        
        // Store pairs of (mask, length) for valid palindromic subsequences
        vector<pair<int, int>> palindromes;
        
        for (int mask = 1; mask < totalMasks; ++mask) {
            string sub = "";
            for (int i = 0; i < n; ++i) {
                if ((mask >> i) & 1) {
                    sub += s[i];
                }
            }
            
            if (isPalindrome(sub)) {
                palindromes.push_back({mask, static_cast<int>(sub.length())});
            }
        }
        
        int maxProd = 0;
        int m = palindromes.size();
        
        // Compare every pair of palindromes
        for (int i = 0; i < m; ++i) {
            for (int j = i + 1; j < m; ++j) {
                // Check if masks are disjoint
                if ((palindromes[i].first & palindromes[j].first) == 0) {
                    maxProd = max(maxProd, palindromes[i].second * palindromes[j].second);
                }
            }
        }
        
        return maxProd;
    }

private:
    bool isPalindrome(const string& str) {
        int left = 0, right = str.size() - 1;
        while (left < right) {
            if (str[left] != str[right]) return false;
            ++left;
            --right;
        }
        return true;
    }
};
