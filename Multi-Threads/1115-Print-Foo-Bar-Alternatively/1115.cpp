#include <condition_variable>
#include <functional>
#include <iostream>
#include <mutex>
#include <thread>

class FooBar {
private:
	int n;
	std::mutex g_lock;
	std::condition_variable g_cv;
	bool g_foo;

public:
	FooBar(int n) {
		this->n = n;
		this->g_foo = true;
	}

	void foo(std::function<void()> printFoo) {
		for (int i = 0; i < n; i++) {
			std::unique_lock<std::mutex> locker(g_lock);
			g_cv.wait(locker, [&]() { return g_foo; });
			// printFoo() outputs "foo". Do not change or remove this line.
			printFoo();
			g_foo = false;
			g_cv.notify_one();
		}
	}

	void bar(std::function<void()> printBar) {
		for (int i = 0; i < n; i++) {
			std::unique_lock<std::mutex> locker(g_lock);
			g_cv.wait(locker, [&]() { return !g_foo; });
			// printBar() outputs "bar". Do not change or remove this line.
			printBar();
			g_foo = true;
			g_cv.notify_one();
		}
	}
};