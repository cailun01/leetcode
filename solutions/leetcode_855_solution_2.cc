class ExamRoom {
private:
    int N_;
    // 将端点p映射到以p为左端点的线段
    unordered_map<int, vector<int>> startMap;
    // 将端点p映射到以p为右端点的线段
    unordered_map<int, vector<int>> endMap;

    function<bool(const vector<int>& a, const vector<int>& b)> Comp = 
        [this](const vector<int>& a, const vector<int>& b) -> bool {
            int distA = distance(a);
            int distB = distance(b);
            if (distA == distB) {
                return b[0] < a[0];
            }
            return distA < distB;
        };
    // 根据线段长度从小到大存放所有线段
    set<vector<int>, function<bool(const vector<int>& , const vector<int>&)>> pq;
public:
    int distance(const vector<int>& intv) {
        int x = intv[0];
        int y = intv[1];
        if (x == -1) return y;
        if (y == N_) return N_ - 1 - x;
        // 中点到端点的长度
        return (y - x) / 2;
    }

    ExamRoom(int N) : N_(N), pq(Comp) {
        addInterval(vector<int>{-1, N_});
    }

    /* 去除一个线段 */
    void removeInterval(const vector<int>& intv) {
        pq.erase(intv);
        startMap.erase(intv[0]);
        endMap.erase(intv[1]);
    }
    /* 增加一个线段 */
    void addInterval(const vector<int>& intv) {
        pq.insert(intv);
        startMap[intv[0]] = intv;
        endMap[intv[1]] = intv;
    }

    int seat() {
        auto longest = *pq.rbegin();
        int x = longest[0];
        int y = longest[1];
        int seat;
        if (x == -1) { // 情况一
            seat = 0;
        } else if (y == N_) { // 情况二
            seat = N_ - 1;
        } else { // 情况三
            seat = (y - x) / 2 + x;
        }
        vector<int> left{x, seat};
        vector<int> right{seat, y};
        removeInterval(longest);
        addInterval(left);
        addInterval(right);
        return seat;
    }
    
    void leave(int p) {
        vector<int> left = endMap[p];
        vector<int> right = startMap[p];
        vector<int> merged{left[0], right[1]};
        removeInterval(left);
        removeInterval(right);
        addInterval(merged);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */