import java.util.Comparator;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.HashMap;

public class Solution347 {
    public static void main(String[] args) {

    }
}
//翻译一下C++
class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        int[] res = new int[k];
        Map<Integer, Integer> table = new HashMap<Integer, Integer>();
        for (int num : nums)
            table.put(num, table.getOrDefault(num, 0) + 1);
        //int[] 第一个元素为元素值，第二个元素为元素出现次数
        PriorityQueue<int[]> minHeap = new PriorityQueue<int[]>(new Comparator<int[]>(){
            public int compare(int[] m, int[] n) {
                return m[1] - n[1];
            }
        });

        for (Map.Entry<Integer, Integer> entry : table.entrySet()) {
            int key = entry.getKey(), value = entry.getValue();
            if (minHeap.size() < k) {
                minHeap.add(new int[] {key, value});
                continue;
            }
            if (value > minHeap.peek()[1]) {
                minHeap.poll();
                minHeap.add(new int[] {key, value});
            }
        }
        for (int i = 0; i < k; ++i) 
            res[i] = minHeap.poll()[0];
        return res;
    }
}