class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n, 0);
        stack<int> st; // stack to keep indices of people to the right

        for (int i = n - 1; i >= 0; i--) {
            int count = 0;
            // Pop shorter people (they are visible but block no one further)
            while (!st.empty() && heights[i] > heights[st.top()]) {
                st.pop();
                count++;
            }
            // If stack not empty, the next taller person is also visible
            if (!st.empty()) count++;
            ans[i] = count;
            st.push(i);
        }
        return ans;
    }
};
