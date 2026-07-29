class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> record;
        for (string& op : ops) {
            if (op == "C") {
                record.pop_back();
            } else if (op == "D") {
                record.push_back(record.back() * 2);
            } else if (op == "+") {
                record.push_back(record[record.size() - 1] + record[record.size() - 2]);
            } else {
                record.push_back(stoi(op));
            }
        }
        int sum = 0;
        for (int score : record) sum += score;
        return sum;
    }
};
