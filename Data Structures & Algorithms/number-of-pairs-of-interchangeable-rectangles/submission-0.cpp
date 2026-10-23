class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<string, long long> freq;
        long long ans = 0;

        for (auto &r : rectangles) {
            int w = r[0];
            int h = r[1];

            int g = gcd(w, h);
            w /= g;
            h /= g;

            string key = to_string(w) + "/" + to_string(h);

            ans += freq[key];
            freq[key]++;
        }

        return ans;
    }
};