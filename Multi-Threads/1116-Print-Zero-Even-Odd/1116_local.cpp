#include <mutex>
#include <iostream>
#include <thread>
#include <condition_variable>


int main() {
    int n = 10;
    std::mutex g_mtx;
    std::condition_variable g_cv;
    int g_flag = 0; // 0, 1, 2 - zero - odd - even

    std::thread t1([&]() {
        for (int i = 0; i < n; ++i) {
            std::unique_lock<std::mutex> locker(g_mtx);
            g_cv.wait(locker, [&]() { return g_flag == 0; });
            std::cout << "0" << std::endl;
            g_flag = (i % 2 + 1);
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
            g_cv.notify_all();

        }
    });

    // odd
    std::thread t2([&]() {
        for (int i = 1; i <= n; i += 2) {
            std::unique_lock<std::mutex> locker(g_mtx);
            g_cv.wait(locker, [&]() { return g_flag == 1; });
            std::cout << i << std::endl;
            g_flag = 0;
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
            g_cv.notify_all();
        }
    });



    std::thread t3([&]() {
        for (int i = 2; i <= n; i += 2) {
            std::unique_lock<std::mutex> locker(g_mtx);
            g_cv.wait(locker, [&]() { return g_flag == 2; });
            std::cout << i << std::endl;
            g_flag = 0;
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
            g_cv.notify_all();
        }
    });

    t1.join();
    t2.join();
    t3.join();


    return 0;
}