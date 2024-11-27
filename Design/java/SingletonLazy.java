package Design.java;
/**
 * 创建型模式-单例模式（懒汉）
 * SingletonLazy
 * 懒汉式单例模式
 * 优点：节省内存
 * 缺点：线程不安全，调用效率低，使用 volatile 和 synchronized 关键字解决线程安全问题
 */
public class SingletonLazy {
    private static volatile SingletonLazy instance = null;

    private SingletonLazy() {
    }

    public static SingletonLazy getInstance() {
        if (instance == null) {
            synchronized (SingletonLazy.class) {
                if (instance == null) {
                    instance = new SingletonLazy();
                }
            }
        }
        return instance;
    }

    public static void main(String[] args) {
        SingletonLazy instance1 = SingletonLazy.getInstance();
        SingletonLazy instance2 = SingletonLazy.getInstance();
        System.out.println(instance1 == instance2);
    }
}
