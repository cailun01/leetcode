/*
这是两条路的交叉路口。第一条路是A路，车辆可沿1号方向由北向南行驶，也可沿2号方向由南向北行驶。
第二条路是 B 路，车辆可沿3号方向由西向东行驶，也可沿4号方向由东向西行驶。

每条路在路口前都有一个红绿灯。红绿灯可以亮起红灯或绿灯。

绿灯表示两个方向的车辆都可通过路口。
红灯表示两个方向的车辆都不可以通过路口，必须等待绿灯亮起。
两条路上的红绿灯不可以同时为绿灯。这意味着，当 A 路上的绿灯亮起时，B 路上的红灯会亮起；
当 B 路上的绿灯亮起时，A 路上的红灯会亮起.

开始时，A 路上的绿灯亮起，B 路上的红灯亮起。当一条路上的绿灯亮起时，所有车辆都可以从任意两个方向通过路口，
直到另一条路上的绿灯亮起。不同路上的车辆不可以同时通过路口。

给这个路口设计一个没有死锁的红绿灯控制系统。

实现函数 void carArrived(carId, roadId, direction, turnGreen, crossCar) :

carId 为到达车辆的编号。
roadId 为车辆所在道路的编号。
direction 为车辆的行进方向。
turnGreen 是一个函数，调用此函数会使当前道路上的绿灯亮起。
crossCar 是一个函数，调用此函数会允许车辆通过路口。
当你的答案避免了车辆在路口出现死锁，此答案会被认定为正确的。当路口已经亮起绿灯时仍打开绿灯，此答案会被认定为错误的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/traffic-light-controlled-intersection
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
class TrafficLight {
private:
    bool road_one_grean = true;
    mutex mtx;
public:
    TrafficLight() {
        
    }

    void carArrived(
        int carId,                   // ID of the car
        int roadId,                  // ID of the road the car travels on. Can be 1 (road A) or 2 (road B)
        int direction,               // Direction of the car
        function<void()> turnGreen,  // Use turnGreen() to turn light to green on current road
        function<void()> crossCar    // Use crossCar() to make car cross the intersection
    ) {
        if((roadId == 1 && road_one_grean) || (roadId == 2 && !road_one_grean)) {
            crossCar();
        } else {
            mtx.lock();
            road_one_grean = !road_one_grean;
            turnGreen();
            mtx.unlock();
            crossCar();
        }
    }
};

/*
首先过滤一下题目中的废话，提取有用信息如下：

有两条路，Road1和Road2，组成十字路口；
车与车的唯一有用的区别就是它在Road1上还是Road2上；
每辆车代表一个线程；
TrafficLight这个类，就是红绿灯遥控器，很明显每个车都要抢这个遥控器；

*/