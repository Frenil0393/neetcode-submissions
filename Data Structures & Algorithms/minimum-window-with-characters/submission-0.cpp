class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        unordered_map<char,int> need, window;
        for (char c : t) need[c]++;
        int have = 0, needCount = need.size();
        int resLen = INT_MAX, resStart = 0;
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            window[c]++;
            if (need.count(c) && window[c] == need[c]) have++;
            while (have == needCount) {
                if (right - left + 1 < resLen) {
                    resLen = right - left + 1;
                    resStart = left;
                }
                window[s[left]]--;
                if (need.count(s[left]) && window[s[left]] < need[s[left]]) have--;
                left++;
            }
        }
        return resLen == INT_MAX ? "" : s.substr(resStart, resLen);
    }
};
