class FoodRatings {
private:
    unordered_map<string, pair<int, string>> foodInfo;
    unordered_map<string,
        priority_queue<pair<int, string>,
                       vector<pair<int, string>>,
                       greater<pair<int, string>>>> cuisineHeap;

public:
    FoodRatings(vector<string>& foods,
                vector<string>& cuisines,
                vector<int>& ratings) {

        int n = foods.size();

        for (int i = 0; i < n; i++) {
            foodInfo[foods[i]] = {ratings[i], cuisines[i]};

            cuisineHeap[cuisines[i]].push(
                {-ratings[i], foods[i]}
            );
        }
    }

    void changeRating(string food, int newRating) {
        string cuisine = foodInfo[food].second;

        foodInfo[food].first = newRating;

        cuisineHeap[cuisine].push(
            {-newRating, food}
        );
    }

    string highestRated(string cuisine) {
        auto &pq = cuisineHeap[cuisine];

        while (!pq.empty()) {
            auto [negRating, food] = pq.top();

            int currentRating = foodInfo[food].first;

            if (-negRating == currentRating)
                return food;

            pq.pop();
        }

        return "";
    }
};