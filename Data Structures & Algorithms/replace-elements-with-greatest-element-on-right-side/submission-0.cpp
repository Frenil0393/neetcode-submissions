class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int maxRight = -1;  // last element always replaced with -1
        
        for (int i = n - 1; i >= 0; i--) {
            int current = arr[i];
            arr[i] = maxRight;       // replace with greatest element to the right
            maxRight = max(maxRight, current); // update maxRight
        }
        
        return arr;
    }
};
