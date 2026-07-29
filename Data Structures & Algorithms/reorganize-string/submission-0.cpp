class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        
        priority_queue<pair<int,char>> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) pq.push({freq[i], 'a' + i});
        }
        
        string result;
        while (pq.size() > 1) {
            auto [count1, char1] = pq.top(); pq.pop();
            auto [count2, char2] = pq.top(); pq.pop();
            
            result.push_back(char1);
            result.push_back(char2);
            
            if (--count1 > 0) pq.push({count1, char1});
            if (--count2 > 0) pq.push({count2, char2});
        }
        
        if (!pq.empty()) {
            if (pq.top().first > 1) return "";
            result.push_back(pq.top().second);
        }
        
        return result;
    }
};
