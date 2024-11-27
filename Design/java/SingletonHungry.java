package Design.java;
/**
 * 创建型模式-单例模式（饿汉）
 * SingletonHungry
 * 饿汉式单例模式
 * 优点：线程安全，调用效率高
 * 缺点：类加载时就初始化，浪费内存
 */
public class SingletonHungry {
    private static SingletonHungry instance = new SingletonHungry();

    private SingletonHungry() {
    }

    public static SingletonHungry getInstance() {
        return instance;
    }

    public static void main(String[] args) {
        SingletonHungry instance1 = SingletonHungry.getInstance();
        SingletonHungry instance2 = SingletonHungry.getInstance();
        System.out.println(instance1 == instance2);
    }
}
