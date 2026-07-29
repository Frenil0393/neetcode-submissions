class Solution {
public:
    bool isHappy(int n) {   // <-- must be isHappy
        unordered_set<int> seen;
        
        while (n != 1) {
            if (seen.count(n)) return false;
            seen.insert(n);
            n = sumOfSquares(n);
        }
        return true;
    }
    
private:
    int sumOfSquares(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
};

