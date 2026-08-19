#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastNonZero = 0;
        
        // Move non-zero elements forward
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[lastNonZero++] = nums[i];
            }
        }
        
        // Fill remaining positions with zeros
        for (int i = lastNonZero; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};
