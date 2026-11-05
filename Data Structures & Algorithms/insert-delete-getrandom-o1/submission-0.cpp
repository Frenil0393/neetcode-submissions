class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> pos;

public:
    RandomizedSet() {
    }

    bool insert(int val) {
        if (pos.count(val))
            return false;

        nums.push_back(val);
        pos[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (!pos.count(val))
            return false;

        int idx = pos[val];
        int lastVal = nums.back();

        // Move last element to deleted position
        nums[idx] = lastVal;
        pos[lastVal] = idx;

        nums.pop_back();
        pos.erase(val);

        return true;
    }

    int getRandom() {
        return nums[rand() % nums.size()];
    }
};