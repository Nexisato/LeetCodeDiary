/*
 * @Date: 2024-03-06 21:52:30
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/Multi-Threads/1114-Print-in-Order/1114-mutex.cpp
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <thread>
#include <functional>
#include <mutex>
using namespace std;

/**
思路：开三个线程，既然要保证两个依赖顺序，那就加两个锁
 实例初始化的时候上两个锁，只有第一个
*/
class Foo {
private:
    std::mutex mtx_1, mtx_2;
    std::unique_lock<std::mutex> locker1, locker2;
public:
    Foo() : locker1(mtx_1, try_to_lock), locker2(mtx_2, try_to_lock) {
        
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        locker1.unlock();
    }

    void second(function<void()> printSecond) {
        std::lock_guard<std::mutex> guard1(mtx_1);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        locker2.unlock();
    }

    void third(function<void()> printThird) {
        std::lock_guard<std::mutex> guard2(mtx_2);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
int main() {


    return 0;
}