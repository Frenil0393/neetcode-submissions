class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0;  // position to write compressed result
        int read = 0;   // position to read characters

        while (read < n) {
            char current = chars[read];
            int count = 0;

            // Count consecutive occurrences
            while (read < n && chars[read] == current) {
                read++;
                count++;
            }

            // Write the character
            chars[write++] = current;

            // Write the count if > 1
            if (count > 1) {
                string cnt = to_string(count);
                for (char c : cnt) {
                    chars[write++] = c;
                }
            }
        }
        return write;
    }
};
