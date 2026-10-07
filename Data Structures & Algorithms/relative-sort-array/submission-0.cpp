class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> order;
        for (int i = 0; i < arr2.size(); i++) {
            order[arr2[i]] = i; // store index of arr2 elements
        }
        
        sort(arr1.begin(), arr1.end(), [&](int a, int b) {
            if (order.count(a) && order.count(b)) {
                return order[a] < order[b]; // both in arr2
            } else if (order.count(a)) {
                return true; // a in arr2, b not
            } else if (order.count(b)) {
                return false; // b in arr2, a not
            } else {
                return a < b; // both not in arr2
            }
        });
        
        return arr1;
    }
};
