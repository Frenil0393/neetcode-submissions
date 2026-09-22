class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0, y = 0;
        unordered_set<string> visited;
        visited.insert("0,0");  // starting point

        for (char dir : path) {
            if (dir == 'N') y++;
            else if (dir == 'S') y--;
            else if (dir == 'E') x++;
            else if (dir == 'W') x--;

            string pos = to_string(x) + "," + to_string(y);
            if (visited.count(pos)) return true;
            visited.insert(pos);
        }
        return false;
    }
};
