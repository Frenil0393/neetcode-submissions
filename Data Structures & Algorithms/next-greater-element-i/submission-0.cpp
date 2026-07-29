class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> st;

        // Preprocess nums2 to find next greater for each element
        for (int num : nums2) {
            while (!st.empty() && st.top() < num) {
                nextGreater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        // Build result for nums1 using the map
        vector<int> result;
        for (int num : nums1) {
            if (nextGreater.count(num)) result.push_back(nextGreater[num]);
            else result.push_back(-1);
        }
        return result;
    }
};
