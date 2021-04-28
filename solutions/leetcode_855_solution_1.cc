/*
在考场里，一排有 N 个座位，分别编号为 0, 1, 2, ..., N-1 。

当学生进入考场后，他必须坐在能够使他与离他最近的人之间的距离达到最大化的座位上。
如果有多个这样的座位，他会坐在编号最小的座位上。(另外，如果考场里没有人，那么学生就坐在 0 号座位上。)

返回 ExamRoom(int N) 类，它有两个公开的函数：其中，函数 ExamRoom.seat() 会返回一个 
int （整型数据），代表学生坐的位置；函数 ExamRoom.leave(int p) 代表坐在座位 p 上的学生现在离开了考场。
每次调用 ExamRoom.leave(p) 时都保证有学生坐在座位 p 上。

 

示例：

输入：["ExamRoom","seat","seat","seat","seat","leave","seat"], [[10],[],[],[],[],[4],[]]
输出：[null,0,9,4,2,null,5]
解释：
ExamRoom(10) -> null
seat() -> 0，没有人在考场里，那么学生坐在 0 号座位上。
seat() -> 9，学生最后坐在 9 号座位上。
seat() -> 4，学生最后坐在 4 号座位上。
seat() -> 2，学生最后坐在 2 号座位上。
leave(4) -> null
seat() -> 5，学生最后坐在 5 号座位上。

*/

/*
我们可以用有序集合（Java 中 TreeSet，C++ 中的 set）存储目前有学生的座位编号。
当我们要调用 leave(p) 函数时，我们只需要把有序集合中的 p 移除即可。
当我们要调用 seat() 函数时，我们遍历这个有序集合，对于相邻的两个座位 i 和 j，
如果选择在这两个座位之间入座，那么最近的距离 d 为 (j - i) / 2，选择的座位为 i + d。
除此之外，我们还需要考虑坐在最左侧 0 和最右侧 N - 1 的情况。

*/
class ExamRoom {
    int n;
    set<int> students;
public:
    ExamRoom(int N) {
        n = N;
    }
    
    int seat() {
        if (students.empty()) {
            students.insert(0);
            return 0;
        }
        int pos = 0, previous = -1, max_distance = 0;
        for (int current : students) {
            int distance = (current - previous) / 2;
            if (distance > max_distance) {
                if (previous == -1) {
                    pos = 0 + distance;
                } else {
                    pos = previous + distance;
                }
                max_distance = distance;
            }
            previous = current;
        }
        // Considering the right-most seat.
        if (n - previous - 1 > max_distance) {
            pos = n - 1;
        }
        students.insert(pos);
        return pos;
    }
    
    void leave(int p) {
        students.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */