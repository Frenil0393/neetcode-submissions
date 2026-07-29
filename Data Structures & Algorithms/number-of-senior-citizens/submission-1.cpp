class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for (string &d : details) {
            // Age is always at index 11 and 12
            int age = stoi(d.substr(11, 2));
            if (age > 60) count++;
        }
        return count;
    }
};
