class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 1;
        
        int maxLen = 1, currLen = 1;
        int prevCmp = 0; // 0 = equal, 1 = greater, -1 = less
        
        for (int i = 1; i < n; i++) {
            int cmp = (arr[i] > arr[i-1]) ? 1 : (arr[i] < arr[i-1]) ? -1 : 0;
            
            if (cmp == 0) {
                currLen = 1;
            } else if (cmp == -prevCmp) {
                currLen++;
            } else {
                currLen = 2;
            }
            
            maxLen = max(maxLen, currLen);
            prevCmp = cmp;
        }
        
        return maxLen;
    }
};
