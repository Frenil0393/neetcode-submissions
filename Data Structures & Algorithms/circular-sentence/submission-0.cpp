class Solution {
public:
    bool isCircularSentence(string sentence) {
        // Split the sentence into words
        vector<string> words;
        stringstream ss(sentence);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }

        int n = words.size();
        // Check each word's last character against the next word's first character
        for (int i = 0; i < n; i++) {
            string curr = words[i];
            string next = words[(i + 1) % n]; // wrap around to first word
            if (curr.back() != next.front()) {
                return false;
            }
        }
        return true;
    }
};
