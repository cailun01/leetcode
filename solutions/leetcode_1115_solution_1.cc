class FooBar {
private:
    int n;
    mutex mtx;
    condition_variable cv;
    bool foo_done;
public:
    FooBar(int n) : foo_done(false) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> ulk(mtx);
            cv.wait(ulk, [this](){ return !foo_done; });
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> ulk(mtx);
            cv.wait(ulk, [this](){ return foo_done; });
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            cv.notify_one();
        }
    }
};