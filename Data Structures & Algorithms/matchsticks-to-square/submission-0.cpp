class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        long long total = accumulate(matchsticks.begin(), matchsticks.end(), 0LL);
        if (total % 4 != 0) return false;
        int target = total / 4;
        
        sort(matchsticks.rbegin(), matchsticks.rend()); // sort descending for pruning
        vector<int> sides(4, 0);
        
        return backtrack(matchsticks, sides, target, 0);
    }
    
    bool backtrack(vector<int>& matchsticks, vector<int>& sides, int target, int idx) {
        if (idx == matchsticks.size()) {
            return sides[0] == target && sides[1] == target &&
                   sides[2] == target && sides[3] == target;
        }
        
        for (int i = 0; i < 4; i++) {
            if (sides[i] + matchsticks[idx] <= target) {
                sides[i] += matchsticks[idx];
                if (backtrack(matchsticks, sides, target, idx + 1)) return true;
                sides[i] -= matchsticks[idx];
            }
        }
        return false;
    }
};
