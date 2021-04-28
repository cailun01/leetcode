// 限定就餐策略；
// 当5个哲学家都左手持有其左边的叉子 或 当5个哲学家都右手持有其右边的叉子时，会发生死锁。
// 故只需设计一个避免发生上述情况发生的策略即可。
// 规定奇数号的哲学家先拿起他左边的筷子，然后再去拿他右边的筷子；而偶数号的哲学家则先拿起他右边的筷子，
// 然后再去拿他左边的筷子。按此规定，将是1、2号哲学家竞争1号筷子，3、4号哲学家竞争3号筷子。
// 即五个哲学家都竞争奇数号筷子，获得后，再去竞争偶数号筷子，最后总会有一个哲学家能获得两支筷子而进餐。

class DiningPhilosophers {
public:
    DiningPhilosophers() {
    }
    
    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        int l = philosopher;
        int r = (philosopher + 1) % 5;
        if (philosopher % 2 == 0) {
            lock[r].lock(); // 偶数哲学家先拿右侧的叉子
            lock[l].lock();
            pickLeftFork();
            pickRightFork();
        } else {
            lock[l].lock(); // 奇数哲学家先拿左侧的叉子
            lock[r].lock();
            pickLeftFork();
            pickRightFork();
        }
        
        eat();
        putRightFork();
        putLeftFork();
        lock[l].unlock();
        lock[r].unlock();
    }
private:
    std::mutex lock[5];
};

