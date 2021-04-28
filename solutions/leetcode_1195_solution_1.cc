class FizzBuzz {
private:
    int n;
    int i;
    mutex mymutex;
public:
    FizzBuzz(int n) {
        this->n = n;
        this->i = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(true) {
            if(i == n + 1)
            break;
            if (i % 3 == 0 && i % 5 != 0) {
                printFizz();
                i++;
            }
            else {
                  this_thread::yield();
            }
        }

    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while(true) {
            if(i==n+1)
            break;
            if(i % 5 == 0 && i % 3 != 0) {
                printBuzz();
                i++;
            } else {
              this_thread::yield();
            }       
        }

    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while(true) {
            if(i==n+1)
            break;
            if(i % 5 == 0 && i % 3 == 0) {
                printFizzBuzz();
                i++;
            } else {
              this_thread::yield();
            }
        }     
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {      
        while(true) {
            if(i==n+1)
            break;
            if (i % 5 != 0 && i % 3 != 0) {
                printNumber(i);
                i++;
            } else {
              this_thread::yield();
            }
        }     
    }
};
