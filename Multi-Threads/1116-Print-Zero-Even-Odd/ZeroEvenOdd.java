import java.util.concurrent.atomic.AtomicInteger;
import java.util.function.IntConsumer;

public class ZeroEvenOdd {
    private int n;
    private AtomicInteger g_counter = new AtomicInteger();

    public ZeroEvenOdd(int _n) {
        this.n = _n;
    }

    public synchronized void zero(IntConsumer printNumber) throws InterruptedException {
        for (int num = 0; num < this.n; ++num) {
            while (g_counter.get() != 0) {
                wait();
            }
            printNumber.accept(0);
            if (num % 2 == 1) {
                g_counter.set(2);
            } else {
                g_counter.set(1);
            }
            notifyAll();
        }
    }

    public synchronized void even(IntConsumer printNumber) throws InterruptedException {
        for (int num = 2; num <= this.n; num += 2) {
            while (g_counter.get() != 2) {
                wait();
            }
            printNumber.accept(num);
            g_counter.set(0);
            notifyAll();
        }
    }

    public synchronized void odd(IntConsumer printNumber) throws InterruptedException {
        for (int num = 1; num <= this.n; num += 2) {
            while (g_counter.get() != 0) {
                wait();
            }
            printNumber.accept(num);
            g_counter.set(0);
            notifyAll();
        }
    }

    public static void main(String[] args) {
        
    };
};