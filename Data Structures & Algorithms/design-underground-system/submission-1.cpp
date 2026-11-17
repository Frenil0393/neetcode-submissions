class UndergroundSystem {
private:
    unordered_map<int, pair<string, int>> checkins;

    unordered_map<string, pair<long long, int>> routes;

public:
    UndergroundSystem() {}

    void checkIn(int id, string stationName, int t) {
        checkins[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        auto [startStation, startTime] = checkins[id];

        string route = startStation + "#" + stationName;
        int duration = t - startTime;

        routes[route].first += duration; // total time
        routes[route].second += 1;       // trip count

        checkins.erase(id);
    }

    double getAverageTime(string startStation, string endStation) {
        string route = startStation + "#" + endStation;

        auto [totalTime, tripCount] = routes[route];

        return (double) totalTime / tripCount;
    }
};