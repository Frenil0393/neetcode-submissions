class Solution {
public:
    int tribonacci(int n) {
        static int dp[38] = {0,1,1};
        static bool ready = false;
        if (!ready) {
            for (int i = 3; i <= 37; i++) {
                dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
            }
            ready = true;
        }
        return dp[n];
    }
};
