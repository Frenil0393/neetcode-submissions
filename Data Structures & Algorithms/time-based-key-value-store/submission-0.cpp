class TimeMap {
public:
    unordered_map<string, vector<pair<int,string>>> mp;
    TimeMap() {}
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    string get(string key, int timestamp) {
        if (!mp.count(key)) return "";
        auto& v = mp[key];
        int l = 0, r = v.size() - 1, ans = -1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (v[m].first <= timestamp) {
                ans = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return ans == -1 ? "" : v[ans].second;
    }
};
