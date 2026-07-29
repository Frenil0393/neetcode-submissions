class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (rank[px] < rank[py]) parent[px] = py;
        else if (rank[px] > rank[py]) parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
    }

    vector<int> getFactors(int num) {
        vector<int> factors;
        for (int d = 2; d * d <= num; d++) {
            if (num % d == 0) {
                factors.push_back(d);
                while (num % d == 0) num /= d;
            }
        }
        if (num > 1) factors.push_back(num);
        return factors;
    }

    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;

        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;

        unordered_map<int,int> primeToIndex;

        for (int i = 0; i < n; i++) {
            vector<int> factors = getFactors(nums[i]);
            for (int f : factors) {
                if (primeToIndex.count(f)) {
                    unite(i, primeToIndex[f]);
                } else {
                    primeToIndex[f] = i;
                }
            }
        }

        int root = find(0);
        for (int i = 1; i < n; i++) {
            if (find(i) != root) return false;
        }
        return true;
    }
};
