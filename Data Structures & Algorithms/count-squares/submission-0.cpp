class CountSquares {
private:
    // Map: x -> (y -> count)
    unordered_map<int, unordered_map<int, int>> points;

public:
    CountSquares() {}

    void add(vector<int> point) {
        int x = point[0], y = point[1];
        points[x][y]++;  // allow duplicates
    }

    int count(vector<int> point) {
        int x = point[0], y = point[1];
        int total = 0;

        // Iterate over all possible y-coordinates with same x
        for (auto& [colY, cnt] : points[x]) {
            if (colY == y) continue;  // skip same point

            int side = abs(colY - y);  // side length of square

            // Check both directions (left and right)
            for (int dx : {-side, side}) {
                int newX = x + dx;

                if (points.count(newX)) {
                    total += cnt * points[newX][y] * points[newX][colY];
                }
            }
        }
        return total;
    }
};
