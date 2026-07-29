class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) left = mid + 1;
            else right = mid;
        }
        int peak = left;
        int l = 0, r = peak;
        while (l <= r) {
            int mid = (l + r) / 2;
            int val = mountainArr.get(mid);
            if (val == target) return mid;
            if (val < target) l = mid + 1;
            else r = mid - 1;
        }
        l = peak + 1; r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int val = mountainArr.get(mid);
            if (val == target) return mid;
            if (val > target) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }
};
