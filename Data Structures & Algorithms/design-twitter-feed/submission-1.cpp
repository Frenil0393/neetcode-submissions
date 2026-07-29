class Twitter {
private:
    int timeStamp;
    unordered_map<int, unordered_set<int>> followMap;
    unordered_map<int, vector<pair<int,int>>> tweets;
    
public:
    Twitter() {
        timeStamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> maxHeap;
        
        // Include user's own tweets
        for (auto &t : tweets[userId]) {
            maxHeap.push(t);
        }
        
        // Include followees' tweets
        for (int followee : followMap[userId]) {
            for (auto &t : tweets[followee]) {
                maxHeap.push(t);
            }
        }
        
        vector<int> feed;
        for (int i = 0; i < 10 && !maxHeap.empty(); i++) {
            feed.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followMap[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};
