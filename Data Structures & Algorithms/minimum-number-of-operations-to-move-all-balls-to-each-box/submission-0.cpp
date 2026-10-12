class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> answer(n, 0);

        // Left pass
        int countLeft = 0, opsLeft = 0;
        for (int i = 0; i < n; i++) {
            answer[i] += opsLeft;
            if (boxes[i] == '1') countLeft++;
            opsLeft += countLeft;
        }

        // Right pass
        int countRight = 0, opsRight = 0;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] += opsRight;
            if (boxes[i] == '1') countRight++;
            opsRight += countRight;
        }

        return answer;
    }
};
