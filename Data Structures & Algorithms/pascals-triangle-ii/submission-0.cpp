class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);  // Initialize with 1s
        
        // Use the property: C(n, k) = C(n, k-1) * (n-k+1)/k
        for (int k = 1; k < rowIndex; ++k) {
            row[k] = (long long)row[k - 1] * (rowIndex - k + 1) / k;
        }
        
        return row;
    }
};
