#include "headers.h"

class Foo {
public:
    Foo() {
        mtx2.lock();
        mtx3.lock();
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        mtx2.unlock();
    }

    void second(function<void()> printSecond) {
        mtx2.lock();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        mtx3.unlock();
    }

    void third(function<void()> printThird) {
        mtx3.lock();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        mtx3.unlock();
    }
private:
    mutex mtx2;
    mutex mtx3;
};