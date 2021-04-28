class BoundedBlockingQueue {
private:
    int capacity;
    queue<int> q;
    mutex mtx;
    condition_variable cv;
public:
    BoundedBlockingQueue(int capacity) {
        this->capacity = capacity;
    }
    
    void enqueue(int element) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this](){ return size() < this->capacity; });
        q.push(element);
        cv.notify_all();
    }
    
    int dequeue() {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this](){ return size() > 0; });
        int val = q.front();
        q.pop();
        cv.notify_all();
        return val;
    }
    
    int size() {
        return q.size();
    }
};