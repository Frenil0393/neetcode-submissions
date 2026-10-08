class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        // Step 1: Pair each name with its height
        vector<pair<int, string>> people;
        for (int i = 0; i < names.size(); i++) {
            people.push_back({heights[i], names[i]});
        }
        
        // Step 2: Sort by height in descending order
        sort(people.begin(), people.end(), [](auto &a, auto &b) {
            return a.first > b.first;
        });
        
        // Step 3: Extract names in sorted order
        vector<string> result;
        for (auto &p : people) {
            result.push_back(p.second);
        }
        
        return result;
    }
};
