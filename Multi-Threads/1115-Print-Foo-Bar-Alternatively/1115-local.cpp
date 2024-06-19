#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

int main() {
	int threshold = 10;
	std::mutex g_mtx;
	bool g_foo = true;
	std::condition_variable g_cv;

	std::thread t1([&]() {
		for (int i = 0; i < threshold; ++i) {
			std::unique_lock<std::mutex> locker(g_mtx);
			// wait 函数内部会释放掉锁，直到条件满足，才会重新加锁
			g_cv.wait(locker, [&]() { return g_foo; });
			std::cout << "Foo" << std::endl;
			g_foo = false;
			// 延时
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
			g_cv.notify_one(); // 不用 all
			                   // 是因为只有一个线程在等待，如果有多个线程在等待，就要用
			                   // all
		}
	});

	std::thread t2([&]() {
		for (int i = 0; i < threshold; ++i) {
			std::unique_lock<std::mutex> locker(g_mtx);
			g_cv.wait(locker, [&]() { return !g_foo; });
			std::cout << "Bar" << std::endl;
			g_foo = true;
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
			g_cv.notify_one();
		}
	});

	t1.join();
	t2.join();

	return 0;
}