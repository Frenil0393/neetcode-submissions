#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long left = -1e10, right = 1e10;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (countLessEqual(nums1, nums2, mid) >= k)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }

private:
    long long floorDiv(long long a, long long b) {
        long long res = a / b;
        long long rem = a % b;
        if (rem != 0 && ((a < 0) ^ (b < 0))) {
            res--;
        }
        return res;
    }

    long long ceilDiv(long long a, long long b) {
        long long res = a / b;
        long long rem = a % b;
        if (rem != 0 && !((a < 0) ^ (b < 0))) {
            res++;
        }
        return res;
    }

    long long countLessEqual(vector<int>& nums1, vector<int>& nums2, long long mid) {
        long long cnt = 0;
        for (long long b : nums2) {
            if (b > 0) {
                long long val = floorDiv(mid, b);
                cnt += upper_bound(nums1.begin(), nums1.end(), val) - nums1.begin();
            } else if (b < 0) {

                long long val = ceilDiv(mid, b);
                cnt += nums1.end() - lower_bound(nums1.begin(), nums1.end(), val);
            } else { // b == 0
                if (mid >= 0) cnt += nums1.size();
            }
        }
        return cnt;
    }
};
