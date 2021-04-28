class Twitter {
public:
    class Tweet {
    public:
        Tweet(int id, int time) {
            id_ = id;
            time_ = time;
            next = nullptr;
        }
        Tweet* next;
        int time() { return time_; }
        int time() const { return time_; }
        int id() { return id_; }
        int id() const { return id_; }
    private:
        int id_;
        int time_;
    };

    class User {
    public:
        int id;
        Tweet* head;
        set<int> followed;
        User() {}
        User(int userId) {
            id = userId;
            head = nullptr;
            follow(id);
        }

        void follow(int userId) {
            followed.insert(userId);
        }

        void unfollow(int userId) {
            if (id != userId) {
                followed.erase(userId);
            }
        }

        void post(int tweetId) {
            Tweet* twt = new Tweet(tweetId, timestamp);
            timestamp++;
            twt->next = head;
            head = twt;
            if (head == nullptr) {
                cout << "head == nullptr" << endl;
            }
        }
    };
public:
    /** Initialize your data structure here. */
    Twitter() {

    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if(userMap.find(userId) == userMap.end()) {
            User u(userId);
            // userMap[userId] = u;
            userMap.insert({userId, u});
        }
        User& u = userMap[userId];
        u.post(tweetId);
    }
    
    struct Comp {
        bool operator() (Tweet* a, Tweet* b) {
            return a->time() < b->time();
        }
    };

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        if (userMap.find(userId) == userMap.end()) {
            return {};
        }
        vector<int> res;
        set<int> users = userMap[userId].followed;
        priority_queue<Tweet*, vector<Tweet*>, Comp> pq;
        // cout << "users.size(): " << users.size() << endl;
        for (int id : users) {
            Tweet* twt = userMap[id].head;
            if (twt == nullptr) {
                // cout << "twt == nullptr"<< endl;
                continue;
            }
            pq.push(twt);
        }

        while (!pq.empty()) {
            if (res.size() == 10) {
                break;
            }
            Tweet* twt = pq.top();
            pq.pop();
            // cout << "twt->id():" << twt->id() << endl;
            res.push_back(twt->id());
            if (twt->next != nullptr) {
                pq.push(twt->next);
            }
        }
        return res;

    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (userMap.find(followerId) == userMap.end()) {
            User follower = User(followerId);
            // userMap[followerId] = follower;
            userMap.insert({followerId, follower});
        }
        if (userMap.find(followeeId) == userMap.end()) {
            User followee = User(followeeId);
            // userMap[followeeId] = followee;
            userMap.insert({followeeId, followee});
        }
        userMap[followerId].follow(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) {
            return;
        }
        if (userMap.find(followerId) != userMap.end()) {
            userMap[followerId].unfollow(followeeId);
        }
    }
private:
    unordered_map<int, User> userMap;
    static int timestamp;

};

int Twitter::timestamp = 0;

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */