class Foo {
private:
    int count;
    mutex mtx;
    condition_variable cv2;
    condition_variable cv3;
public:
    Foo() : count(1) {
        
    }

    void first(function<void()> printFirst) {
        unique_lock<mutex> lock(mtx);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        count = 2;
        cv2.notify_one();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(mtx);
        cv2.wait(lock, [this](){ return count == 2; });
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        count = 3;
        cv3.notify_one();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(mtx);
        cv3.wait(lock, [this](){ return count == 3; });
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};