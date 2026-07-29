class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProd = nums[0];
        int curMax = nums[0], curMin = nums[0];
        
        for (int i = 1; i < n; i++) {
            int x = nums[i];
            int tempMax = max({x, curMax * x, curMin * x});
            int tempMin = min({x, curMax * x, curMin * x});
            
            curMax = tempMax;
            curMin = tempMin;
            
            maxProd = max(maxProd, curMax);
        }
        
        return maxProd;
    }
};

