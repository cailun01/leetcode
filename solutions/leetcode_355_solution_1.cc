/* 355 设计推特
设计一个简化版的推特(Twitter)，可以让用户实现发送推文，关注/取消关注其他用户，
能够看见关注人（包括自己）的最近十条推文。你的设计需要支持以下的几个功能：
    postTweet(userId, tweetId): 创建一条新的推文
    getNewsFeed(userId): 检索最近的十条推文。每个推文都必须是由此用户关注的人或者是用户自己发出的。
                         推文必须按照时间顺序由最近的开始排序。
    follow(followerId, followeeId): 关注一个用户
    unfollow(followerId, followeeId): 取消关注一个用户

示例:
Twitter twitter = new Twitter();
// 用户1发送了一条新推文 (用户id = 1, 推文id = 5).
twitter.postTweet(1, 5);
// 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
twitter.getNewsFeed(1);
// 用户1关注了用户2.
twitter.follow(1, 2);
// 用户2发送了一个新推文 (推文id = 6).
twitter.postTweet(2, 6);
// 用户1的获取推文应当返回一个列表，其中包含两个推文，id分别为 -> [6, 5].
// 推文id6应当在推文id5之前，因为它是在5之后发送的.
twitter.getNewsFeed(1);
// 用户1取消关注了用户2.
twitter.unfollow(1, 2);
// 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
// 因为用户1已经不再关注用户2.
twitter.getNewsFeed(1);
*/

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
    int id_;
    // 用户发表的推文链表头节点
    Tweet* head;
    // 关注用户的集合
    set<int> followed;
    User() {}
    User(int userId) {
      id_ = userId;
      head = nullptr;
      // 关注自己
      follow(id_);
    }

    void follow(int userId) {
      followed.insert(userId);
    }

    void unfollow(int userId) {
      // 不能取关自己
      if (id_ != userId) {
        followed.erase(userId);
      }
    }

    void post(int tweetId) {
      Tweet* twt = new Tweet(tweetId, timestamp);
      timestamp++;
      // 新建的推文插入链表表头
      // 越靠前的推文time值越大
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
  
  /** 发部一条推特 */
  void postTweet(int userId, int tweetId) {
    if(userMap.find(userId) == userMap.end()) {
      User u(userId);
      userMap.insert({userId, u});
    }
    User& u = userMap[userId];
    u.post(tweetId);
  }
  
  /**  
  返回该user关注的人（包括它自己）最近的动态id，最多10条，
  而且这些动态必须按从新到旧的时间线顺序排序
    */
  vector<int> getNewsFeed(int userId) {
    if (userMap.find(userId) == userMap.end()) {
      return {};
    }
    vector<int> res;
    // 关注列表的用户Id
    set<int> users = userMap[userId].followed;
    auto Comp = [](const Tweet* a, const Tweet* b) -> bool {
      return a->time() < b->time();
    };
    // 自动通过time属性从大到小排序，容量为users的大小
    priority_queue<Tweet*, vector<Tweet*>, decltype(Comp)> pq(Comp);
    // 先将所有链表头节点插入优先级队列
    for (int id : users) {
      Tweet* twt = userMap[id].head;
      if (twt == nullptr) {
        continue;
      }
      pq.push(twt);
    }

    while (!pq.empty()) {
      // 最多返回10条
      if (res.size() == 10) {
        break;
      }
      // 弹出time值最大的（即最近发布的）
      Tweet* twt = pq.top();
      pq.pop();
      // 将下一篇Tweet插入进行排序
      res.push_back(twt->id());
      if (twt->next != nullptr) {
        pq.push(twt->next);
      }
    }
    return res;
  }
  
  /** follower关注followee */
  void follow(int followerId, int followeeId) {
    // 如果follower不存在，则创建
    if (userMap.find(followerId) == userMap.end()) {
      User follower = User(followerId);
      userMap.insert({followerId, follower});
    }
    // 如果followee不存在，则创建
    if (userMap.find(followeeId) == userMap.end()) {
      User followee = User(followeeId);
      userMap.insert({followeeId, followee});
    }
    userMap[followerId].follow(followeeId);
  }
  
  /** 返回该user关注的人（包括它自己）最近的动态id， */
  void unfollow(int followerId, int followeeId) {
    if (followerId == followeeId) {
      return;
    }
    if (userMap.find(followerId) != userMap.end()) {
      userMap[followerId].unfollow(followeeId);
    }
  }
private:
  // 映射userID到user
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