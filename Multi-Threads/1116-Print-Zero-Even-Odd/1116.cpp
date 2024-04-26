#include <mutex>
#include <condition_variable>
#include <functional>
using namespace std;

class ZeroEvenOdd {
private:
    int n;
    std::mutex g_mtx;
    std::condition_variable g_cv;
    int g_flag; // 0, 1, 2 - zero - odd - even

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        this->g_flag = 0;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; ++i) {
            std::unique_lock<std::mutex> locker(g_mtx);
            g_cv.wait(locker, [&]() { return g_flag == 0; });
            printNumber(0);
            g_flag = (i % 2 + 1);
            g_cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            std::unique_lock<std::mutex> locker(g_mtx);
            g_cv.wait(locker, [&]() { return g_flag == 2; });
            printNumber(i);
            g_flag = 0;
            g_cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            std::unique_lock<std::mutex> locker(g_mtx);
            g_cv.wait(locker, [&]() { return g_flag == 1; });
            printNumber(i);
            g_flag = 0;
            g_cv.notify_all();
        } 
    }
};