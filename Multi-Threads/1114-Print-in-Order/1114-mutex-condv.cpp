/*
 * @Date: 2024-03-06 22:47:28
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/Multi-Threads/1114-Print-in-Order/1114-mutex-condv.cpp
 * @Description:
 */
#include <condition_variable>
#include <functional>
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

/**
 * 思路：条件变量，用于线程间通知唤醒或者阻塞，一般搭配互斥锁进行使用
 */
class Foo {
private:
	std::mutex g_mutex;
	std::condition_variable g_cv;
	int g_k = 0;

public:
	Foo() {}

	void first(function<void()> printFirst) {

		// printFirst() outputs "first". Do not change or remove this line.
		printFirst();
		g_k = 1;
		g_cv.notify_all();
	}

	void second(function<void()> printSecond) {
		std::unique_lock<std::mutex> locker(g_mutex);
		// wait 做三件事
		// 1. 将当前线程加入等待唤醒队列
		// 2. unlock mutex
		// 3. 阻塞当前线程
		g_cv.wait(locker, [this]() -> bool { return g_k == 1; });
		// printSecond() outputs "second". Do not change or remove this line.
		printSecond();
		g_k = 2;
		g_cv.notify_one();
	}

	void third(function<void()> printThird) {
		std::unique_lock<std::mutex> locker(g_mutex);
		g_cv.wait(locker, [this]() -> bool { return g_k == 2; });
		// printThird() outputs "third". Do not change or remove this line.
		printThird();
	}
};

int main() { return 0; }